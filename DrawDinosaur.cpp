#include <fstream>
#include <windows.h>
#include <math.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
using namespace std;
GLint x; GLint y; GLint d;
void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.31f, 0.03f, 0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}
void drawPolylineFile(char * fileName) {
	fstream inStream;
	inStream.open(fileName, ios::in); // open the file
	if (inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	GLint numpolys, numLines, x, y;
	inStream >> numpolys; // read the number of polylines
	for (int j = 0; j < numpolys; j++) // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP); // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y; // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}
void display_dino() {
	drawPolylineFile("dino.dat");
}

void processNormalKeys(unsigned char key, int mx, int my) {
	if (key == 'E') {
		glColor3f(0.31f, 0.0f, 0.0f);
		glutPostRedisplay();
	}
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("dat dino");
	glutDisplayFunc(display_dino);
	glutKeyboardFunc(processNormalKeys);
//	glutSpecialFunc(processSpecialKeys);
	glutPostRedisplay();
	myInit();
	glutMainLoop();
}