/*
 * Cone.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Calvin
 */

#include "Cone.hpp"

Cone::Cone() {
	this->translate(1, 0.3, 1.2);
}

void Cone::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(.30, .80, 0); //sets it green
	glBegin(GL_POLYGON);
	GLUquadricObj *obj = gluNewQuadric();

	gluCylinder(obj, 0.1f, 0.0f, .50f, 32, 32);
	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f); // changes colour back to white
}
