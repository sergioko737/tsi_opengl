#include <GL/glut.h>

GLUnurbsObj* nurbs;
GLfloat left[][3] = { { 0 ,-3, 0.0 },{ -2 , 0, 0.0 },{ -3 , 4, 0.0 },{ -1.5 , 4, 0.0 },{ 0, 3, 0.0 } };
GLfloat right[][3] = { { 0 ,-3, 0.0 },{ 2 , 0, 0.0 },{ 3 , 4, 0.0 },{ 1.5 , 4, 0.0 },{ 0, 3, 0.0 } };
GLfloat knots[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(8.0);

	nurbs = gluNewNurbsRenderer();
	gluNurbsProperty(nurbs, GLU_SAMPLING_TOLERANCE, 25.0);

	glColor3f(1, 0, 0);
	gluBeginCurve(nurbs);
	gluNurbsCurve(nurbs,10, knots, 3, &left[0][0], 5, GL_MAP1_VERTEX_3);
	gluEndCurve(nurbs);

	gluBeginCurve(nurbs);
	gluNurbsCurve(nurbs, 10, knots, 3, &right[0][0], 5, GL_MAP1_VERTEX_3);
	gluEndCurve(nurbs);

	glPointSize(4.0);
	glColor3f(0.0, 0.0, 1);
	glBegin(GL_POINTS);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3f(left[i][0], left[i][1], left[i][2]);
		glVertex3f(right[i][0], right[i][1], right[i][2]);
	}
	glEnd();

	gluDeleteNurbsRenderer(nurbs);
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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("LAB 2_3");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}