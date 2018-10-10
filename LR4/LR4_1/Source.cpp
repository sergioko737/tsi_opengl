#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>    /*Äëÿ Linux è Windows*/
#else
#include <GLUT/GLUT.h>  /*Äëÿ Mac OS*/
#endif

void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL lesson 6");

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
	glOrtho(-15, 15, -15, 15, -15, 15);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1, 1, 1, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glutWireTeapot(5);

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
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
	}
}
