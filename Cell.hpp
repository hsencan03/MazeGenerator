#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Cell : public sf::Drawable {
public:
	Cell(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Color wallColor, sf::Vector2i coord);

	void removeWall(int num);

	sf::Vector2f getSize() const;

	sf::Vector2i getCord() const;

	bool isVisited;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Vector2i m_cord;

	sf::RectangleShape cell;
	sf::RectangleShape walls[4];

	sf::Color m_color;
	sf::Color m_wallColor;
};