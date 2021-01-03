#include "Particle.h"
//#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
//#include "Const.h"

void Particle::move() {
  // Move the particle in the frame but check first if it is hitting a wall
  isWallHit();
  this->position = this->position + (this->velocity * deltatime);
}

void Particle::draw(sf::RenderWindow &window) {
  // Draw the particle on the screen - remeber that position is not a position
  // of the center but left top corner of the ball
  this->shape.setPosition(this->position.x, this->position.y);
  window.draw(this->shape);
}

void Particle::isWallHit() {
  // Function to check if particle hit the wall - if so then change velocity.
  // Also additional options can be added like color changing or counting 
  
  // Save the position of the next step of the particle
  vec next_pos = this->position + (this->velocity * deltatime);

  if ((next_pos.x + 2 * this->shape.getRadius() > H ) || (next_pos.x < 0)) {
    // we are outside of side walls
    this->velocity.x = -this->velocity.x;
    this->shape.setFillColor(sf::Color(100, 250, 50));
  }

  if ((next_pos.y + 2 * this->shape.getRadius() > W ) || (next_pos.y < 0)) {
    // passing top or bottom walls
    this->velocity.y = -this->velocity.y;
    this->shape.setFillColor(sf::Color(69, 169, 169));
  }
}

void Particle::isParticleHit(Particle &p) {
  // Function to check if there is an intersection with another particle
  // and in case of this happening it apply applies a transformation 
  // to velocities of both particles 
  vec centre1, centre2, d;
  vec rad(1, 1);
  
  // Tranformation of coords - form left top corner to center of a circle
  centre1 = this->position + (this->velocity * deltatime) +
            rad * this->shape.getRadius();
  centre2 = p.position + (p.velocity * deltatime) + rad * p.shape.getRadius();
  
  // Distance vector between two particles 
  d = centre2 - centre1;

  // if balls are close together 
  if (d.norm() <= this->shape.getRadius() + p.shape.getRadius()) { 
    // coeficiant of a interaction - derived from conservation of momentum
    // assuming that both paritcles has the same mass
    double vel_correction_factor =
        ((this->velocity - p.velocity) ^ d) / (d.norm() * d.norm());
    // changing velocities of both particles
    this->velocity = this->velocity - d * vel_correction_factor;
    p.velocity = p.velocity + d * vel_correction_factor;
  }
}
