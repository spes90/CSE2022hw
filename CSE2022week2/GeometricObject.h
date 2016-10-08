#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

const int width = 1280;
const int height = 480;

class GeometricObject {
public:
	double x, y, r;

	GeometricObject() {
	}
public:
	
	virtual void draw(float *pixels) {
		std::cout << "hello world" << std::endl;
	}
	
	GeometricObject(const double &_x, const double &_y, const double &_r);

	void initialize(const double &_x, const double &_y, const double &_r);

	void drawred(float *pixels);

	void drawPixel1(float *pixels, const int& i, const int& j, 
		const float& red, const float& green, const float& blue);


	GeometricObject(const double& i0, const double& j0, const double& _r, GLFWwindow* window);
	
	void initialize(const double& i0, const double& j0, const double& _r, GLFWwindow* window);
	
	void changecolor(GLFWwindow* window, float *pixels);

	void drawCicleChangeColor(const double& i0, const double& j0, const double& _r, GLFWwindow* window);

	bool isInsideCircle(double& x, double& y, const double i, const double j, const double r);
};
