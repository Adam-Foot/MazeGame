#include <GL/glew.h>
#include <GL/freeglut.h>


void display();



void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);	// Sets of background of window to black
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);												// Initialise GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
	glutInitWindowSize(600, 600);								//  Sets the size of the GLUT window
	glutInitWindowPosition(300, 300);								// Sets the position of the GLUT window
	glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");		// Creates GLUT window and defines it's title
	glutDisplayFunc(display);
	glutMainLoop();														// Main GLUT loop

	return 0;
}

void display()
{
	glutSwapBuffers();	// Swap buffers and displays the new frame
}
