#include <GL/glew.h>
#include <GL/freeglut.h>


void display();



void init()
{
	glClearColor(0.10, 0.10, 0.10, 1.0);	// Set's background colour to dark grey
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);												// Initialise GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
	glutInitWindowSize(600, 600);								// Set's the size of the GLUT window
	glutInitWindowPosition(300, 300);								// Set's the position of the GLUT window
	glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");		// Creates GLUT window and defines it's title
	glutDisplayFunc(display);
	init();
	glutMainLoop();														// Main GLUT loop

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clears colour buffer
	glutSwapBuffers();					// Swap buffers and displays the new frame
}
