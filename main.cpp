#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "Cell.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");
	window.setFramerateLimit(1);


	Cell test(sf::Vector2f(50.f, 50.f), sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Color::White, sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Space)
				test.removeWall(1);
		}

		window.clear();

		window.draw(test);

		window.display();
	}

	return EXIT_SUCCESS;
}