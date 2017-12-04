/*
 * Mountainskyline.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Calvin Wang & Ethyl Chan
 *
 */


#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "House.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Clouds.hpp"
#include "pixmap/RGBpixmap.h"
#include "time.h"
#include "SunMoon.hpp"

#define TIME 0.0015;

RGBpixmap pix[6];   // make six pixmaps


GLint winWidth = 800, winHeight = 800;

GLfloat red = 1.0, green = 1.0, blue = 1.0,theta;
GLint moving = 0, xBegin = 0, coordinate = 1, type = 4, selected = 1;
GLfloat globalTime = 13;
GLfloat r = 0.19, g = 0.6, b = 0.8;
int colorCount;
//6078

//Declare a world containing all objects to draw.
World myWorld;
Camera myCamera;
SunMoon planets;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // Sets display colour to black
	myCamera.setProjectionMatrix();

	pix[0].readBMPFile("wood.bmp");
	pix[0].setTexture(0);

	pix[1].readBMPFile("mountain.bmp");  // make pixmap from image
	pix[1].setTexture(1);

	pix[2].readBMPFile("sun.bmp");
	pix[2].setTexture(2);
	pix[3].readBMPFile("moon.bmp");
	pix[3].setTexture(3);

	planets.Sun->textureID = 2;
	planets.Moon->textureID = 3;


	myWorld.list[6] = &planets;
}


void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void mouseAction(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		moving = 1;
		xBegin = x;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		moving = 0;
	}
}

void mouseMotion(GLint x, GLint y) {
	GLfloat theta;

	if (moving) {
		theta = (xBegin - x > 0) ? 1 : -1;

		if (coordinate == 3) {
			if (type == 1) {
				myCamera.rotate(1.0, 0.0, 0.0, theta * 0.5);
			} else if (type == 2) {
				myCamera.rotate(0.0, 1.0, 0.0, theta * 0.5);
			} else if (type == 3) {
				myCamera.rotate(0.0, 0.0, 1.0, theta * 0.5);
			} else if (type == 4) {
				myCamera.translate(theta * 0.02, 0, 0);
			} else if (type == 5) {
				myCamera.translate(0, theta * 0.02, 0);
			} else if (type == 6) {
				myCamera.translate(0, 0, theta * 0.02);
			} else if (type == 7) {
				myCamera.setViewVolume(myCamera.viewAngle, myCamera.aspect,
						myCamera.farDist, myCamera.nearDist + theta * 0.1);
			} else if (type == 8) {
				myCamera.setViewVolume(myCamera.viewAngle, myCamera.aspect,
						myCamera.farDist + theta * 0.1, myCamera.nearDist);
			} else if (type == 9) {
				myCamera.setViewVolume(myCamera.viewAngle + theta * 0.1,
						myCamera.aspect, myCamera.farDist, myCamera.nearDist);
			}
		}
		glutPostRedisplay();
	}

}


void backgroundColor() { // need to fix sun and moon times
	if (globalTime > 4.0 && globalTime < 7.0) {
		planets.Moon->translate(0, -0.001, 0);
	}
	if (globalTime > 8.0 && globalTime < 11.0) {
		planets.Sun->translate(0, 0.001, 0);
	}
	if (globalTime > 13.0 && globalTime < 19.0) {
		colorCount += 1;
		planets.Sun->translate(0, -0.0005, 0);

		if (colorCount == 50){
			r += 0.005;
			g += 0.005;
			b += 0.005;
			if(r > 0.19){
				r = 0.19;
			}
			if (g > 0.6){
				g = 0.6;
			}
			if (b > 0.8){
				b = 0.8;
			}
			colorCount = 0;
		}
	} else if (globalTime > 18.0 && globalTime < 24.0) {
		colorCount += 1;
		planets.Moon->translate(0, 0.0005, 0);
		if (colorCount == 50){
			r -= 0.005;
			g -= 0.005;
			b -= 0.005;
			if(r <= 0){
					r = 0;
			}
			if (g <= 0){
				g = 0;
			}
			if (b <= 0){
				b = 0;
			}
			colorCount = 0;
		}
	} else{
		if (colorCount != 0){
			colorCount = 0;
		}
	}
}

void time(void){
	static int oldTime, newTime;
	GLfloat speed = 0.0005;
	oldTime = clock();
	theta = (newTime - oldTime) * speed;
	globalTime += TIME;
	if(globalTime > 24){
		globalTime = 0;
	}
	newTime = clock();
	oldTime = newTime;
	printf("global: %f\n", globalTime);
	glutPostRedisplay();
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(red, green, blue);
	myCamera.setProjectionMatrix();
	myWorld.draw_world(); // draw all objects in the world
	planets.draw();
	backgroundColor();
	glClearColor(r, g, b, 0.0f); // sky blue
	printf("%f %f %f\n", r,g,b);
	glFlush();
	glutSwapBuffers();
}

void mainMenu(GLint option) {
	switch (option) {
	case 1:
		myWorld.list[0] = new Base();
		myWorld.list[1] = new House();
		myWorld.list[2] = new Mountains();
		myWorld.list[3] = new Clouds();
		myCamera.setDefaultCamera();
		red = 1.0;
		green = 1.0;
		blue = 1.0;
		break;
	case 2:
		exit(0);
	}
	glutPostRedisplay();
}

void colorSubMenu(GLint colorOption) {
	switch (colorOption) {
	case 1:
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	case 2:
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
	case 3:
		red = 0.0;
		green = 0.0;
		blue = 1.0;
		break;
	case 4:
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}
	glutPostRedisplay();
}

void VCTransMenu(GLint transOption) {
	coordinate = 3;
	type = transOption;
	glutPostRedisplay();
}

void menu() {
	GLint VCTrans_Menu, subMenuColor;
	subMenuColor = glutCreateMenu(colorSubMenu);
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	glutAddMenuEntry(" White", 4);


	VCTrans_Menu = glutCreateMenu(VCTransMenu);
	glutAddMenuEntry(" Rotate X ", 1);
	glutAddMenuEntry(" Rotate Y ", 2);
	glutAddMenuEntry(" Rotate Z", 3);
	glutAddMenuEntry(" Translate X ", 4);
	glutAddMenuEntry(" Translate Y ", 5);
	glutAddMenuEntry(" Translate Z ", 6);
	glutAddMenuEntry(" Zoom ", 9);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" Colors ", subMenuColor);
	glutAddSubMenu(" View Transformations ", VCTrans_Menu);
	glutAddMenuEntry(" Quit", 2);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Mountain Skyline (by Calvin and Ethyl)");
	init();
	menu();

	glutIdleFunc(time);
	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
