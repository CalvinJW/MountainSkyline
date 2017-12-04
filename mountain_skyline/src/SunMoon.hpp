/*
 * SunMoon.hpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Calvin
 */

#ifndef SUNMOON_HPP_
#define SUNMOON_HPP_

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include "Sphere.hpp"

class SunMoon: public Shape {
protected:

public:
	Sphere* Sun;
	Sphere* Moon;

	SunMoon();
	void draw();
	void set_color(GLfloat, GLfloat, GLfloat);
	void scale_change(GLfloat x);
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
	void rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void reset();
};

#endif /* SUNMOON_HPP_ */
