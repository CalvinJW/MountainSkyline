/*
 * Mountains.h
 *
 *  Created on: Nov 27, 2017
 *      Author: Calvin
 */

#ifndef MOUNTAINS_HPP_
#define MOUNTAINS_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Mountains: public Shape {
public:
	Mountains();
	void draw();
};

#endif /* MOUNTAINS_HPP_ */
