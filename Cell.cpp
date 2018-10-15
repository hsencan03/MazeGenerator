#include "Cell.hpp"

Cell::Cell(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color wallColor)
	: m_color{color}, m_wallColor{wallColor}, isVisited{false}
{
	cell.setSize(size);
	cell.setOrigin(cell.getSize().x / 2, cell.getSize().y / 2);
	cell.setPosition(position);
	cell.setFillColor(color);

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: //UP
			walls[i].setSize(sf::Vector2f(size.x, size.y / 8));
			walls[i].setOrigin(walls[i].getSize().x / 2, walls[i].getSize().y / 2);
			walls[i].setPosition(sf::Vector2f(position.x, position.y - (size.y / 2)));
			break;
		case 1: //DOWN
			walls[i].setSize(sf::Vector2f(size.x, size.y / 8));
			walls[i].setOrigin(walls[i].getSize().x / 2, walls[i].getSize().y / 2);
			walls[i].setPosition(sf::Vector2f(position.x, position.y + (size.y / 2)));
			break;
		case 2: //LEFT
			walls[i].setSize(sf::Vector2f(size.x / 8, size.y));
			walls[i].setOrigin(walls[i].getSize().x / 2, walls[i].getSize().y / 2);
			walls[i].setPosition(sf::Vector2f(position.x - (size.x / 2), position.y));
			break;
		case 3: //RIGHT
			walls[i].setSize(sf::Vector2f(size.x / 8, size.y));
			walls[i].setOrigin(walls[i].getSize().x / 2, walls[i].getSize().y / 2);
			walls[i].setPosition(sf::Vector2f(position.x + (size.x / 2), position.y));
			break;
		default:
			break;
		}
		walls[i].setFillColor(m_wallColor);
	}
}

void Cell::removeWall(int num)
{
	if (num < 0 || num >= 4)
		return;

	walls[num].setFillColor(m_color);
}

sf::Vector2f Cell::getSize() const
{
	return cell.getSize();
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(cell);
	for (int i = 0; i < 4; i++)
		target.draw(walls[i]);
}