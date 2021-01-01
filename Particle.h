#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

class Particle {
public:
  Particle(){};
  void move(double);
  void draw(sf::RenderWindow&);

  void isWallHit(double);
  void isParticleHit(double, Particle &);

  vec position;
  vec velocity;

  sf::CircleShape shape;
};
