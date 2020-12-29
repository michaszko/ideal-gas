#include "Particle.h"
#include<iostream>

void Particle::move(double deltatime) { 
	this->position = this->position + (this->velocity*deltatime);
}

void Particle::draw() {
	this->shape.setPosition(this->position.x,this->position.y);
}

