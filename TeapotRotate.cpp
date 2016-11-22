#include <cstdlib>			// standard definitions
#include <iostream>			
#include <cstdio>			 
#include <cmath>			

#include <GL/glut.h>			
#include <GL/glu.h>			
#include <GL/gl.h>			

using namespace std;			

double rotAngle = 10;			

							

void init()
{
	glClearColor(1, 1, 1, 1);		
	glClearDepth(1.0);			

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 1000);	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(				
		0.0, 0.0, 5.0,		
		0.0, 0.0, 0.0,		
		0.0, 1.0, 0.0);		

	glEnable(GL_DEPTH_TEST);		

	glEnable(GL_LIGHTING);		
	glEnable(GL_LIGHT0);		

	float lpos[] = { 1, 1, 1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lpos);

	 glShadeModel(GL_FLAT);		
	//glShadeModel(GL_SMOOTH);		
}

void display()
{
	glClear(
		GL_COLOR_BUFFER_BIT |		
		GL_DEPTH_BUFFER_BIT);		

	glPushMatrix();			

	glRotated(rotAngle, 0, 1, 0);	


	glEnable(GL_COLOR_MATERIAL);	
	glColor3f(0.5, 0.5, 0.5);		

	glutSolidTeapot(1.5);			

	glPopMatrix();			
	glFlush();				

	glutSwapBuffers();			
}


void keyboard(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 'a':
		rotAngle += 5;			
		break;
	case 'd':
		rotAngle -= 5;			
		break;
	case 'q':
		exit(0);			
	}
	glutPostRedisplay();		
}


int main()
{
	glutInitDisplayMode(		
	GLUT_DOUBLE |		
	GLUT_DEPTH |		
	GLUT_RGB);		

	glutCreateWindow("Teapot Rotation");	

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 150);

	glutDisplayFunc(display);		
	glutKeyboardFunc(keyboard);		

	init();				

	glutMainLoop();			
	return 0;
}