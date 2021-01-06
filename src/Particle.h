#include "Const.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

class Particle {
public:
  Particle(){};
  void move();
  void draw(sf::RenderWindow &);

  void isWallHit();
  void isParticleHit(Particle &);

  vec position;
  vec velocity;

  sf::CircleShape shape;
};
