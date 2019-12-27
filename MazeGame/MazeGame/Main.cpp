#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <irrKlang.h>

#include "Maze.h"
#include <string>
#include <ctime>

#define ROWS 41.0		// Defines values for X and Y co-ordinates on maze window
#define COLUMNS 41.0
#define FPS 3			// Assigns FPS value

extern short characterDirection;	// Externs the characterDirection short from Maze.cpp

void display();
void displaySizeChange(int, int);	// Callback function for changing size of screen
void timer(int);					// Callback function for the timer for character movement
void keyboardInput(int, int, int);	// Callback function for keyboard input from user
bool gameover = false;
bool foundExit = false;
int timervalue = 0;

DWORD StartTime = 0;	// Set's start time for timer
DWORD EndTime = 0;		// Set's end time for timer
DWORD CurrentTime = 0;	// Set's current time for timer

// Sound engines for sounds in game
irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();			// Game music
irrklang::ISoundEngine* SoundEngineFail = irrklang::createIrrKlangDevice();		// Failure sound effect
irrklang::ISoundEngine* SoundEngineSuccess = irrklang::createIrrKlangDevice();	// Success sound effect

void init()
{
	glClearColor(0.10, 0.10, 0.10, 1.0);			// Set's background colour to dark grey
	initMaze(COLUMNS, ROWS);	
	SoundEngine->play2D("music.mp3", GL_TRUE);	// Set's background music
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);												// Initialise GLUT
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
	glutInitWindowSize(500, 500);								// Set's the size of the GLUT window
	glutInitWindowPosition(300, 300);								// Set's the position of the GLUT window
	glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");		// Creates GLUT window and defines it's title
	glutDisplayFunc(display);
	glutReshapeFunc(displaySizeChange);									// Called when the windows size is changed (through maximisation/minimisation)
	glutTimerFunc(0, timer, 0);									// Timer function
	glutSpecialFunc(keyboardInput);

	StartTime = GetTickCount64();											// Start's counting ticks for game timer
	EndTime = StartTime + (60 * 1000);									// Get's 60 seconds in milliseconds and set's it as end time
	
	init();
	glutMainLoop();														// Main GLUT loop

	return 0;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clears colour buffer
	drawMaze();							// Draws the maze
	drawCharacter();					// Draws the character
	drawExit();							// Draws the exit
	CurrentTime = GetTickCount64();
	glutSwapBuffers();					// Swap buffers and displays the new frame

	// Runs if player touches an out of bounds block
	if (gameover)
	{
		SoundEngine->drop();
		SoundEngineFail->play2D("failure.wav", GL_FALSE);
		MessageBox(NULL, "Game Over! You obtained a score of 0!", "GAME OVER!", 0);
		exit(0);
	}

	// Runs if player finds the exit before the time runs out
	if (foundExit)
	{
		SoundEngine->drop();
		SoundEngineSuccess->play2D("success.wav", GL_FALSE);
		char buff[100];
		const std::string time = std::to_string(CurrentTime);
		sprintf_s(buff, "Well done you found the exit! You obtained a score of: ", time);
		printf(time.c_str());
		MessageBox(NULL, buff, "Congratulations!", 0);
		exit(0);
	}

	// Runs if the player hasn't reached the end before the 60 second timer
	if (CurrentTime >= EndTime)
	{
		SoundEngine->drop();
		SoundEngineFail->play2D("failure.wav", GL_FALSE);
		MessageBox(NULL, "Game Over! You obtained a score of 0 ", "Try again!", 0);
		exit(0);
	}
}

void displaySizeChange(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);			// Set's the viewport of the window automatically
	glMatrixMode(GL_PROJECTION);												// Set's matrix mode to projection
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);		// Sets the clipping planes and distances for depth clipping
	glMatrixMode(GL_MODELVIEW);													// Set's matrix back to model_view
}

void timer(int)
{
	glutPostRedisplay();							// Calls display function asap - new frame is displayed every time it's called
	glutTimerFunc(1000 / FPS, timer, 0);	// Called 10 times every second (10 FPS)
}

void keyboardInput(int keyPressed, int, int)
{
	switch(keyPressed)					// Depending on what key is pressed controls the direction of the character movement
	{
	case GLUT_KEY_UP:
		characterDirection = UP;
		break;
	case GLUT_KEY_RIGHT:
		characterDirection = RIGHT;
		break;
	case GLUT_KEY_DOWN:
		characterDirection = DOWN;
		break;
	case GLUT_KEY_LEFT:
		characterDirection = LEFT;
		break;
	}
}
