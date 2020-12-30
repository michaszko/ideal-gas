#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Particle {
public:
  Particle(){};
  void move(double);
  void draw();

  bool isWallHit();

  vec position;
  vec velocity;

  sf::CircleShape shape;
};
