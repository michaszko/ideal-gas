#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>

class vec {
public:
  vec() {
    this->x = 0;
    this->y = 0;
  }
  vec(double a, double b) {
    this->x = a;
    this->y = b;
  }
  //~vec() TODO: maybe finally write a destructor
  // overloading  basic operators
  vec operator+(vec b);
  vec operator-(vec b);
  vec operator*(double val);
  vec operator/(double val);
  double operator^(vec b);

  double norm();
  vec normalize();

  friend std::ostream &operator<<(std::ostream &out, const vec &b);
  // variables for 2D vector
  double x, y;
};
