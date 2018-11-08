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
	glutCreateWindow("LR4_1");

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

	//glOrtho(-15, 15, -15, 15, -15, 15);
	gluPerspective(60, 1, 0, 20);
	gluLookAt(15, 15, 15, 0, 0, 0, 0, 1, 0);
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glClearColor(1, 1, 1, 0);
}

void display()
{
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

	//glutWireTeapot(5);
	//glutSolidTeapot(3);
	//glutSolidSphere(3, 30, 30);
	//glutWireSphere(3, 127, 127);
	//glutSolidCube(3);
	//glutWireCube(3);
	//glutSolidTorus(3, 5, 15, 7);
	//glutWireTorus(1, 5, 15, 17);
	//glutSolidCone(4, 7, 12, 12);
	//glutWireCone(4, 7, 12, 12);
	//glutSolidTetrahedron();
	//glutWireTetrahedron();
	//glutSolidOctahedron();
	//glutWireOctahedron();
	//glutSolidDodecahedron();
	//glutWireDodecahedron();
	//glutSolidIcosahedron();
	glPushMatrix();
	//glTranslated(5, 5, 0);
	glutWireIcosahedron();
	glTranslated(-3, 0, 0);
	glPopMatrix();


	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
	// key + to enlarge
	if (key == 43) {
		glScaled(1.05, 1.05, 1.05);
		display();
	}
	// key - to reduce size
	if (key == 45) {
		glScaled(0.95, 0.95, 0.95);
		display();
	}
	// DELETE key
	if (key == 127) {
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 0, 0, 1);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(1, 1, 1);
		display();
		break;
	case GLUT_KEY_DOWN:
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-1, -1, -1);
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
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 1, 0, 0);
		display();
		break;
	case GLUT_KEY_END:
		glMatrixMode(GL_MODELVIEW);
		glRotated(5, 0, 1, 0);
		display();
		break;
	case GLUT_KEY_PAGE_UP:
		display();
		break;
	case GLUT_KEY_PAGE_DOWN:
		display();
		break;
	}
}
