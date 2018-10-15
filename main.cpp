#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Generator.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");
	window.setFramerateLimit(1);

	Generator generator(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(20.f, 20.f));

	while (window.isOpen())
	{
	
		window.clear();

		generator.draw(window);

		window.display();
	}

	return EXIT_SUCCESS;
}