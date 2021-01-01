#include "Particle.h"
#include <SFML/Window.hpp>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

int main() {
  // Global variables
  const int H = 800;  // height of the screen
  const int W = 600;  // width of the screen
  const int N = 500;  // number of particles - 500 is still good, 1000 not
  const double deltatime = 0.2; // time of one step

  sf::RenderWindow window(sf::VideoMode(H, W), "Particles");  // render a window
  // set framerate - without it program is running as fast as it can
  window.setFramerateLimit(60); 
  // clock - just in case
  // sf::Clock dt;

  srand(time(NULL)); // for random numbers 

  Particle particles[N];  // create array of particles 

  // initializing of pos, vel and radii of all particles 
  for (int i = 0; i < N; i++) {
    particles[i].position.x = rand() % H;
    particles[i].position.y = rand() % W;

    particles[i].velocity.x = rand() % 20;
    particles[i].velocity.y = rand() % 20;

    particles[i].shape.setRadius(5);
  }
  
  // main loop
  while (window.isOpen()) {
    // checking intersections between particles 
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        particles[i].isParticleHit(deltatime, particles[j]);
      }
      // move particles - with checking walls
      particles[i].move(deltatime);
      // draw particles on the screen
      particles[i].draw(window);
    }

    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }
    // clearing window every frame - on black
    window.clear(sf::Color::Black);
  }
}
