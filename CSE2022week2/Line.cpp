#include "Line.h"

void Line::draw(float* pixels) {
	drawLine(pixels, start_x, start_y, end_x, end_y, 0.0f, 0.0f, 0.0f);
}

void Line::drawLine(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	if (i0 == i1) {
		for (int j = j0; j < j1; j++)
			drawPixel1(pixels, i0, j, 0.0f, 0.0f, 0.0f);
	}
	else
		for (int i = i0; i <= i1; i++) {
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
			drawPixel1(pixels, i, j, red, green, blue);
		}
}
