#include<Windows.h> 
#include <GL/glut.h>    /*Äëÿ Linux è Windows*/ 
#include <vector> 
#include <fstream>
#include <math.h>

using namespace std;

GLfloat points[31][3];

struct Point
{
	int x, y;
};
void reshape(int w, int h);
void display();
void readFromFile();
void lineto(Point p);
void moveto(Point p);
vector<Point> point;
vector<int>code;
Point currentPoint;

int main(int argc, char * argv[])
{
	currentPoint.x = 0; currentPoint.y = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("LAB 2_4");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	readFromFile();
	glColor3d(1, 0, 0);
	glLineWidth(3.0);
	for (int t = 0; t < 17; t += 8) {
		glMap1f(GL_MAP1_VERTEX_3, 0.0, 2.0, 3, 4, &points[t][0]);
		glEnable(GL_MAP1_VERTEX_3);
		glBegin(GL_LINE_STRIP);
		float r = 0, g = 1;
		for (int i = 0; i <= 60; i++) {
			glEvalCoord1f((GLfloat)i / 30.0);
			glColor3f(r += 0.06, g -= 0.03, 0);
		}
		glEnd();
	}
	for (int i = 0; i < code.size(); i++)
		if (code[i] < 0)
		{
			moveto(point[abs(code[i]) - 1]);
		}
		else
		{
			lineto(point[(code[i]) - 1]);
		}
	glFlush();
}
void readFromFile()
{
	fstream f("ecopoints.txt", ios::in);
	int pointNumber;
	Point p;
	f >> pointNumber;
	for (int i = 0; i < pointNumber; i++)
	{
		f >> p.x >> p.y;
		point.push_back(p);
		points[i][0] = p.x;
		points[i][1] = p.y;
		points[i][2] = 0.0;
	}
	int movesNumber, m;
	f >> movesNumber;
	for (int i = 0; i < movesNumber; i++)
	{
		f >> m; code.push_back(m);
	}
	f.close();
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