/*
 * water.hpp
 *
 *  Created on: Nov 27, 2017
 *      Author: Calvin
 */

#ifndef WATER_HPP_
#define WATER_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Water: public Shape {
public:
	Water();
	void draw();
};

#endif
