#include<Windows.h>
#include <GL/glut.h> 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
struct Point
{
	float x, y, z;
};

vector<Point> v;
vector<vector<int>> faces;
int point_count, face_count;
double axisX = 0;
double axisY = 0;
double axisZ = 0;
double angle = 0;

void reshape(int w, int h);
void drawLetter();
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void readfromfile()
{
	float x, y, z;
	Point p;
	ifstream f("s.txt", ios::in);
	f >> point_count >> face_count;
	for (int i = 0; i < point_count; i++)
	{
		f >> p.x >> p.y >> p.z;
		v.push_back(p);
	}
	faces.resize(face_count);
	for (int i = 0; i < face_count; i++)
	{
		int n;
		f >> n;
		for (int j = 0; j < n; j++)
		{
			int p;
			f >> p;
			faces[i].push_back(p);
		}
	}
	f.close();
}

int main(int argc, char * argv[])
{
	readfromfile();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL lesson 7");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glutMainLoop();

	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-5, 25, -5, 25, -15, 15);
	//gluPerspective(60, 1, 0, 20);
	//gluLookAt(10, 10, 55, 10, 10, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity();
	int y = glutGet(GLUT_WINDOW_HEIGHT);
	int x = glutGet(GLUT_WINDOW_WIDTH);
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glColor3d(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 100, 0);
	glColor3d(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glEnd();
	glPopMatrix();

	glColor3f(1.0, 0.0, 0.0);

	glPushMatrix();
	
	drawLetter();
	
	glPopMatrix();

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	if (key == 65) {
		glLoadIdentity();
		display();
	}
		// key + to enlarge
	if (key == 43) {
		glTranslated(10, 10, 0.5);
		glScaled(1.05, 1.05, 1.05);
		glTranslated(-10, -10, -0.5);
		display();
	}
	// key - to reduce size
	if (key == 45) {
		glTranslated(10, 10, 0.5);
		glScaled(0.95, 0.95, 0.95);
		glTranslated(-10, -10, -0.5);
		display();
	}
	// DELETE key
	if (key == 127) {
		glTranslated(10, 10, 0.5);
		glRotated(5, 0, 0, 1);
		glTranslated(-10, -10, -0.5);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 1, 0);
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -1, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-1, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(1, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:
		glTranslated(10, 10, 0.5);
		glRotated(5, 1, 0, 0);
		glTranslated(-10, -10, -0.5);
		display();
		break;
	case GLUT_KEY_END:
		glTranslated(10, 10, 0.5);
		glRotated(5, 0, 1, 0);
		glTranslated(-10, -10, -0.5);
		display();
		break;
	case GLUT_KEY_PAGE_UP:
		glTranslated(10, 10, 0.5);
		glRotated(-5, 1, 1, 1);
		glTranslated(-10, -10, -0.5);
		display();
		break;
	case GLUT_KEY_PAGE_DOWN:
		glTranslated(10, 10, 0.5);
		glRotated(5, 1, 1, 1);
		glTranslated(-10, -10, -0.5);
		display();
		break;
	}
}

void drawLetter() {
	for (int i = 0; i < face_count; i++)
	{
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < faces[i].size(); j++)
		{
			glVertex3f(v[faces[i][j]].x, v[faces[i][j]].y, v[faces[i][j]].z);
		}
		glEnd();
	}
}