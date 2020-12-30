#include <cstdlib>

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

  // void SetVal(double val0 , double val1){this->x = val0; this->y = val1;}

  // double GetX(){return this->x;}
  // double GetY(){return this->y;}
  // private:
  double x, y;
};
