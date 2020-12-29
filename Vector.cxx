struct vector{
	double x,y;
}
class vec {
	vector a;
public:
	vec (){a.z =0; a.y= 0;}
	vec(vector a );
	~vec();

	//overloading  basic operators 
	vec operator+ (vector b, vector c){
		vector res;
		res.x = b.x + c.x;
		res.y = b.y + c.y;
		return res;
	}

	vec operator- (vector b, vector c){
		vector res;
		res.x = b.x - c.x;
		res.y = b.y - c.y;
		return res;
	}

	vec operator* (vector b, double val){
		vector res; 
		res.x = b.x*val;
		res.y = b.y*val;
		return res;
	}

	vec operator/ (vector b, double val){
		vector res;
		if (val != 0) {
			res.x = b.x/val;
			res.y = b.y/val;
			
		}
		else {
			std::cout<<"division by 0 is unsupported in current situation. Sorry, amigo."<<std::endl;
		}
		return res;
	}
	vec operator^ (); // scalar product 

};

vec::vec( ){
	x.a = a;
	y.a = b;
}
