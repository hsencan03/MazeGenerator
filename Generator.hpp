#pragma once

#include <vector>
#include <stack>
#include <ctime>

#include "Cell.hpp"

namespace sf
{
	class RenderWindow;
}


class Generator {
public:
	Generator(sf::Vector2f size, sf::Vector2f cellSize);
	~Generator();

	void update();

	void handleEvent(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window);

private:
	std::vector<Cell*> GetNeighbors(Cell* cell);

private:
	sf::Vector2f m_size;

	std::vector<Cell*> m_cells;
	sf::Vector2i m_cellCount;

	Cell* currentCell;

	std::stack<sf::Vector2i> m_stack;
	int m_visitedSize;
};