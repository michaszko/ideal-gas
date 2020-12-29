#include "Particle.h"
#include<iostream>

void Particle::move(double deltatime) { 
	vec next_pos = this->position + (this->velocity*deltatime);
	if ((next_pos.x > 800) || (next_pos.x<0)){
		//we are outside of side walls
		this->velocity.x = -this->velocity.x;
		this->shape.setFillColor(sf::Color(100, 250, 50));
	}
	if ((next_pos.y>600) || (next_pos.y<0)){
		//passing top or bottom walls 
		this->velocity.y = -this->velocity.y;
		this->shape.setFillColor(sf::Color(69, 169, 169));
	}
	this->position = this->position + (this->velocity*deltatime);
}

void Particle::draw() {
	this->shape.setPosition(this->position.x,this->position.y);
}

