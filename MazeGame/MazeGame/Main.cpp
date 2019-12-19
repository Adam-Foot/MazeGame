/**
 * This test file when ran should display 2 windows.
 *
 * One of them will be the console and one should be a black box which contains a white square.
 * If this window does not appear then there is an issue with the setup for the dependencies (specifically FREEGLUT and GLEW)
 */

#include <GL/glew.h>
#include <GL/freeglut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	glVertex2f(0.0, 0.0);	// Bottom left
	glVertex2f(0.5, 0.0);	// Bottom right
	glVertex2f(0.5, 0.5);	// Top right
	glVertex2f(0.0, 0.5);	// Top left

	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);							// Window size in pixels
	glutInitWindowPosition(500, 500);							// Position of the window from the top left corner of the screen (in pixels)
	glutCreateWindow("Test window for GLEW and FREEGLUT!");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}