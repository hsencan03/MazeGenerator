#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Generator.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");
	window.setFramerateLimit(30);

	Generator generator(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(25.f, 25.f));


	while (window.isOpen())
	{
		generator.update();
	
		generator.handleEvent(window);

		window.clear();

		generator.draw(window);

		window.display();
	}

	return EXIT_SUCCESS;
}