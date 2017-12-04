#include "House.hpp"

House::House()
{


	body = new Cube();
	body->setTextureID(0,0);
	body->setTextureID(1,0);
	body->setTextureID(2,0);
	body->setTextureID(3,0);
	body->setTextureID(4,0);
	body->setTextureID(5,0);

	roof = new Pyramid();
	body->translate(8, 3, 10);
	roof->translate(2.15, 1.3, 2.8);
	//roof->rotate(0, 0, 0, 180);
}

void House::draw()
{
	glPushMatrix();
	this->ctm_multiply();
	glScalef(0.1, 0.1, 0.1);
	body->draw();
	glScalef(3, 3, 3);
	roof->draw();
	glPopMatrix();
}
