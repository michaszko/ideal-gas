#include "Particle.h"
#include <SFML/Window.hpp>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
//#include "Const.h" // most of the constants defined here 

int main() {
  // Global variables

  sf::RenderWindow window(sf::VideoMode(H, W), "Particles");  // render a window
  // set framerate - without it program is running as fast as it can
  window.setFramerateLimit(frame_rate); 
  // clock - just in case
  // sf::Clock dt;

  srand(time(NULL)); // for random numbers 

  Particle particles[N];  // create array of particles 

  // initializing of pos, vel and radii of all particles 
  for (int i = 0; i < N; i++) {
    particles[i].position.x = rand() % H;
    particles[i].position.y = rand() % W;

    particles[i].velocity.x = rand() % seed;
    particles[i].velocity.y = rand() % seed;

    particles[i].shape.setRadius(radius);
  }
  
  // main loop
  while (window.isOpen()) {
    // checking intersections between particles 
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        particles[i].isParticleHit(particles[j]);
      }
      // move particles - with checking walls
      particles[i].move();
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
