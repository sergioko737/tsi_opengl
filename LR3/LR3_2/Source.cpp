#if defined(linux) || defined(_WIN32)
#include <GL/glut.h> /*Äëÿ Linux è Windows*/ 
#else 
#include <GLUT/GLUT.h> /*Äëÿ Mac OS*/ 
#endif

void reshape(int w, int h);
void display();
void processNormalKeys(unsigned char key, int x, int y);
void processSpecialKeys(int key, int x, int y);

int main(int argc, char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutCreateWindow("LR3_2");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}

void reshape(int w, int h) {
	int z = glutGet(GLUT_WINDOW_WIDTH);
	glViewport(0, 0, w, h);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(250, 550);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(250, 250);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(550, 250);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(550, 550);
	glEnd();

	// Backup matrix and reset coordinates
	glPushMatrix();
	glLoadIdentity();

	int y = glutGet(GLUT_WINDOW_HEIGHT);
	int x = glutGet(GLUT_WINDOW_WIDTH);
	glColor3d(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x/2, 0);
	glVertex2f(x/2, y);
	glVertex2f(0, y/2);
	glVertex2f(x, y/2);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
	// Keys Q,W,A,S moves square by diagonals
	if (key == 87) {
		glMatrixMode(GL_MODELVIEW);
		glTranslated(20, 20, 0);
		display();
	}
	if (key == 81) {
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-20, 20, 0);
		display();
	}
	if (key == 65) {
		glMatrixMode(GL_MODELVIEW);
		glTranslated(-20, -20, 0);
		display();
	}
	if (key == 83) {
		glMatrixMode(GL_MODELVIEW);
		glMatrixMode(GL_MODELVIEW);
		glTranslated(20, -20, 0);
		display();
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: glMatrixMode(GL_MODELVIEW);
		glTranslated(0, 20, 0);
		display();
		break;
	case GLUT_KEY_DOWN: glMatrixMode(GL_MODELVIEW);
		glTranslated(0, -20, 0);
		display();
		break;
	case GLUT_KEY_LEFT: glMatrixMode(GL_MODELVIEW);
		glTranslated(-20, 0, 0);
		display();
		break;
	case GLUT_KEY_RIGHT: glMatrixMode(GL_MODELVIEW);
		glTranslated(20, 0, 0);
		display();
		break;
	case GLUT_KEY_HOME: glMatrixMode(GL_MODELVIEW);
		glRotated(2, 0, 0, 1);
		glTranslated(15, -15, 0);
		display();
		break;
	case GLUT_KEY_END: glMatrixMode(GL_MODELVIEW);
		glRotated(-2, 0, 0, 1);
		glTranslated(-15, 15, 0);
		display();
		break;
	}
}