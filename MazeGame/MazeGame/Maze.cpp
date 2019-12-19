#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Maze.h"

int mazeX, mazeY;

void initMaze(int x, int y)
{
	mazeX = x;
	mazeY = y;
}

void drawMaze()
{
	unit(20, 20);
}

void unit(int x, int y)
{

	glLineWidth(1.0);						// Set's line width
	glColor3f(0.0, 0.75, 0.0);	// Set's line colour
	
	glBegin(GL_LINE_LOOP);

	glVertex2f(x, y);				// Set's lines in a square using the co-ordinates given.
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}