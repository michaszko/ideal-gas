#include "Vector.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Particle {
public:

  Particle(){};
  void move(double);
  void draw(); 

  vec position;
  vec velocity;

  sf::CircleShape shape;
};
