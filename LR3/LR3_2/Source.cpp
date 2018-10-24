#include <Windows.h> 
#include <GL/glut.h>
#include <vector> 
#include <fstream>
#include <math.h>

using namespace std;

struct Point
{
	int x, y;
};

void reshape(int w, int h);
void display();
void drawLetter(vector<Point>point, vector<int>code);
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);
void readFromFile(string letter, Point p, vector<Point> *point, vector<int> *code);
void lineto(Point p);
void moveto(Point p);
vector<Point> spoint;
vector<int>scode;
vector<Point> kpoint;
vector<int>kcode;
Point currentPoint;
Point sp;
Point kp;
string s = "s.txt";
string k = "k.txt";

int main(int argc, char * argv[])
{
	if (spoint.size() == 0) readFromFile(s, sp, &spoint, &scode);
	if (kpoint.size() == 0)	readFromFile(k, kp, &kpoint, &kcode);
	currentPoint.x = 0; currentPoint.y = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1400, 800);
	glutCreateWindow("LAB 2_1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glColor3d(1, 0, 0);
	glLineWidth(4.0);

	glPushMatrix();
	drawLetter(spoint, scode);
	glPopMatrix();

	drawLetter(kpoint, kcode);

	glFlush();
}

void readFromFile(string letter, Point p, vector<Point> *point, vector<int> *code)
{
	fstream f(letter, ios::in);
	int pointNumber;
	
	f >> pointNumber;
	for (int i = 0; i < pointNumber; i++)
	{
		f >> p.x >> p.y;
		point->push_back(p);
	}
	int movesNumber, m;
	f >> movesNumber;
	for (int i = 0; i < movesNumber; i++)
	{
		f >> m; code->push_back(m);
	}
	f.close();
}

void drawLetter(vector<Point>point, vector<int>code) {
	for (unsigned int i = 0; i < code.size(); i++)
		if (code[i] < 0)
		{
			moveto(point[abs(code[i]) - 1]);
		}
		else
		{
			lineto(point[(code[i]) - 1]);
		}
}

void moveto(Point p) {
	currentPoint.x = p.x; currentPoint.y = p.y;
}

void lineto(Point p) {
	glBegin(GL_LINES);
	glVertex2i(currentPoint.x, currentPoint.y);
	glVertex2i(p.x, p.y);
	glEnd();
	currentPoint.x = p.x; currentPoint.y = p.y;
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
	// Keys Q,W,A,S moves square by diagonals
	if (key == 87) {
		glTranslated(20, 20, 0);
		display();
	}
	if (key == 81) {
		glTranslated(-20, 20, 0);
		display();
	}
	if (key == 65) {
		glTranslated(-20, -20, 0);
		display();
	}
	if (key == 83) {
		glTranslated(20, -20, 0);
		display();
	}
	// key + to enlarge
	if (key == 43) {
		glTranslated(-40, -40, 0);
		glScaled(1.1, 1.1, 0);
		display();
	}
	// key - to reduce size
	if (key == 45) {
		glTranslated(40, 40, 0);
		glScaled(0.9, 0.9, 0);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glTranslated(0, 20, 0);
		display();
		break;
	case GLUT_KEY_DOWN:
		glTranslated(0, -20, 0);
		display();
		break;
	case GLUT_KEY_LEFT:
		glTranslated(-20, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT:
		glTranslated(20, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME:
		glTranslatef(14, -13.5, 0);
		glRotated(2, 0, 0, 1);
		display();
		break;
	case GLUT_KEY_END:
		glTranslatef(-13.5, 14, 0);
		glRotated(-2, 0, 0, 1);
		display();
		break;
	}
}