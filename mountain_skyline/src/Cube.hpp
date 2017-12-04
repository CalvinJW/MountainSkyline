#ifndef CCUBE_H
#define CCUBE_H

#include <GL/glut.h>
#include "Shape.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
	GLuint textureID[6];
	GLfloat faceColor[6][3];      	 // face color
	GLfloat cube_face_norm_mc[6][3]; // normal face in mc
	GLfloat cube_face_norm_wc[6][4]; // normal face in wc

public:
	Cube();
	void draw_face(int);
	void draw();
	void setTextureID(int index, int textureid);
};

#endif
