#include <GL/glut.h>

GLUnurbsObj* nobj;

GLfloat ctlarray[][3] = {
	{ 0 ,-0.8, 0.0 },
	{ -0.8 , 0.8, 0.0 },
	{ 0 , 0.4, 0.0 },
	{ 0.8 , 0.8, 0.0 },
	{ 0, -0.8, 0.0 }
};

void init()
{
	glClearColor(1, 1, 1, 1);
	nobj = gluNewNurbsRenderer();
	gluNurbsProperty(nobj, GLU_SAMPLING_TOLERANCE, 25.0);
}

void Display()
{
	GLfloat knot_1[] = { 0, 0, 1, 2, 3, 4, 4 };
	GLfloat knot_2[] = { 0, 0, 0, 1, 2, 3, 3, 3 };
	GLfloat knot_3[] = { 0, 0, 0, 0, 1, 2, 2, 2, 2 };
	GLfloat knot_4[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };

	GLfloat knop_1[] = { 0, 1, 2, 3, 4, 5, 6 };
	GLfloat knop_2[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	GLfloat knop_3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	GLfloat knop_4[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.0);

	//glColor3f(0.9, 0.85, 0.1);
	// gluNurbsCurve(nobj, 7, knot_1, 3, &ctlarray[0][0], 2, GL_MAP1_VERTEX_3);

	//glColor3f(0.1, 0.85, 0.9);
	//gluNurbsCurve(nobj, 8, knot_2, 3, &ctlarray[0][0], 3, GL_MAP1_VERTEX_3);

	 //glColor3f(0.85, 0.4, 0.1);
	 //gluNurbsCurve(nobj, 9, knot_3, 3, &ctlarray[0][0], 4, GL_MAP1_VERTEX_3);

	 //glColor3f(0.9, 0.1, 0.85);
	 //gluNurbsCurve(nobj,10, knot_4, 3, &ctlarray[0][0], 5, GL_MAP1_VERTEX_3);


	glColor3f(1, 0, 0);
	//gluNurbsCurve(nobj, 7, knop_1, 3, &ctlarray[0][0], 2, GL_MAP1_VERTEX_3);

	glColor3f(0, 1, 0);
	gluNurbsCurve(nobj, 8, knop_2, 3, &ctlarray[0][0], 3, GL_MAP1_VERTEX_3);

	//glColor3f(0, 0, 1);
	//gluNurbsCurve(nobj, 9, knop_3, 3, &ctlarray[0][0], 4, GL_MAP1_VERTEX_3);

	//glColor3f(0.9, 0.1, 0.85);
	//gluNurbsCurve(nobj, 10, knop_4, 3, &ctlarray[0][0], 5, GL_MAP1_VERTEX_3);

	glPointSize(4.0);
	glColor3f(0.0, 0.0, 1);
	glBegin(GL_POINTS);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3f(ctlarray[i][0], ctlarray[i][1], ctlarray[i][2]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("LAB 3");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}