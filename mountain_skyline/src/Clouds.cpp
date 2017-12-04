/*
 * Clouds.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Ethyl
 */
#include "Clouds.hpp"
#include <math.h>

Clouds::Clouds() {
	this->translate(0, 2, 0);
}

void Clouds::draw(){
	glPushMatrix();
//
//	glEnable(GL_POINT_SMOOTH);
//	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
//    glBegin(GL_LINE_LOOP);
//    for (int ii = 0; ii < 100; ii++)   {
//        float theta = 2.0f * 3.1415926f * float(ii) / float(100);//get the current angle
//        float x = 0.7 * cosf(theta);//calculate the x component
//        float y = 0.7 * sinf(theta);//calculate the y component
//        glVertex2f(x + 0, y + 0);//output vertex
//    }
//    glEnd();
//
	this->ctm_multiply();
	glScalef(0.1, 0.1, 0.1);
	glColor3f(1, 1, 1);

	glBegin(GL_POLYGON);
	GLUquadricObj *quadratic = gluNewQuadric();
	gluSphere(quadratic, 2.0f, 8.0f, 8.0f);
	glEnd();

    glPopMatrix();
}

void Clouds::translate(GLfloat tx, GLfloat ty, GLfloat tz) {

}


