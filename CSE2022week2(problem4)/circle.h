#pragma once
#include"GeometricObject.h"

class circle : public GeometricObject {
public:
	int x, y, r;
public:
	circle(const double &_x, const double &_y, const double &_r);

	void initialize(const double &_x, const double &_y, const double &_r);

	void circle::draw(float* pixels);

	void drawcircle(float* pixels, double x0, double y0, double radius);
};