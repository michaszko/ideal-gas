#include "Vector.h"

// overloading  basic operators
vec vec::operator+(vec b) {
  vec res;
  res.x = this->x + b.x;
  res.y = this->y + b.y;
  // std::cout<<"sum of vector  "<<this->x<<" "<< this->y << " and vector
  // "<<b.x<<" "<<b.y<<" is equal to "<<res.x<<" "<<res.y<<std::endl;
  return res;
}

vec vec::operator-(vec b) {
  vec res;
  res.x = this->x - b.x;
  res.y = this->y - b.y;
  // std::cout<<"diff of vector  "<<this->x<<" "<< this->y << " and vector
  // "<<b.x<<" "<<b.y<<" is equal to "<<res.x<<" "<<res.y<<std::endl;
  return res;
}

vec vec::operator*(double val) {
  vec res;
  res.x = this->x * val;
  res.y = this->y * val;
  // std::cout<<" vector"<<this->x<<" "<< this->y<<" multiplied by "<<val<<" is
  // equal "<<res.x<<" "<<res.y<<std::endl;
  return res;
}

vec vec::operator/(double val) {
  vec res;
  if (val != 0) {
    res.x = (this->x) / val;
    res.y = (this->y) / val;
    // std::cout<<" vector devided by "<<val<<" is equal "<<res.x<<"
    // "<<res.y<<std::endl;
  } else {
    std::cout
        << "division by 0 is unsupported in couturrent situation. Sorry, amigo."
        << std::endl;
    exit(-1);
  }
  return res;
}

double vec::operator^(vec b) { // scalar product
  return this->x * b.x + this->y * b.y;
}

double vec::norm() { // norm of a vector
  return sqrt((*this) ^ (*this));
}

double vec::norm_sqr() { // square of norm - for skipping square root
  return (*this) ^ (*this);
}

vec vec::normalize() { // normalized vector
  return (*this) / ((*this).norm());
}

std::ostream &operator<<(std::ostream &out,
                         const vec &b) { // for faster debugging
  // Since operator<< is a friend of the Point class, we can access Point's
  // members directly.
  out << "(" << b.x << ", " << b.y << ')'; // actual output done here

  return out; // return std::ostream so we can chain calls to operator<<
}
