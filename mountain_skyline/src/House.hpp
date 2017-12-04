#ifndef HOUSE_H
#define HOUSE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Pyramid.hpp"
#include "Cube.hpp"
#include "pixmap/RGBpixmap.h"

class House: public Shape {
protected:
	Cube* body;
	Pyramid* roof;
	RGBpixmap pix[2];   // make six pixmaps

public:
	House();
	void draw();
};

#endif
