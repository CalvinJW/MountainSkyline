/*
 * SunMoon.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Calvin
 */

#include "SunMoon.hpp"

#include "SunMoon.hpp"

SunMoon::SunMoon() {
	Sun = new Sphere();
	Moon = new Sphere();

	Sun->radius = 0.2;
	Sun->translate(0, 2, 0);

	Moon->radius = 0.1;
	Moon->translate(0, 0, 0);

}

void SunMoon::draw() { /*1: wire, 4: bitmap */

	// material setting for the sun
	GLfloat matAmb1[] = { 0.7, 0.53, 0.3, 1.0 }; //ambient
	GLfloat matDif1[] = { 0.76, 0.57, 0.16, 1.0 }; //diffuse
	GLfloat matSpec1[] = { 1.0, 0.15, 0.0, 1.0 }; //specular
	GLfloat matEm1[] = { 0.75, 0.588, 0.0, 1.0 }; //emission
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec1);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm1);
	Sun->draw();

	// material setting for the moon
	GLfloat matAmb3[] = { 0.2, 0.2, 0.25, 1.0 };
	GLfloat matDif3[] = { 0.8, 0.8, 0.95, 1.0 };
	GLfloat matSpec3[] = { 0.3, 0.3, 1.0, 1.0 };
	GLfloat matEm3[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec3);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm3);
	Moon->draw();

}

void SunMoon::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	Sun->translate(tx, ty, tz);
	Moon->translate(tx, ty, tz);
}

void SunMoon::rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Sun->rotate_origin(rx, ry, rz, angle);
	Moon->rotate_origin(rx, ry, rz, angle);
}

void SunMoon::reset() {
	delete Sun;
	delete Moon;
	Sun = new Sphere();
	Moon = new Sphere();

	Sun->radius = 1;
	Sun->translate(0, 2, 0);

	Moon->radius = 0.1;
	Moon->translate(0, 0, 0);
}


