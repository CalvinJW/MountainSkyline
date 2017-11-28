#include "Pyramid.hpp"

Pyramid::Pyramid()
{
	this->translate(0, 1, 0);
}

void Pyramid::draw()
{
    glPushMatrix();
    this->ctm_multiply();
	glScalef(1.5, 1.5, 1.5);

	glBegin(GL_LINE_LOOP);

	//this->rotate(0, 0, 0, 180);
//	glVertex3f(-1, -1, -1);
//	glVertex3f(-1, -1, 1);
//	glVertex3f(1, -1, 1);
//	glVertex3f(1, -1, -1);
//	glVertex3f(-1, -1, -1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(1, -1, -1);
//	glVertex3f(1, -1, 1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(-1, -1, 1);

	glVertex3f(1, -0.5, 1);
	glVertex3f(1, -0.5, -1);
	glVertex3f(-1, -0.5, -1);
	glVertex3f(-1, -0.5, 1);
	glVertex3f(1, -0.5, 1);
	glVertex3f(0, -1.5, 0);
	glVertex3f(-1, -0.5, 1);
	glVertex3f(-1, -0.5, -1);
	glVertex3f(0, -1.5, 0);
	glVertex3f(1, -0.5, -1);

	glEnd();

    glPopMatrix();
}
