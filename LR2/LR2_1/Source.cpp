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
	glutCreateWindow("LAB 2_1");
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
	GLdouble plane[4] = { -1, 1, 0, 1000 };
	glClipPlane(GL_CLIP_PLANE0, plane);
	glEnable(GL_CLIP_PLANE0);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	readFromFile();
	glColor3d(1, 0, 0);
	glLineWidth(4.0);
	for (unsigned int i = 0; i < code.size(); i++)
		if (code[i] < 0)
		{
			moveto(point[abs(code[i]) - 1]);
		}
		else
		{
			lineto(point[(code[i]) - 1]);
		}
	glDisable(GL_CLIP_PLANE0);
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