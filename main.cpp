#include "Particle.h"
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

int main() {
  // Global variables
  const int H = 800;
  const int W = 600;

  sf::RenderWindow window(sf::VideoMode(H, W), "Balls");
  window.setFramerateLimit(60);
  // sf::Clock dt;
  

  
  Particle lol;

  lol.position.x = 1;
  lol.position.y = 2;

  lol.velocity.x = 29.1;
  lol.velocity.y = 46;
  // lol.velocity.x = 2;
  // lol.velocity.y = 4;

  
  lol.shape.setRadius(4);

  while (window.isOpen()) {
    lol.move(0.1);
    lol.draw();
    window.draw(lol.shape);
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
  }
}
