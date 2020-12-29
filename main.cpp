#include "Particle.h"
#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Gravity");

	Particle lol;

	lol.position.x = 1;
	lol.position.y = 2;
	
	lol.velocity.x = 2;
	lol.velocity.y = 4;

	std::cout << lol.position.x << " " << lol.position.y << "\n";

	lol.shape.setRadius(1);

	while ( window.isOpen() ){
		lol.move(0.01);
		lol.draw();	
		window.draw(lol.shape);
		window.display();
	}
}
