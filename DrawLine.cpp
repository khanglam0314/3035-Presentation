#include <windows.h>
#include<gl/glut.h>
#include<gl/glu.h>
#include<gl/gl.h>


void myInit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);

}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.4, 0.2);
	glPointSize(4.0);
	glBegin(GL_LINES);
	glVertex2i(1000, 1000);
	glVertex2i(20, 20);


	glEnd();
	glFlush();

}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 620);
	glutCreateWindow("DrawLine");
	glutDisplayFunc(draw);
	myInit();
	glutMainLoop();

}