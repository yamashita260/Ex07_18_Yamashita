#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Solid {
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Box :Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(
		double width,
		double height,
		double depth) {
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return 2 * (width * height + height * depth + depth * width);
	}
};

class Cylinder :public Solid {
private:
	double radius;
	double height;
public:
	Cylinder(double radius, double height) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume(){
		return radius * radius * M_PI * height;
		}
	virtual double GetSurface() {
		return (radius + height) * radius * M_PI * 2;
	}
};

class Cone :public Solid {
private:
	double radius;
	double height;
public:
	Cone(double radius, double height) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return radius * radius * M_PI * height / 3.0;
	}
	virtual double GetSurface() {
		return M_PI * radius * (sqrt(radius * radius + height * height) + radius);
	}
};

class Sphere :public Solid {
private:
	double radius;
public:
	Sphere(double radius) {
		this->radius = radius;
	}
	double GetVolume() {
		return radius * radius * radius * M_PI * 4.0 / 3.0;
	}
	virtual double GetSurface() {
		return M_PI * radius * radius * 4.0;
	}
};


int main() {
	Box box{ 3, 5, 2.5 };
	cout << "箱の体積" << box.GetVolume() << endl;
	cout << "箱の表面積" << box.GetSurface() << endl;

	Cylinder cylinder{ 3, 5 };
	cout << "円柱の体積" << cylinder.GetVolume() << endl;
	cout << "円柱の表面積" << cylinder.GetSurface() << endl;
	
	Cone cone{ 3, 5 };
	cout << "円錐の体積" << cone.GetVolume() << endl;
	cout << "円柱の表面積" << cone.GetSurface() << endl;

	Sphere sphere{ 3 };
	cout << "球の体積" << sphere.GetVolume() << endl;
	cout << "球の表面積" << sphere.GetSurface() << endl;
}