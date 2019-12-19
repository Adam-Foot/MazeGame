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
	for (int x = 0; x < mazeX; x++)
	{
		for (int y = 0; y < mazeY; y++)
		{
			unit(x, y);
		}
	}
}

void unit(int x, int y)
{

	// Loop that changes the colour of the outside of the grid to red
	if (x == 0 || y == 0 || x == mazeX - 1 || y == mazeY - 1)
	{
		glLineWidth(1.0);
		glColor3f(0.75, 0.0, 0.0);
	}
	else
	{
		glLineWidth(1.0);						// Set's line width
		glColor3f(1.0, 1.0, 1.0);	// Set's line colour
	}
	
	glBegin(GL_LINE_LOOP);

	glVertex2f(x, y);				// Set's lines in a square using the co-ordinates given.
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}