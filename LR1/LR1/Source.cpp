#if defined(linux) || defined(_WIN32) 
#include <GL/glut.h>		// For Linux and Windows
#else #include <GLUT/GLUT.h>  // For MacOS
#endif
#include <math.h>

void reshape(int w, int h);
void display();

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL lesson 1");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float left = -100, right = 100, bottom = -50, top = 50;
	gluOrtho2D(left, right, bottom, top);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, bottom);
	glVertex2f(0, top);
	glVertex2f(left, 0);
	glVertex2f(right, 0);
	glEnd();
}

void display()
{
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (float x = -100; x < 100; x += 0.5) {
		glColor3d(fabs(x/100), 0.5, fabs(1 - x/100));
		glVertex2f(x, fabs(1.0 / 4.0*x + 3.0*cos(100.0*x)*sin(x)));
		glVertex2f(x, fabs(1.0 / 4.0*x + 3.0*cos(100.0*x)*sin(x))*2);
	}
	glEnd();
	glutSwapBuffers();
}