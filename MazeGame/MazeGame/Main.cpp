#include <GL/glew.h>
#include <GL/freeglut.h>
#include <irrKlang.h>

#include "Maze.h"

#define ROWS 60.0		// Defines values for X and Y co-ordinates on maze window
#define COLUMNS 60.0
#define FPS 10			// Assigns FPS value

extern short characterDirection;	// Externs the characterDirection short from Maze.cpp

void display();
void displaySizeChange(int, int);	// Callback function for changing size of screen
void timer(int);					// Callback function for the timer for character movement
void keyboardInput(int, int, int);	// Callback function for keyboard input from user
bool gameover = false;
bool foundExit = false;
int timervalue = 0;

DWORD StartTime = 0;
DWORD EndTime = 0;
DWORD CurrentTime = 0;

// Sound engines for sounds in game
irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();			// Game music
irrklang::ISoundEngine* SoundEngineFail = irrklang::createIrrKlangDevice();		// Failure sound effect
irrklang::ISoundEngine* SoundEngineSuccess = irrklang::createIrrKlangDevice();	// Success sound effect

void init()
{
	glClearColor(0.10, 0.10, 0.10, 1.0);	// Set's background colour to dark grey
	initMaze(COLUMNS, ROWS);
	SoundEngine->play2D("music.mp3", GL_TRUE);
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
	glutTimerFunc(0, timer, 0);									// Timer function
	glutSpecialFunc(keyboardInput);

	StartTime = GetTickCount();
	EndTime = StartTime + (60 * 1000);
	
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
	
	glutSwapBuffers();					// Swap buffers and displays the new frame

	if (gameover)
	{
		SoundEngine->drop();
		SoundEngineFail->play2D("failure.wav", GL_FALSE);
		MessageBox(NULL, "Game Over! You obtained a score of 0 ", "Try again!", 0);
		exit(0);
	}

	if (foundExit)
	{
		SoundEngine->drop();
		SoundEngineSuccess->play2D("success.wav", GL_FALSE);
		MessageBox(NULL, "Well done you found the exit! You obtained a score of: ", "Congratulations!", 0);
		exit(0);
	}

	CurrentTime = GetTickCount();
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
