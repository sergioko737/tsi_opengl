#if defined(linux) || defined(_WIN32) 
#include <GL/glut.h> 
/*Äëÿ Linux è Windows*/
#else #include <GLUT/GLUT.h>  /*Äëÿ Mac OS*/
#endif  

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
	glutMainLoop();    return 0;
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2i(250, 500);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(250, 100);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(600, 300);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.5, 0.5, 1.0);
	glVertex2i(600, 500);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(600, 100);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(250, 300);
	glEnd();
	glutSwapBuffers();
}