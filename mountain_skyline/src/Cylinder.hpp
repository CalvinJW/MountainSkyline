/*
 * Cylinder.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Calvin
 */

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Cylinder: public Shape {
public:
	Cylinder();
	void draw();
};

#endif /* MOUNTAINS_HPP_ */
