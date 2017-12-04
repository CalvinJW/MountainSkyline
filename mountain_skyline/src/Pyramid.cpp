#include "Pyramid.hpp"

Pyramid::Pyramid() {
	vertex[0][0] = 0;
	vertex[0][1] = 0;
	vertex[0][2] = 0;

	vertex[1][0] = 0;
	vertex[1][1] = 0;
	vertex[1][2] = 1;

	vertex[2][0] = 1;
	vertex[2][1] = 0;
	vertex[2][2] = 1;

	vertex[3][0] = 1;
	vertex[3][1] = 0;
	vertex[3][2] = 0;

	vertex[4][0] = 0.5;
	vertex[4][1] = 0.5;
	vertex[4][2] = 0.5;

	this->setface();
}


void Pyramid::setface() {

	face[0][0] = 0;
	face[0][1] = 1;
	face[0][2] = 4;

	face[1][0] = 1;
	face[1][1] = 2;
	face[1][2] = 4;

	face[2][0] = 2;
	face[2][1] = 3;
	face[2][2] = 4;

	face[3][0] = 0;
	face[3][1] = 3;
	face[3][2] = 4;

}

void Pyramid::drawface(int i) {
	glBegin(GL_LINE_LOOP);
	glVertex3fv(&vertex[face[i][0]][0]);
	glVertex3fv(&vertex[face[i][1]][0]);
	glVertex3fv(&vertex[face[i][2]][0]);
	glEnd();
}


void Pyramid::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 4; i++) {
		drawface(i);
	}

	glPopMatrix();

}

//Pyramid::Pyramid()
//{
//	this->translate(0, 1, 0);
//}
//
//void Pyramid::draw()
//{
//    glPushMatrix();
//    this->ctm_multiply();
//	glScalef(1.5, 1.5, 1.5);
//
//	glBegin(GL_LINE_LOOP);
//
//	//this->rotate(0, 0, 0, 180);
////	glVertex3f(-1, -1, -1);
////	glVertex3f(-1, -1, 1);
////	glVertex3f(1, -1, 1);
////	glVertex3f(1, -1, -1);
////	glVertex3f(-1, -1, -1);
////	glVertex3f(0, 0, 0);
////	glVertex3f(1, -1, -1);
////	glVertex3f(1, -1, 1);
////	glVertex3f(0, 0, 0);
////	glVertex3f(-1, -1, 1);
//
//	glVertex3f(1, -0.5, 1);
//	glVertex3f(1, -0.5, -1);
//	glVertex3f(-1, -0.5, -1);
//	glVertex3f(-1, -0.5, 1);
//	glVertex3f(1, -0.5, 1);
//	glVertex3f(0, -1.5, 0);
//	glVertex3f(-1, -0.5, 1);
//	glVertex3f(-1, -0.5, -1);
//	glVertex3f(0, -1.5, 0);
//	glVertex3f(1, -0.5, -1);
//
//	glEnd();
//
//    glPopMatrix();
//}


