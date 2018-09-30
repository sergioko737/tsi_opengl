#include <GL/glut.h>

using namespace std;

GLfloat ctrlpoints[8][3] = {
	{ 0.0, -3.0, 0.0 },{ -4.0, 2.0, 0.0 },
	{ -1.0, 4.0, 0.0 },{ 0.0, 2.0, 0.0 },
	{ 0.0, -3.0, 0.0 },{ 4.0, 2.0, 0.0 },
	{ 1.0, 4.0, 0.0 },{ 0.0, 2.0, 0.0 } };

void display(void)
{
	int t, i;
	glClearColor(0, 0, 0, 0); // background
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(5.0);
	for (t = 0; t < 5; t += 4) {
		glMap1f(GL_MAP1_VERTEX_3, 0.0, 2.0, 3, 4, &ctrlpoints[t][0]);
		glEnable(GL_MAP1_VERTEX_3);
		glBegin(GL_LINE_STRIP);
		float r = 0, g = 1;
		for (i = 0; i <= 60; i++) {
			glEvalCoord1f((GLfloat)i / 30.0);
			glColor3f(r+=0.06 , g-=0.03, 0);
		}
		glEnd();
	}
	/* Display control points */
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 8; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h / (GLfloat)w,
			5.0*(GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0*(GLfloat)w / (GLfloat)h,
			5.0*(GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(500, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}