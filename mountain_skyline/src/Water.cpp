/*
 * water.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: Calvin
 */

#include "Water.hpp"

Water::Water() {
	this->translate(0, 1, 0);
}

void Water::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(1.5, 1.5, 1.5);

	glBegin(GL_LINE_LOOP);



	glEnd();

	glPopMatrix();
}
