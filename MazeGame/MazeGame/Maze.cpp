#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Maze.h"

int mazeX, mazeY;			// Maze x and y co-ordinates
int posX = 2, posY = 37;	// Position of character
short characterDirection;
extern bool gameover;		// Allows access to gameover bool from Main.cpp
extern bool foundExit;		// Allows access to foundExit bool from Main.cpp
int exitX, exitY;			// Holds the values of the exit cube


void initMaze(int x, int y)
{
	mazeX = x; // 60
	mazeY = y; // 60
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
		glColor3f(0.75, 0.0, 0.0);
	}
	else
	{
		glColor3f(0.10, 0.10, 0.10);	// Set's line colour
	}
	
	glBegin(GL_QUADS);

	glVertex2f(x, y);				// Set's lines in a square using the co-ordinates given.
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}

void drawExit()
{
	exitX = 36;
	exitY = 2;

	glColor3f(0.0, 0.0, 1.0);
	glRectf(exitX, exitY, exitX + 1, exitY + 1);
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

	// Checks to see if character has hit a wall that it wasn't allowed to, or if they found the exit
	if (posX == 0 || posX == mazeX - 1 || posY == 0 || posY == mazeY - 1)
	{
		gameover = true;
	}

	if (posX == exitX && posY == exitY)
	{
		foundExit = true;
	}
	
}