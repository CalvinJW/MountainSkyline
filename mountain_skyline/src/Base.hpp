/*
 * Base.hpp
 *
 *  Created on: Dec 1, 2017
 *      Author: Ethyl
 */

#ifndef BASE_HPP_
#define BASE_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Pyramid.hpp"

class Base: public Shape {
protected:
	Pyramid* island;

public:
	Base();
	void draw();
};


#endif /* BASE_HPP_ */
