/*
 * Clouds.hpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Ethyl
 */

#ifndef CLOUDS_HPP_
#define CLOUDS_HPP_

#include <GL/glut.h>
#include "Shape.hpp"


class Clouds: public Shape {
protected:
	GLfloat vertex[5][3];
	GLint face[4][3];
public:
	Clouds();
	void draw();
	void translate(GLfloat tx, GLfloat ty, GLfloat tz);
};


#endif /* CLOUDS_HPP_ */
