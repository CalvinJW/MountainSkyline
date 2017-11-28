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
#include "mesh.hpp"

GLint winWidth = 800, winHeight = 800;

GLfloat red = 1.0, green = 1.0, blue = 1.0;  //color
GLint moving = 0, xBegin = 0, coordinate = 1, type = 4, selected = 1;

//Declare a world containing all objects to draw.
World myWorld;
Camera myCamera;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(red, green, blue);
	myCamera.setProjectionMatrix();
	myWorld.draw_world(); // draw all objects in the world
	glFlush();
	glutSwapBuffers();
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
	GLfloat rx, ry, rz, theta;
	int i = selected - 1;

	if (moving) {
		theta = (xBegin - x > 0) ? 1 : -1;

		if (coordinate == 1) {
			if (type == 1) {
				rx = myWorld.list[i]->getMC().mat[0][0];
				ry = myWorld.list[i]->getMC().mat[1][0];
				rz = myWorld.list[i]->getMC().mat[2][0];
				myWorld.list[i]->rotate(rx, ry, rz, theta * 0.5);
			} else if (type == 2) {
				rx = myWorld.list[i]->getMC().mat[0][1];
				ry = myWorld.list[i]->getMC().mat[1][1];
				rz = myWorld.list[i]->getMC().mat[2][1];
				myWorld.list[i]->rotate(rx, ry, rz, theta * 0.5);
			} else if (type == 3) {
				rx = myWorld.list[i]->getMC().mat[0][2];
				ry = myWorld.list[i]->getMC().mat[1][2];
				rz = myWorld.list[i]->getMC().mat[2][2];
				myWorld.list[i]->rotate(rx, ry, rz, theta * 0.5);
			} else if (type == 4) {
				myWorld.list[i]->scale_change(theta * 0.02);
			}
		} else if (coordinate == 2) {
			if (type == 1) {
				rx = 1, ry = 0, rz = 0;
				myWorld.list[i]->rotate_origin(rx, ry, rz, theta * 0.5);
			} else if (type == 2) {
				rx = 0, ry = 1, rz = 0;
				myWorld.list[i]->rotate_origin(rx, ry, rz, theta * 0.5);
			} else if (type == 3) {
				rx = 0, ry = 0, rz = 1;
				myWorld.list[i]->rotate_origin(rx, ry, rz, theta * 0.5);
			} else if (type == 4) {
				myWorld.list[i]->translate(theta * 0.02, 0, 0);
			} else if (type == 5) {
				myWorld.list[i]->translate(0, theta * 0.02, 0);
			} else if (type == 6) {
				myWorld.list[i]->translate(0, 0, theta * 0.02);
			}
		} else if (coordinate == 3) {
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

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);  // Sets display colour to black
	myCamera.setProjectionMatrix();

//	Mesh mymesh;
//	mymesh.readMesh("barn.txt");
//	mymesh.printMesh();

}

void mainMenu(GLint option) {
	switch (option) {
	case 1:
		myWorld.list[0] = new Pyramid();
		myWorld.list[1] = new House();
		myWorld.list[2] = new Mountains();
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

void MCTransMenu(GLint transOption) {
	coordinate = 1;
	type = transOption;
	glutPostRedisplay();
}

void WCTransMenu(GLint transOption) {
	coordinate = 2;
	type = transOption;
	glutPostRedisplay();
}

void VCTransMenu(GLint transOption) {
	coordinate = 3;
	type = transOption;
	glutPostRedisplay();
}

void ObjSubMenu(GLint objectOption) {
	selected = objectOption;
	glutPostRedisplay();
}

void menu() {
	GLint WCTrans_Menu, VCTrans_Menu, MCTrans_Menu, subMenuColor, Object_Menu;
	subMenuColor = glutCreateMenu(colorSubMenu);
	glutAddMenuEntry(" Red", 1);
	glutAddMenuEntry(" Green", 2);
	glutAddMenuEntry(" Blue", 3);
	glutAddMenuEntry(" White", 4);

	MCTrans_Menu = glutCreateMenu(MCTransMenu);
	glutAddMenuEntry(" Rotate X ", 1);
	glutAddMenuEntry(" Rotate Y ", 2);
	glutAddMenuEntry(" Rotate Z ", 3);
	glutAddMenuEntry(" Scale ", 4);

	WCTrans_Menu = glutCreateMenu(WCTransMenu);
	glutAddMenuEntry(" Rotate X ", 1);
	glutAddMenuEntry(" Rotate Y ", 2);
	glutAddMenuEntry(" Rotate Z ", 3);
	glutAddMenuEntry(" Translate X ", 4);
	glutAddMenuEntry(" Translate Y ", 5);
	glutAddMenuEntry(" Translate Z ", 6);

	VCTrans_Menu = glutCreateMenu(VCTransMenu);
	glutAddMenuEntry(" Rotate X ", 1);
	glutAddMenuEntry(" Rotate Y ", 2);
	glutAddMenuEntry(" Rotate Z", 3);
	glutAddMenuEntry(" Translate X ", 4);
	glutAddMenuEntry(" Translate Y ", 5);
	glutAddMenuEntry(" Translate Z ", 6);
	glutAddMenuEntry(" Clipping Near ", 7);
	glutAddMenuEntry(" Clipping Far ", 8);
	glutAddMenuEntry(" Angle ", 9);

	Object_Menu = glutCreateMenu(ObjSubMenu);
	glutAddMenuEntry(" Cube ", 1);
	glutAddMenuEntry(" Pyramid ", 2);
	glutAddMenuEntry(" House ", 3);

	glutCreateMenu(mainMenu);      // Create main pop-up menu.
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" Colors ", subMenuColor);
	glutAddSubMenu(" Model Transformations ", MCTrans_Menu);
	glutAddSubMenu(" WC Transformations ", WCTrans_Menu);
	glutAddSubMenu(" View Transformations ", VCTrans_Menu);
	glutAddSubMenu(" Object Selection ", Object_Menu);
	glutAddMenuEntry(" Quit", 2);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("A2 (Calvin)");
	init();
	menu();

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
