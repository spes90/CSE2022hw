#include "circle.h"

circle::circle(const double &_x, const double &_y, const double &_r) {
	initialize(_x, _y, _r);
}
void circle::initialize(const double &_x, const double &_y, const double &_r) {
	x = _x;
	y = _y;
	r = _r;
}

void circle::draw(float* pixels) {
	drawcircle(pixels, x, y, r);
}

void circle::drawcircle(float* pixels, double x0, double y0, double radius) {
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		drawPixel1(pixels, x0 + x, y0 + y, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 + y, y0 + x, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 - y, y0 + x, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 - x, y0 + y, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 - x, y0 - y, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 - y, y0 - x, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 + y, y0 - x, 0.0f, 0.0f, 0.0f);
		drawPixel1(pixels, x0 + x, y0 - y, 0.0f, 0.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}


