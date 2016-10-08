#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
const int width = 640*2;
const int height = 480;

float *pixels = new float [width*height*3];
//float *pixels = (float*)malloc(sizeof(float)*width *height *3); //C언어 동적할당

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawSquare(int thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);

class GeometircObject {
public:
	virtual void draw() {
		std::cout << "aaaaaaa" << std::endl;
	}
};

class Line :public GeometircObject {
public:
	int start_x, start_y;
	int end_x, end_y; //데이타제공

public:
	void draw() { //알아서 해라(draw!)
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

class Box :public GeometircObject {
public:	
	int start_x, start_y;
	int end_x, end_y;
public:
	Box() {

	}

	Box(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y) {
		initialize(_start_x, _start_y, _end_x, _end_y);
	} //constructor!! 값이 할당될때 메모리도 넣어준다.

	//~Box() {

	//} //destructor = delete
	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y) {
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw() {
		drawSquare(20, start_x, start_y, end_x, end_y, 0.0f, 0.0f, 1.0f);
	}

};

//Line **my_lines = new Line*[100];
//Box **my_boxes = new Box*[10]; //포인터의 어레이
GeometircObject **my_object = new GeometircObject*[10];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float&blue) {
	pixels[(i + width*j) * 3 + 0] = red;
	pixels[(i + width*j) * 3 + 1] = green;
	pixels[(i + width*j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawSquare(int thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0+i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - thickness; j < j_center + thickness; j++){
		for (int i = i_center - thickness; i < i_center + thickness; i++) {
			drawPixel(i, j, red, green, blue);
		}
	}
}

void draw() {
	int i_center = 100, j_center = 400 ,i2_center =650, j2_center = 450;
	const int thickness = 3, thickness2 = 49;
	//thick line
	for (int j = j_center - thickness; j < j_center + thickness; j++)
	
			for (int i = i_center - thickness; i < i_center + thickness; i++) {
				for (int i = 100; i < 200; i++) {
					drawPixel(i, j, 0.0f, 0.0f, 0.0f);
					
				}
			}

	//triangle
	drawLine(100, 100, 200, 100, 0.0f, 0.0f, 0.0f);
	drawLine(100, 100, 150, 200, 0.0f, 0.0f, 0.0f);
	drawLine(150, 200, 200, 100, 0.0f, 0.0f, 0.0f);
	
	/*for (int i = 0; i < 5; i++)
		my_lines[i]->draw();

	for (int i = 0; i < 5; i++) {
		my_boxes[i]->draw();
	}*/
	for (int i = 0; i < 10; i++) {
		my_object[i]->draw();
	}
}

int main(void)
{
	int count = 0;
	/*initialize lines*/
	for (int i = 0; i < 5; i++) {
		
		Line* tmp = new Line;

		tmp->start_x = 0 + 50 * i;
		tmp->start_y = 0;
		tmp->end_x = 50 + 50 * i;
		tmp->end_y = 50;

		my_object[i] = tmp;
	}
	/*initialize boxes*/
	for (int i = 5; i < 10; i++) {
		my_object[i] = new Box(i, 120, i * 50 + 120, 100);
		//my_boxes[i]->initialize(i, 120, i*50 +120,100);
	}

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// white background
		for (int j = 0; j < height; j++)
			for (int i = 0; i < width; i++) 
			{
				pixels[(i + width*j) * 3 + 0] = 1.0f;
				pixels[(i + width*j) * 3 + 1] = 1.0f;
				pixels[(i + width*j) * 3 + 2] = 1.0f;
			}
		// draw
		draw();

		// draw한것을 출력
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	delete[] pixels;

	return 0;
}

//객체 = object -> class 사용
//class(object를 c++문법에 맞춰서 코드로 옮길 때), object(실체), instance(특정값이 들어간 존재: 메모리를 차지 하는 실체)
//
//#include <iostream>
//
//class Line {
//public:
//	int sart_x, start_y;
//	int end_x, end_y; //데이타제공
//
//	void draw() { //알아서 해라(draw!)
//
//	}
//};
//
//void main() {
//	Line line0, line1;
//	Line my_lines[100];
//
//	line0.draw();
//
//	for (int i = 0; i < 5; i++)
//		my_lines[i].draw();
//}