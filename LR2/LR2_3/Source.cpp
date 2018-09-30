#include <GL/glut.h>

using namespace std;

GLfloat point[15][3] = { { 20, 37, 0 },{ 25, 25, 0 },{ 28, 25, 0 },{ 60, 20, 0 },{ 70, 40, 0 },{ 80, 55, 0 },{ 32, 61, 0 },{ 25, 58, 0 },{ 27, 55, 0.0 },{ 22, 63, 0 },{ 65, 70, 0 },{ 55, 80, 0 },{ 30, 80, 0 },{ 35, 80, 0 },{ 20, 70, 0.0 } };

GLfloat node[30] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


void display()
{
	GLUnurbs* nurbs = gluNewNurbsRenderer();
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(4);
	glColor3d(1, 0, 0);
	gluBeginCurve(nurbs);
	gluNurbsCurve(nurbs, 30, &node[0], 3, &point[0][0], 15, GL_MAP1_VERTEX_3);
	gluEndCurve(nurbs);

	glutSwapBuffers();
	gluDeleteNurbsRenderer(nurbs);

}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(100.0, 100.0, 100.0*(GLfloat)h / (GLfloat)w,
			100.0*(GLfloat)h / (GLfloat)w, 100.0, 100.0);
	else
		glOrtho(100.0*(GLfloat)w / (GLfloat)h,
			100.0*(GLfloat)w / (GLfloat)h, 100.0, 100.0, 100.0, 100.0);
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