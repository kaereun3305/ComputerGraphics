#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

void drawPolyLineFile(const char* fileName) {

	std::ifstream inStream;
	inStream.open(fileName);	// open the file
	if (inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;		           // read the number of polylines
	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

void setWindow(float left, float right, int bottom, int top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 480.0, 0.0);
	int j = 0;
	for (int i = 0; i < 25; i++) {

		int oi = i % 5;

		if ((i % 2 == 0)){
			glViewport(oi * 128, j * 96, 128, 96);
			drawPolyLineFile("dino.dat");
			glFlush();
		}
		if (i % 5 == 4) {
			j++;
		}
	}

	int m = 0;

	setWindow(0, 640.0, 0.0, 480.0);
	for (int i = 0; i < 25; i++) {
		int oi = i % 5;
		if ((i % 2 == 1)) {
			glViewport(oi * 128, m * 96, 128, 96);
			drawPolyLineFile("dino.dat");
		}
		if (i % 5 == 4) {
			m++;
		}
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("HW1_5");
	glutDisplayFunc(render);;
	glutMainLoop();
	return(0);
}
