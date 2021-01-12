#include "Const.h" // most of the constants defined here
#include "Particle.h"
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <vector>

// Global variables
int H = 800; // screen heigh
int W = 600; // screen width
int N = 5;   // number of particles - 500 is still good, 1000 not

int frame_rate = 2;     // frames per second
int radius = 5;         // radius of every ball
int max_speed = 20;     // maximal speed upon the generation of particles
double deltatime = 0.2; // time of one step
int sides_border = 300; // var to divide the volume
std::vector<double> x_pos;

int main() {
  sf::RenderWindow window(sf::VideoMode(H, W), "Particles"); // render a window
  // set framerate - without it program is running as fast as it can
  window.setFramerateLimit(frame_rate);
  // clock - just in case
  // sf::Clock dt;

  srand(time(NULL)); // for random numbers

  Particle particles[N]; // create array of particles

  // initializing of pos, vel and radii of all particles
  for (int i = 0; i < N; i++) {
    particles[i].position.x = rand() % H;
    particles[i].position.y = rand() % W;

    particles[i].velocity.x = rand() % max_speed;
    particles[i].velocity.y = rand() % max_speed;

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
      // add x_pos to vector
      x_pos.push_back(particles[i].position.x);
    }
    
    // sort this vecotr 
    std::sort(x_pos.begin(), x_pos.end());
    
    // debugging
    std::cout << "myvector contains:";
    for (std::vector<double>::iterator it = x_pos.begin(); it != x_pos.end(); ++it)
      std::cout << ' ' << *it;

    std::cout << "\n";
    
    // clear it every iteration
    x_pos.clear();

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
