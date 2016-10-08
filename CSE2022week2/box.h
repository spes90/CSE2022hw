#pragma once
#include"GeometricObject.h"

class box : public GeometricObject {
public:
	int i0, j0, i1, j1;
public:
	box(const int&_i0, const int&_j0, const int&_i1, const int&_j1, const float& red, const float& green, const float& blue);
	
	void initialize(const int&_i0, const int&_j0, const int&_i1, const int&_j1);

	void draw(float* pixels);

	void drawBox(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
};