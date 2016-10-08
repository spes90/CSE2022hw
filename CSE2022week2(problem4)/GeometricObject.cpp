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

GeometricObject::GeometricObject(const int& _i0, const int& _j0, const int& _i1, const int& _j1) {
	initialize(_i0, _j0, _i1, _j1);
}
void GeometricObject::initialize(const int& _i0, const int& _j0, const int& _i1, const int& _j1) {
	i0 = _i0;
	j0 = _j0;
	i1 = _i1;
	j1 = _j1;
}
void GeometricObject::bluebox(float* pixels) {
	void drawbluebox(float* pixels, const int& i0, const int& j0, const int& i1, const int& j1);
		
	for (int i = i0; i <= i1; i++) {
		drawPixel1(pixels, i, j0, 0.0f, 0.0f, 1.0f);
		drawPixel1(pixels, i, j1, 0.0f, 0.0f, 1.0f);
	}
	for (int j = j0; j <= j1; j++) {
		drawPixel1(pixels, i0, j, 0.0f, 0.0f, 1.0f);
		drawPixel1(pixels, i1, j, 0.0f, 0.0f, 1.0f);
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