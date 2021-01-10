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
  int Which_side(); // checking on which side of the grid is the particle 

  vec position;
  vec velocity;


  sf::CircleShape shape;
};
