#include <GL/glew.h>
#include <GL/freeglut.h>

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(60.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(60.0, 10.0, 0.0);

	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);

	glVertex3f(10.0, 90.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(60.0, 80.0, 0.0);
	glVertex3f(60.0, 90.0, 0.0);
	glVertex3f(20.0, 80.0, 0.0);
	glVertex3f(10.0, 90.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(40.0, 55.0, 0.0);
	glVertex3f(40.0, 45.0, 0.0);
	glVertex3f(20.0, 55.0, 0.0);
	glVertex3f(20.0, 45.0, 0.0);

	glEnd();
	glFlush();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
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
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("hw1_2.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}
