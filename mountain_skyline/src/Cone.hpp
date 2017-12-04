/*
 * Cone.h
 *
 *  Created on: Dec 3, 2017
 *      Author: Calvin
 */

#ifndef CONE_HPP_
#define CONE_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Cone: public Shape {
public:
	Cone();
	void draw();
};

#endif /*CONE_HPP_*/
