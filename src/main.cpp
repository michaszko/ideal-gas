#include "Const.h" // most of the constants defined here
#include "Particle.h"
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <vector>

// Global variables
int H = 800; // screen heigh
int W = 600; // screen width
int N = 100; // number of particles - 500 is still good, 1000 not

int frame_rate = 60;    // frames per second
int radius = 5;         // radius of every ball
int max_speed = 20;     // maximal speed upon the generation of particles
double deltatime = 0.2; // time of one step
int sides_border = 300; // var to divide the volume
std::vector<std::pair<int, double>> x_pos;

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
    // filling vecotr
    for (int i = 0; i < N; i++) {
      // add x_pos to vector
      x_pos.push_back(std::make_pair(i, particles[i].position.x));
    }

    // sort this vecotr by second number in the pair - x position
    // use of lambda function (form Stack Overflow)
    std::sort(x_pos.begin(), x_pos.end(), [](auto &left, auto &right) {
      return left.second < right.second;
    });

    // debugging
    //  std::cout << "myvector contains: \n";
    //  for (int i = 0; i < x_pos.size(); i++) {
    //    std::cout << x_pos[i].first << ", " << x_pos[i].second << "\n";
    //  }
    //  std::cout << "\n";

    // smart looking for interactions
    for (int i = 0; i < x_pos.size() - 1; i++) {
      int j = i + 1;
      // if next particle is close (4 radii) check interesection - it prevents
      // form checking between really distant particles
      while (x_pos[j].second - x_pos[i].second <= 4 * radius) {
        particles[x_pos[i].first].isParticleHit(particles[x_pos[j].first]);
        // dunno why this line is needed - without it I get segmentation
        // violation
        if (j < x_pos.size())
          j++;
        else
          break;
      }
    }

    // clear it every iteration
    x_pos.clear();

    for (int i = 0; i < N; i++) {
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
