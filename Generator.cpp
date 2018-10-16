#include "Generator.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Generator::Generator(sf::Vector2f size, sf::Vector2f cellSize)
	: m_size{ size }, m_visitedSize{ 0 }
{
	std::srand(std::time(nullptr));

	m_cellCount = sf::Vector2i(size.x / cellSize.x, size.y / cellSize.y);
	
	m_cells.resize(m_cellCount.x * m_cellCount.y);
	for (int x = 0; x < m_cellCount.x; x++)
	{
		for (int y = 0; y < m_cellCount.y; y++)
			m_cells[y * m_cellCount.x + x] = new Cell(cellSize, sf::Vector2f(cellSize.x * x, cellSize.y * y), sf::Color::Black, sf::Color::White, sf::Vector2i(x, y));
	}
	
	currentCell = m_cells[0];
	currentCell->isVisited = true;
	m_stack.push({currentCell->getCord()});
}

Generator::~Generator()
{
	for (int i = 0; i < m_cells.size(); i++)
		if (m_cells[i] != nullptr)
			delete m_cells[i];
}

void Generator::update()
{
	if (m_visitedSize >= m_cellCount.x * m_cellCount.y)
		return;

	auto neighbours = GetNeighbors(currentCell);
	
	if (neighbours.size() == 0)
	{
		m_stack.pop();
		currentCell = m_cells[m_stack.top().y * m_cellCount.x + m_stack.top().x];
	}
	else
	{
		//DON'T KNOW WHICH WALL I NEED TO REMOVE

		int num = rand() % neighbours.size();

		switch (num)
		{
		case 0:	//UP
			currentCell->removeWall(0);
			neighbours[num]->removeWall(1);
			break;
		case 1: //DOWN
			currentCell->removeWall(1);
			neighbours[num]->removeWall(0);
			break;
		case 2: //LEFT
			currentCell->removeWall(2);
			neighbours[num]->removeWall(3);
			break;
		case 3: //RIGHT
			currentCell->removeWall(3);
			neighbours[num]->removeWall(2);
			break;
		default:
			break;
		}

		currentCell = neighbours[num];
		currentCell->isVisited = true;
		m_stack.push(currentCell->getCord());

		//!!!
		m_visitedSize++;
	}


}

void Generator::handleEvent(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Generator::draw(sf::RenderWindow& window)
{
	for (Cell* cell : m_cells)
		window.draw(*cell);
}

std::vector<Cell*> Generator::GetNeighbors(Cell* cell)
{
	std::vector<Cell*> temp;
	
	if (cell == nullptr)
		return temp;

	// UP
	if (cell->getCord().y - 1 >= 0 && !m_cells[(cell->getCord().y - 1) * m_cellCount.x + cell->getCord().x]->isVisited)
	{
		temp.push_back(m_cells[(cell->getCord().y - 1) * m_cellCount.x + cell->getCord().x]);
	}
	// DOWN
	if (cell->getCord().y + 1 < m_cellCount.y && !m_cells[(cell->getCord().y + 1) * m_cellCount.x + cell->getCord().x]->isVisited)
	{
		temp.push_back(m_cells[(cell->getCord().y + 1) * m_cellCount.x + cell->getCord().x]);
	}
	// LEFT
	if (cell->getCord().x - 1 >= 0 && !m_cells[cell->getCord().y * m_cellCount.x + (cell->getCord().x - 1)]->isVisited)
	{
		temp.push_back(m_cells[cell->getCord().y * m_cellCount.x + (cell->getCord().x - 1)]);
	}
	// RIGHT
	if (cell->getCord().x + 1 < m_cellCount.x && !m_cells[cell->getCord().y * m_cellCount.x + (cell->getCord().x + 1)]->isVisited)
	{
		temp.push_back(m_cells[cell->getCord().y * m_cellCount.x + (cell->getCord().x + 1)]);
	}

	return temp;
}