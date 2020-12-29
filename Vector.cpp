#include <cstdlib>
#include <iostream>
#include <cstdio>

class vec {
public:
	vec (){this->x=0; this->y= 0;}
	vec (double a, double b ){this->x=a; this->y = b; }
	//~vec()

	//overloading  basic operators 
	vec operator+ (vec &b){
		vec res;
		res.x = this->x + b.x;
		res.y = this->y + b.y;
		//std::cout<<"sum of vector  "<<this->x<<" "<< this->y << " and vector "<<b.x<<" "<<b.y<<" is equal to "<<res.x<<" "<<res.y<<std::endl;
		return res;
	}

	vec operator- (vec b){
		vec res;
		res.x = this->x - b.x;
		res.y = this->y - b.y;
		std::cout<<"diff of vector  "<<this->x<<" "<< this->y << " and vector "<<b.x<<" "<<b.y<<" is equal to "<<res.x<<" "<<res.y<<std::endl;
		return res;
	}

	vec operator* (double val){
		vec res; 
		res.x = this->x*val;
		res.y = this->y*val;
		//std::cout<<" vector"<<this->x<<" "<< this->y<<" multiplied by "<<val<<" is equal "<<res.x<<" "<<res.y<<std::endl;
		return res;
	}

	vec operator/ ( double val){
		vec res;
		if (val != 0) {
			res.x = (this->x)/val;
			res.y = (this->y)/val;
		//std::cout<<" vector devided by "<<val<<" is equal "<<res.x<<" "<<res.y<<std::endl;	
		}
		else {
			std::cout<<"division by 0 is unsupported in couturrent situation. Sorry, amigo."<<std::endl;
			exit(-1);
		}
		return res;
	}
	double operator^ (vec &b){ // scalar product 
		double res = 0;
		res = this->x * b.x + this->y * b.y;
		//std::cout<<" scalar product of vector  "<<this->x<<" "<< this->y << " and vector "<<b.x<<" "<<b.y<<" is equal to "<<res<<std::endl;
		return res; 
	} 
private:
	double x,y;
};
// Test main func 
/*
int main ()
{
 vec first(12, 18), second(22,22), third;
 third  = first + second; 
 //third  = second - first;
 third  = first/0;
 third  = second - first;
 third = second*3;
 double scalprod = first^third;
 return 0;
}
*/
