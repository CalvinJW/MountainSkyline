#include "House.hpp"

House::House()
{
	body = new Cube();
	roof = new Pyramid();
	body->translate(8, 3, 10);
	roof->translate(-8, -4, -10);
	roof->rotate(0, 0, 0, 180);
}

void House::draw()
{
	glPushMatrix();
	this->ctm_multiply();
	glScalef(0.1, 0.1, 0.1);
	body->draw();
	roof->draw();
	glPopMatrix();
}
