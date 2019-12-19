#include <GL/glew.h>
#include <GL/freeglut.h>


#include "Maze.h"

#define ROWS 60.0		// Defines values for X and Y co-ordinates on maze window
#define COLUMNS 60.0

void display();
void displaySizeChange(int, int);	// Callback function for changing size of screen


void init()
{
	glClearColor(0.10, 0.10, 0.10, 1.0);	// Set's background colour to dark grey
	initMaze(COLUMNS, ROWS);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);												// Initialise GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
	glutInitWindowSize(600, 600);								// Set's the size of the GLUT window
	glutInitWindowPosition(300, 300);								// Set's the position of the GLUT window
	glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");		// Creates GLUT window and defines it's title
	glutDisplayFunc(display);
	glutReshapeFunc(displaySizeChange);									// Called when the windows size is changed (through maximisation/minimisation)
	init();
	glutMainLoop();														// Main GLUT loop

	return 0;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clears colour buffer
	drawMaze();
	glutSwapBuffers();					// Swap buffers and displays the new frame
}

void displaySizeChange(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);		// Set's the viewport of the window automatically
	glMatrixMode(GL_PROJECTION);											// Set's matrix mode to projection
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);		// Sets the clipping planes and distances for depth clipping
	glMatrixMode(GL_MODELVIEW);												// Set's matrix back to model_view
}
