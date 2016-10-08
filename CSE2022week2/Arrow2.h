#pragma once
#include"GeometricObject.h"

class Arrow2 : public GeometricObject {
public:
	int i0, j0, i1, j1, i2, j2, i3, j3;
public:
	Arrow2(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const float& red, const float& green, const float& blue);

	void initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3);

	void draw(float* pixels);

	void drawArrow2(float* pixels, const int& _i0, const int& _j0, const int& _i1, const int& _j1, const int& _i2, const int& _j2, const int& _i3, const int& _j3, const float& red, const float& green, const float& blue);

};

