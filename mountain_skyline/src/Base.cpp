/*
 * Base.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: Ethyl
 */

#include "Base.hpp"


Base::Base(){
	island = new Pyramid;
	this->translate(-1.5, -0.2, -1.5);
	this->rotate(0, 0, 0, 180);
}

void Base::draw()
{
	glPushMatrix();
	this->ctm_multiply();
	glScalef(3, 3, 3);
	island->draw();
	glPopMatrix();
}



