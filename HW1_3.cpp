#include <GL/glew.h>
#include <GL/freeglut.h>
#include <corecrt_math.h>

void drdisc(double r, double x, double y) {

	int vnumber = 180;
	float pi = 3.1415926;

	for (int i = 0; i <= 360; i++) {
		float rx = r * cos(i * pi / vnumber);
		float ry = r * sin(i * pi / vnumber);
		glVertex2f(rx + x, ry + y);
	}
	glEnd();
}

void drawScene(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	drdisc(20.0, 25.0, 75.0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	drdisc(10.0, 25.0, 75.0);
	glFlush();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 160.0, 0.0, 120.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(640, 480);

	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW1_3.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}
