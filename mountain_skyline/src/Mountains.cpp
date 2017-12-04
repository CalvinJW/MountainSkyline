/*
 * Mountains.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: Calvin
 */

#include "Mountains.hpp"
#include "pixmap/RGBpixmap.h"

Mountains::Mountains() {
	this->translate(-1, 0.70, -1);


}

void Mountains::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(0.5, 0.5, 0.5);

//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,1);
	//tall mountain in corner
	glBegin(GL_QUADS);
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
//	glBindTexture(GL_TEXTURE_2D,1);
	//mountain 2, +2 on z
	glBegin(GL_LINE_LOOP);
	//glBegin(GL_QUADS);
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
//	glBindTexture(GL_TEXTURE_2D,1);
	//mountain 3, +2 on x
	glBegin(GL_LINE_LOOP);
	//glBegin(GL_QUADS);
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
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
