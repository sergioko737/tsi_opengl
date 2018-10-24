#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;

const double PI = 3.141592654;

int frameNumber = 0;

bool isSunOn = false;
bool isKeyOn = false; //key press hoiche kina , on or off detect korar jonno use kora hocche

void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2 * PI / 32 * d;
		glVertex2d(radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}


void drawSun()
{
	int i;
	glColor3f(1, 1, 0);
	for (i = 0; i < 13; i++) { // 13 ta rays draw kora hoice.
		glRotatef(360 / 13, 0, 0, 1); // Rotation er axis position.
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.65f, 0);//aita shurjer line er length
		glEnd();
	}
	drawDisk(0.5);

}

void drawWindmill() {
	int i;
	glColor3f(255, 255, 255);// Windmill er  lathi
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();

	glTranslatef(0, 3, 0);
	if (isKeyOn == true)
	{
		glRotated(frameNumber * (360.0 / 96), 0, 0, 1); //z axis rotationn speed
	}
	//blate er pakha
	glColor3ub(0, 0, 0);

	for (i = 0; i < 3; i++) {//blade er pakha no
		glRotated(120, 0, 0, 1);  // blader er pakha space
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);              //blader shape
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f, 0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}

}
void Mountain()
{
	//1st Mountain
	glColor3ub(1, 50, 32);
	glBegin(GL_TRIANGLES);
	glVertex2f(-3, -1);
	glVertex2f(0.3f, 2.0f);
	glVertex2f(2.5, -1);
	glEnd();
	//2nd Mountain
	glColor3ub(1, 50, 32);
	glBegin(GL_TRIANGLES);
	glVertex2f(-2, -1);
	glVertex2f(2.0f, 1.9f);
	glVertex2f(6, -1);
	glEnd();
	//3rd Mountain
	glColor3ub(1, 50, 32);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, -1);
	glVertex2f(7, 1.4f);
	glVertex2f(20, -1);
	glEnd();
}
void Grass()
{
	//Grass
	glColor3ub(55, 94, 34);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(8, -1.0f);
	glVertex2f(8, 1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

}
void Battery()
{

	//Battery Place
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2f, -0.6f);
	glVertex2f(7.4, -0.6f);
	glVertex2f(7.4, 0.2f);
	glVertex2f(0.2f, 0.2f);
	glEnd();

	////yellow color

	glColor3ub(223, 188, 96);
	glBegin(GL_POLYGON);
	glVertex2f(8.0f, -1.0f);
	glVertex2f(10, -1.0f);
	glVertex2f(7.1, 1.0f);
	glVertex2f(7.1f, 1.0f);
	glEnd();
	////////////////////////////Battery Box Lines////////////////////////
	//1.Battery Box .......
	glColor3ub(166, 166, 166);
	glBegin(GL_POLYGON);
	glVertex2f(0.5f, -0.4f);
	glVertex2f(1.5f, -0.4f);
	glVertex2f(1.5f, 0.4f);
	glVertex2f(0.5f, 0.4f);
	glEnd();
	//2.Battey Box
	glColor3ub(166, 166, 166);
	glBegin(GL_POLYGON);
	glVertex2f(1.8f, -0.4f);
	glVertex2f(2.8f, -0.4f);
	glVertex2f(2.8f, 0.4f);
	glVertex2f(1.8f, 0.4f);
	glEnd();
	//3.Battery Box
	glColor3ub(166, 166, 166);
	glBegin(GL_POLYGON);
	glVertex2f(3.1f, -0.4f);
	glVertex2f(4.1f, -0.4f);
	glVertex2f(4.1f, 0.4f);
	glVertex2f(3.1f, 0.4f);
	glEnd();
	//4.Battery Box
	glColor3ub(166, 166, 166);
	glBegin(GL_POLYGON);
	glVertex2f(4.4f, -0.4f);
	glVertex2f(5.4f, -0.4f);
	glVertex2f(5.4f, 0.4f);
	glVertex2f(4.4f, 0.4f);
	glEnd();
	//5.Battery Box
	glColor3ub(166, 166, 166);
	glBegin(GL_POLYGON);
	glVertex2f(5.7f, -0.4f);
	glVertex2f(7.0f, -0.4f);
	glVertex2f(7.0f, 0.6f);
	glVertex2f(5.7f, 0.6f);
	glEnd();

	//for small box..........
	//1
	glColor3ub(48, 48, 48);
	glBegin(GL_POLYGON);
	glVertex2f(0.5f, -0.4f);
	glVertex2f(0.8f, -0.4f);
	glVertex2f(0.8f, 0.4f);
	glVertex2f(0.5f, 0.4f);
	glEnd();
	//2
	glColor3ub(48, 48, 48);
	glBegin(GL_POLYGON);
	glVertex2f(1.8f, -0.4f);
	glVertex2f(2.1f, -0.4f);
	glVertex2f(2.1f, 0.4f);
	glVertex2f(1.8f, 0.4f);
	glEnd();
	//3
	glColor3ub(48, 48, 48);
	glBegin(GL_POLYGON);
	glVertex2f(3.1f, -0.4f);
	glVertex2f(3.4f, -0.4f);
	glVertex2f(3.4f, 0.4f);
	glVertex2f(3.1f, 0.4f);
	glEnd();
	//4
	glColor3ub(48, 48, 48);
	glBegin(GL_POLYGON);
	glVertex2f(4.4f, -0.4f);
	glVertex2f(4.7f, -0.4f);
	glVertex2f(4.7f, 0.4f);
	glVertex2f(4.4f, 0.4f);
	glEnd();
	//5
	glColor3f(48, 48, 48);
	glBegin(GL_POLYGON);
	glVertex2f(5.7f, 0.2f);
	glVertex2f(7.0f, 0.2f);
	glVertex2f(7.0f, 0.6f);
	glVertex2f(5.7f, 0.6f);
	glEnd();

	//for line inside the box..........
	//1
	glColor3f(51, 51, 0);
	glBegin(GL_POLYGON);
	glVertex2f(0.5f, 0.2f);
	glVertex2f(0.8f, 0.2f);
	glVertex2f(0.8f, 0.4f);
	glVertex2f(0.5f, 0.4f);
	glEnd();
	//2
	glColor3f(51, 51, 0);
	glBegin(GL_POLYGON);
	glVertex2f(1.8f, 0.2f);
	glVertex2f(2.1f, 0.2f);
	glVertex2f(2.1f, 0.4f);
	glVertex2f(1.8f, 0.4f);
	glEnd();
	//3
	glColor3f(51, 51, 0);
	glBegin(GL_POLYGON);
	glVertex2f(3.1f, 0.2f);
	glVertex2f(3.4f, 0.2f);
	glVertex2f(3.4f, 0.4f);
	glVertex2f(3.1f, 0.4f);
	glEnd();
	//4
	glColor3f(51, 51, 0);
	glBegin(GL_POLYGON);
	glVertex2f(4.4f, 0.2f);
	glVertex2f(4.7f, 0.2f);
	glVertex2f(4.7f, 0.4f);
	glVertex2f(4.4f, 0.4f);
	glEnd();
	///// Light box////////////////////////////////////////
	//1
	glColor3ub(4, 255, 80);
	glBegin(GL_POLYGON);
	glVertex2f(5.8f, 0.3f);
	glVertex2f(6.1f, 0.3f);
	glVertex2f(6.1f, 0.5f);
	glVertex2f(5.8f, 0.5f);
	glEnd();
	//2
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(6.2f, 0.3f);
	glVertex2f(6.5f, 0.3f);
	glVertex2f(6.5f, 0.5f);
	glVertex2f(6.2f, 0.5f);
	glEnd();
	//5
	glColor3ub(255, 102, 0);
	glBegin(GL_POLYGON);
	glVertex2f(6.6f, 0.3f);
	glVertex2f(6.9f, 0.3f);
	glVertex2f(6.9f, 0.5f);
	glVertex2f(6.6f, 0.5f);
	glEnd();

	//for box line .....
	//1
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0.8f, -0.1f);
	glVertex2f(1.5f, -0.1f);
	glVertex2f(1.5f, 0.1f);
	glVertex2f(0.8f, 0.1f);
	glEnd();
	//2
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(2.1f, -0.1f);
	glVertex2f(2.8f, -0.1f);
	glVertex2f(2.8f, 0.1f);
	glVertex2f(2.1f, 0.1f);
	glEnd();
	//3
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(3.4f, -0.1f);
	glVertex2f(4.1f, -0.1f);
	glVertex2f(4.1f, 0.1f);
	glVertex2f(3.4f, 0.1f);
	glEnd();
	//4
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(4.7f, -0.1f);
	glVertex2f(5.4f, -0.1f);
	glVertex2f(5.4f, 0.1f);
	glVertex2f(4.7f, 0.1f);
	glEnd();
}
void Windmaill()
{
	//1st Windmill
	glPushMatrix();
	glTranslated(0.50, 1, 0);
	glScaled(0.5, 0.5, 1);
	drawWindmill();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(1.0, 1.0, 0);
	glScaled(0.3, 0.3, 1);
	drawWindmill();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(1.5, 1.5, 0);
	glScaled(0.2, 0.2, 1);
	drawWindmill();
	glPopMatrix();

	//2nd Windmill
	glPushMatrix();
	glTranslated(2.1, 1.6, 0);
	glScaled(0.2, 0.2, 1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.9, 0.9, 0);
	glScaled(0.4, 0.4, 1);
	drawWindmill();
	glPopMatrix();

	//3rd Windmill
	glPushMatrix();
	glTranslated(3.5, 0.8, 0);
	glScaled(0.7, 0.7, 1);
	drawWindmill();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(3.9, 1.0, 0);
	glScaled(0.1, 0.1, 1);
	drawWindmill();
	glPopMatrix();

	//
	glPushMatrix();
	glTranslated(4.3, 1.0, 0);
	glScaled(0.1, 0.1, 1);
	drawWindmill();
	glPopMatrix();

	//4th Windmill
	glPushMatrix();
	glTranslated(4.9, 0.9, 0);
	glScaled(0.4, 0.4, 1);
	drawWindmill();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(5.5, 1.0, 0);
	glScaled(0.1, 0.1, 1);
	drawWindmill();
	glPopMatrix();

	//5th Windmill
	glPushMatrix();
	glTranslated(6.0, 0.9, 0);
	glScaled(0.2, 0.2, 1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(6.5, 1.2, 0);
	glScaled(0.1, 0.1, 1);
	drawWindmill();
	glPopMatrix();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);//color clear
	glColor3ub(150, 224, 255);// Fills the scene with bluef.
	glLoadIdentity();
	Mountain();
	Grass();
	Battery();
	Windmaill();
	glPushMatrix();
	glTranslated(5.8, 3, 0);
	if (isSunOn)
	{
		glRotated(-frameNumber*0.6, 0, 0, 1);//sun er speed
	}
	drawSun();
	glScaled(0.3, 0.3, 1);
	glPopMatrix();
	glutSwapBuffers();

}  // end display

void handleKeyPress(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: //up
	{
		isKeyOn = true;
		glutPostRedisplay();
		break;
	}
	case GLUT_KEY_DOWN: //down
	{
		isKeyOn = false;
		glutPostRedisplay();
		break;
	}
	}

}
//////////////////mouse
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		isKeyOn = true;
		glutPostRedisplay();
		break;

	case GLUT_RIGHT_BUTTON:
		isKeyOn = false;
		glutPostRedisplay();
		break;
	}
}
/////////////////////

void handleGeneralKeypress(unsigned char key, int a, int b)
{
	if (key == 'z')
	{
		isSunOn = true;
		glutPostRedisplay();
	}
	if (key == 'x')
	{
		isSunOn = false;
		glutPostRedisplay();
	}
}

void doFrame(int v) {  //Display frame rate frame rate show korbe..
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);
}

void init() {
	glClearColor(0.5f, 0.5f, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 8, -1, 4, -1, 1);// Image (l,r,b,t,n,f)
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(1200, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Natural view with Windmill");
	init();

	glutDisplayFunc(display);
	glutTimerFunc(100, doFrame, 0);

	//KEY PRESS HANDLER
	glutSpecialFunc(handleKeyPress);
	glutKeyboardFunc(handleGeneralKeypress);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}
