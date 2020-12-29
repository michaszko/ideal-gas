#include "Particle.h"
#include<iostream>
#include <SFML/Window.hpp>
#include <vector>
int main()
{
	//Global variables 
	const int H = 800;
	const int W = 600;
	//std::vector<int> top = {1,1,1};
	sf::RenderWindow window(sf::VideoMode(H,W), "Gravity");

	Particle lol;

	lol.position.x = 1;
	lol.position.y = 2;

	lol.velocity.x = 29.1;
	lol.velocity.y = 46;
	//lol.velocity.x = 2;
	//lol.velocity.y = 4;

	std::cout << lol.position.x << " " << lol.position.y << "\n";

	lol.shape.setRadius(4);

	while ( window.isOpen() ){
		lol.move(0.01);
		lol.draw();	
		window.draw(lol.shape);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
            // "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}
