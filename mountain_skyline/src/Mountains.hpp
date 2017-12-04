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
#include "Pyramid.hpp"

class Mountains: public Shape {
protected:
	Pyramid* mountain1;
	Pyramid* mountain2;
	Pyramid* mountain3;

public:
	Mountains();
	void draw();
};

#endif /* MOUNTAINS_HPP_ */
