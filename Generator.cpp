#include "Generator.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

Generator::Generator(sf::Vector2f size, sf::Vector2f cellSize)
	: m_size{ size }
{
	m_cellCount = sf::Vector2i(size.x / cellSize.x, size.y / cellSize.y);
	
	m_cells.resize(m_cellCount.x * m_cellCount.y);
	for (int x = 0; x < m_cellCount.x; x++)
	{
		for (int y = 0; y < m_cellCount.y; y++)
			m_cells[y * m_cellCount.x + x] = new Cell(cellSize, sf::Vector2f(cellSize.x * x, cellSize.y * y), sf::Color::White, sf::Color::Black);
	}
	
	currentCell = m_cells[0];
	currentCell->isVisited = true;
	m_stack.push({ 0, 0 });
}

Generator::~Generator()
{
	for (int i = 0; i < m_cells.size(); i++)
		if (m_cells[i] != nullptr)
			delete m_cells[i];
}

void Generator::update()
{
	//Update state
}

void Generator::handleEvent(sf::RenderWindow& window)
{
	//handle events
}

void Generator::draw(sf::RenderWindow& window)
{
	for (Cell* cell : m_cells)
		window.draw(*cell);
}