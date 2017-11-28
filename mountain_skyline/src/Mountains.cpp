/*
 * Mountains.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: Calvin
 */

#include "Mountains.hpp"

Mountains::Mountains() {
	this->translate(-1, 0.75, -1);

}

void Mountains::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(0.5, 0.5, 0.5);

	//tall mountain in corner
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);
	glVertex3f(0, 3, 0); //tip
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(0, 3, 0); //tip
	glVertex3f(-1, -1, 1);


	glEnd();

	//mountain 2, +2 on z
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1, -1, 2);
	glVertex3f(-1, -1, 3);
	glVertex3f(1, -1, 3);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);
	glVertex3f(0, 1.5, 2); //tip
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, 3);
	glVertex3f(0, 1.5, 2); //tip
	glVertex3f(-1, -1, 3);

	glEnd();

	//mountain 3, +2 on x
	glBegin(GL_LINE_LOOP);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(3, -1, 1);
	glVertex3f(3, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(2, 2, 0); //tip
	glVertex3f(3, -1, -1);
	glVertex3f(3, -1, 1);
	glVertex3f(2, 2, 0); // tip
	glVertex3f(1, -1, 1);


		glEnd();

	glPopMatrix();
}
