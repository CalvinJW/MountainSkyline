#ifndef PYRAMID_H
#define PYRAMID_H

//#include <GL/glut.h>
//#include "Shape.hpp"
//
//class Pyramid: public Shape {
//public:
//	Pyramid();
//	void draw();
//};
//
//#endif

#include <GL/glut.h>
#include "Shape.hpp"

class Pyramid: public Shape {
protected:
	GLfloat vertex[5][3];
	GLint face[4][3];
public:
	Pyramid();
	void draw();
	void setface();
	void drawface(int);
};


#endif
