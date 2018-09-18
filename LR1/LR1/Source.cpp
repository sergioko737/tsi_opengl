#if defined(linux) || defined(_WIN32) 
#include <GL/glut.h> 
/*Для Linux и Windows*/
#else #include <GLUT/GLUT.h>  /*Для Mac OS*/
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
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float left = -5, right = 5, bottom = -5, top = 5;
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

	//рисование графика
	glColor3d(0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (float x = -4; x < 4; x += 0.1)
		glVertex2f(x, sin(x));
	glEnd();
	glutSwapBuffers();
}

void display()
{
	glColor3d(0, 0, 1);
	glBegin(GL_LINE_STRIP);
	for (float x = -4; x < 4; x += 0.1)
		glVertex2f(x, sin(x));
	glEnd();
	glutSwapBuffers();
	glutSwapBuffers();
}