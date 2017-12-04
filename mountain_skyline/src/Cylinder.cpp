/*
 * Cylinder.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Calvin
 */

#include "Cylinder.hpp"

Cylinder::Cylinder() {

	this->translate(1, 0.3, 1.2);

}

void Cylinder::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.35, 0.35, 0.35);
	glColor3f(0.52, 0.34, 0.14); //sets the colour brown

	glBegin(GL_POLYGON);
	GLUquadricObj *quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.1f, 0.1f, 0.5f, 32, 32);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f); // changes colour back to white
	glPopMatrix();
}
