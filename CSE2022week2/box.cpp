#include"box.h"

box::box(const int&_i0, const int&_j0, const int&_i1, const int&_j1, const float& red, const float& green, const float& blue) {
	initialize(_i0, _j0, _i1, _j1);
}

void box::initialize(const int&_i0, const int&_j0, const int&_i1, const int&_j1) {
	i0 = _i0;
	j0 = _j0;
	i1 = _i1;
	j1 = _j1;
}

void box::draw(float* pixels) {
	drawBox(pixels, i0, j0, i1, j1, 0.0f, 0.0f, 0.0f);
}

void box::drawBox(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	for (int i = i0; i <= i1; i++) {
		drawPixel1(pixels, i, j0, red, green, blue);
		drawPixel1(pixels, i, j1, red, green, blue);
	}
	for (int j = j0; j <= j1; j++) {
		drawPixel1(pixels, i0, j, red, green, blue);
		drawPixel1(pixels, i1, j, red, green, blue);
	}
}