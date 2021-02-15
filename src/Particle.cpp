#include "Particle.h"

void Particle::move() {
  // Move the particle in the frame but check first if it is hitting a wall
  // isWallHit();
  this->position = this->position + (this->velocity * deltatime);
}

void Particle::draw(sf::RenderWindow &window) {
  // Draw the particle on the screen - remeber that position is not a position
  // of the center but left top corner of the ball
  this->shape.setPosition(this->position.x, this->position.y);
  window.draw(this->shape);
}

int Particle::isWallHit() {
  // Function to check if particle hit the wall - if so then change velocity.
  // Also additional options can be added like color changing or counting
  bool hit = false;

  // Save the position of the next step of the particle
  vec next_pos = this->position + (this->velocity * deltatime);
  if ((next_pos.x + 2 * this->shape.getRadius() > H) || (next_pos.x < 0)) {
    // we are outside of side walls
    this->velocity.x = -this->velocity.x;
    this->shape.setFillColor(sf::Color(100, 250, 50));
    hit = true;
  }

  if ((next_pos.y + 2 * this->shape.getRadius() > W) || (next_pos.y < 0)) {
    // passing top or bottom walls
    this->velocity.y = -this->velocity.y;
    this->shape.setFillColor(sf::Color(69, 169, 169));
    hit = true;
  }

  if (hit)
    return 1;
  else
    return 0;
}

int Particle::isParticleHit(Particle &p) {
  // Function to check if there is an intersection with another particle
  // and in case of this happening it apply applies a transformation
  // to velocities of both particles
  int counter = 0;
  vec centre1, centre2, d;
  vec rad(1, 1);
  // checking if the particle are on the same side, if not then do nothing
  if (this->Which_side() == p.Which_side()) {
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
          ((this->velocity - p.velocity) ^ d) / d.norm_sqr();
      // changing velocities of both particles
      this->velocity = this->velocity - d * vel_correction_factor;
      p.velocity = p.velocity + d * vel_correction_factor;
      // change position to prevent particle inside the other particle 
      // TODO check if this is correct formula
      this->position = this->position +
                       d.normalize() * (this->shape.getRadius() - d.norm() / 2);
      p.position = p.position -
                       d.normalize() * (p.shape.getRadius() - d.norm() / 2);
      counter++;
    }
  }
  return counter;
}
// TODO: optimise it after climbing
int Particle::Which_side() {
  vec next_pos = this->position + (this->velocity * deltatime);
  if (next_pos.x < sides_border) {
    return 0;
  } else {
    return 1;
  }
}
