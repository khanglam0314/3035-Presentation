#include <windows.h>   // use as needed for your system
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glPointSize(4.0);		            //set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);// to be explained
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
// the redraw function
void myDisplay(void)
{
#
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(40, 40);         // draw some points (don't know how many)
	glVertex2i(60, 90);
	glVertex2i(80, 40);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2i(40, 110);			// A
	glVertex2i(60, 130);			// B
	glVertex2i(70, 110);			// C
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2i(70, 110);			// C
	glVertex2i(60, 130);			// B
	glVertex2i(83, 135);			// D

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2i(83, 135);			// D
	glVertex2i(70, 110);			// C
	glVertex2i(95, 110);			// E

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(95, 110);			// E
	glVertex2i(83, 135);			// D
	glVertex2i(105, 143);			// F
		
	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2i(50, 165);			// A
	glVertex2i(80, 180);			// B
	glVertex2i(90, 170);			// C

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(50, 165);			// A
	glVertex2i(90, 170);			// C
	glVertex2i(90, 160);			// D

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex2i(50, 165);			// A
	glVertex2i(90, 160);			// D
	glVertex2i(80, 150);			// E

	glEnd();


	glBegin(GL_QUADS);

	glVertex2i(110, 165);			// A
	glVertex2i(130, 180);			// B
	glVertex2i(143, 168);			// C
	glVertex2i(131, 150);			// D
	
	glEnd();


	glBegin(GL_QUAD_STRIP);

	glColor3f(1.0f, 0.0f, 1.0f);

	glVertex2i(45, 210);			// B
	glVertex2i(40, 190);			// A
	glVertex2i(55, 210);			// C
	glVertex2i(60, 190);			// D

	
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2i(55, 210);			// C
	glVertex2i(60, 190);			// D
	glVertex2i(75, 215);			// E
	glVertex2i(70, 190);			// F
	
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2i(75, 215);			// E
	glVertex2i(70, 190);			// F
	glVertex2i(85, 220);			// I
	glVertex2i(80, 192);			// J
	
	
	glEnd();

	glFlush();		                 // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char **argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(640, 480);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("draw polygons"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}