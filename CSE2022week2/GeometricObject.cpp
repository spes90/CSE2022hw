//#include "GeometricObject.h"
//#include "Line.h"
//#include "circle.h"
//#include <string>
//
//
//GeometricObject* GeometricObject::getGeometricObject(const std::string&name) {
//	if (name == "Line")
//		return new Line;
//	else if (name == "circle")
//		return new circle;
////GeometricObject 를 static을 해논 상태에서는 int a 있어도 여기서는 표현 못한다.
//return nullptr;
//}
#include "GeometricObject.h"

GeometricObject::GeometricObject(const double &_x, const double &_y, const double &_r) {
	initialize(_x, _y, _r);
}
void GeometricObject::initialize(const double &_x, const double &_y, const double &_r) {
	x = _x;
	y = _y;
	r = _r;
}
void GeometricObject::drawred(float *pixels) {
	int x = r;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		/*drawPixel1(pixels, r + x, 0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r + y, 0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r - y, 0 + x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r - x, 0 + y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r - x, 0 - y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r - y, 0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r + y, 0 - x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, r + x, 0 - y, 1.0f, 0.0f, 0.0f);*/

		drawPixel1(pixels, this->x + x, this->y + y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x + y, this->y + x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x - y, this->y + x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x - x, this->y + y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x - x, this->y - y, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x - y, this->y - x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x + y, this->y - x, 1.0f, 0.0f, 0.0f);
		drawPixel1(pixels, this->x + x, this->y - y, 1.0f, 0.0f, 0.0f);

		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void GeometricObject::drawPixel1(float *pixels, const int& i, const int& j,
	const float& red, const float& green, const float& blue) {
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

GeometricObject::GeometricObject(const double& i0, const double& j0, const double& _r, GLFWwindow* window) {
	initialize(i0, j0, _r ,window);
}
void GeometricObject::initialize(const double& i0, const double& j0, const double& _r, GLFWwindow* window) {
	x = i0;
	y = j0;
	r = _r;
}
bool GeometricObject::isInsideCircle(double& x, double& y, const double i, const double j, const double r) {
	y = height - y;
	const double f = (x - i)*(x - i) + (y - j)*(y - j) - r*r;

	if (f > 0.0) return false;
	else return true;
}
void GeometricObject::changecolor(GLFWwindow* window, float *pixels) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		if (isInsideCircle(xpos, ypos, x, y, r) == true) {
			
			int x = r;
			int y = 0;
			int err = 0;

			while (x >= y)
			{
		
				drawPixel1(pixels, this->x + x, this->y + y, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x + y, this->y + x, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x - y, this->y + x, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x - x, this->y + y, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x - x, this->y - y, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x - y, this->y - x, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x + y, this->y - x, 0.0f, 0.0f, 1.0f);
				drawPixel1(pixels, this->x + x, this->y - y, 0.0f, 0.0f, 1.0f);

				y += 1;
				err += 1 + 2 * y;
				if (2 * (err - x) + 1 > 0)
				{
					x -= 1;
					err += 1 - 2 * x;
				}
			}

		}
				
	
}