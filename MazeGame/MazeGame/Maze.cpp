#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Maze.h"

int mazeX, mazeY;			// Maze x and y co-ordinates
int posX = 30, posY = 30;	// Position of character
short characterDirection;
extern bool gameover;		// Allows access to gameover bool from Main.cpp


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
		glColor3f(0.10, 0.10, 0.10);	// Set's line colour
	}
	
	glBegin(GL_LINE_LOOP);

	glVertex2f(x, y);				// Set's lines in a square using the co-ordinates given.
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}

void drawCharacter()
{
	if (characterDirection == UP)
	{
		posY++;
	}
	else if (characterDirection == RIGHT)
	{
		posX++;
	}
	else if (characterDirection == DOWN)
	{
		posY--;
	}
	else if (characterDirection == LEFT)
	{
		posX--;
	}
	glColor3f(0.0, 1.0, 0.0);	// Set's colour of character to green
	glRectd(posX, posY, posX + 1, posY + 1);

	// Checks to see if character has hit a wall that it wasn't allowed to.
	if (posX == 0 || posX == mazeX - 1 || posY == 0 || posY == mazeY - 1)
	{
		gameover = true;
	}
	
}