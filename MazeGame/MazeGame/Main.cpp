#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <irrKlang.h>

#include "Maze.h"
#include <string>
#include <ctime>

#define ROWS 41.0		// Defines values for X and Y co-ordinates on maze window
#define COLUMNS 41.0
int FPS = 3;			// Assigns FPS value

extern short characterDirection;	// Externs the characterDirection short from Maze.cpp

void display();
void displaySizeChange(int, int);	// Callback function for changing size of screen
void timer(int);					// Callback function for the timer for character movement
void keyboardInput(int, int, int);	// Callback function for keyboard input from user
bool gameover = false;
bool foundExit = false;
int timervalue = 0;
void GoMenu(int value);

// Sound engines for sounds in game
irrklang::ISoundEngine* SoundEngine = irrklang::createIrrKlangDevice();			// Game music
irrklang::ISoundEngine* SoundEngineFail = irrklang::createIrrKlangDevice();		// Failure sound effect
irrklang::ISoundEngine* SoundEngineSuccess = irrklang::createIrrKlangDevice();	// Success sound effect

void init()
{
	glClearColor(0.10, 0.10, 0.10, 1.0);			// Set's background colour to dark grey
	initMaze(COLUMNS, ROWS);	
	SoundEngine->play2D("music.mp3", GL_TRUE);		// Set's background music
}


time_t programstart;
time_t programend = 240;
int main(int argc, char** argv)
{

	system("cls");
	printf("~~~~~~DEATH MAZE~~~~~~\n");
	printf("Please enter a value for the below menu:\n");
	printf("1. Play Game\n");
	printf("2. Instructions\n");
	printf("3. Exit\n");

	std::string option;
	std::cin >> option;

	if (option == "1")
	{
		glutInit(&argc, argv);												// Initialise GLUT
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
		glutInitWindowSize(500, 500);										// Set's the size of the GLUT window
		glutInitWindowPosition(300, 300);									// Set's the position of the GLUT window



		glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");			// Creates GLUT window and defines it's title


		int subMenu1 = glutCreateMenu(GoMenu);

		glutAddMenuEntry("Normal Speed", 1);
		glutAddMenuEntry("Speed x2", 2);
		glutAddMenuEntry("Speed x4", 3);
		glutCreateMenu(GoMenu);
		glutAddSubMenu("Speed Settings", subMenu1);
		glutAddMenuEntry("Exit", 4);
		glutAttachMenu(GLUT_RIGHT_BUTTON);


		glutDisplayFunc(display);
		glutReshapeFunc(displaySizeChange);									// Called when the windows size is changed (through maximisation/minimisation)
		glutTimerFunc(0, timer, 0);											// Timer function
		glutSpecialFunc(keyboardInput);

		time(&programstart);												// Start's counting ticks for game timer



		init();
		glutMainLoop();														// Main GLUT loop

		return 0;
	}

	if (option == "2")
	{
		system("cls");
		printf("~~~~~~ INSTRUCTIONS ~~~~~~\n");
		printf("When you start the game your character will be stationary and you will start in the top left corner (marked green).\n \n");
		printf("Your aim is to navigate the maze and reach the exit which can be found in the bottom right corner (marked blue).\n \n");
		printf("But be careful! If you touch any of the red walls you instantly die and have to restart! Why do you think it's called DEATH MAZE?!\n \n");
		printf("\n");
		printf("~~~~~~ CONTROLS ~~~~~~\n");
		printf("Pressing the following keys performs the following actions:\n");
		printf("Up Arrow - Moves character up\n");
		printf("Down Arrow - Moves character down\n");
		printf("Left Arrow - Moves character left\n");
		printf("Right Arrow - Moves character right\n");
		printf("Right Mouse Click - Opens a menu that allows the user to change the speed of their character, allowing them to complete the maze faster... If they can complete it! It also allows the user to exit the game.\n");
		printf("\n");
		printf("Once you start moving, your character will not stop! It has a continuous movement which makes it harder to navigate the maze!\n You are also timed just to make it that little bit harder!\n");
		printf("\n");
		printf("Enter 1 and press enter to return to the main menu");
		
		std::string option2;
		std::cin >> option2;

		if (option2 == "1")
		{
			system("cls");
			printf("~~~~~~ DEATH MAZE ~~~~~~\n");
			printf("Please enter a value for the below menu:\n");
			printf("1. Play Game\n");
			printf("2. Exit\n");

			std::string option3;
			std::cin >> option3;

			if (option3 == "1")
			{
				glutInit(&argc, argv);												// Initialise GLUT
				glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);						// Initialise the display mode (double buffered for better performance)
				glutInitWindowSize(500, 500);										// Set's the size of the GLUT window
				glutInitWindowPosition(300, 300);									// Set's the position of the GLUT window



				glutCreateWindow("2D Maze Game - Adam Foot (SOFT356 CW2)");			// Creates GLUT window and defines it's title


				int subMenu1 = glutCreateMenu(GoMenu);

				glutAddMenuEntry("Normal Speed", 1);
				glutAddMenuEntry("Speed x2", 2);
				glutAddMenuEntry("Speed x4", 3);
				glutCreateMenu(GoMenu);
				glutAddSubMenu("Speed Settings", subMenu1);
				glutAddMenuEntry("Exit", 4);
				glutAttachMenu(GLUT_RIGHT_BUTTON);


				glutDisplayFunc(display);
				glutReshapeFunc(displaySizeChange);									// Called when the windows size is changed (through maximisation/minimisation)
				glutTimerFunc(0, timer, 0);											// Timer function
				glutSpecialFunc(keyboardInput);

				time(&programstart);												// Start's counting ticks for game timer



				init();
				glutMainLoop();														// Main GLUT loop

				return 0;
			}

			if (option3 == "2")
			{
				exit(0);
			}

		}
	}
	
	if (option == "3")
	{
		exit(0);
	}

}

void GoMenu(int value) {
	switch (value)
	{
	case 1:
		FPS = 3;
		break;
	case 2:
		FPS = 6;
		break;
	case 3:
		FPS = 12;
		break;
	case 4:
		exit(0);
		break;
	}

	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);		// Clears colour buffer
	drawMaze();							// Draws the maze
	drawCharacter();					// Draws the character
	drawExit();							// Draws the exit
	glutSwapBuffers();					// Swap buffers and displays the new frame

	double secondssincestart = difftime(time(NULL), programstart);
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
		char buff[200];
		const std::string time = std::to_string(secondssincestart);
		const char* seconds = time.c_str();
		const std::string text = "Well done you made it! You completed it in " + time + " seconds!";
		const char* text2 = text.c_str();
		sprintf_s(buff, seconds);
		MessageBox(NULL, text2, "Congratulations!", 0);
		exit(0);
	}

	// Runs if player is out of time (max time 3 minutes or 240 seconds)
	if (secondssincestart >= programend)
	{
		SoundEngine->drop();
		SoundEngineFail->play2D("failure.wav", GL_FALSE);
		MessageBox(NULL, "Game Over! You obtained a score of 0!", "Try again!", 0);
		exit(0);
	}
	
}

void displaySizeChange(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);			// Set's the viewport of the window automatically
	glMatrixMode(GL_PROJECTION);									// Set's matrix mode to projection
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);					// Sets the clipping planes and distances for depth clipping
	glMatrixMode(GL_MODELVIEW);										// Set's matrix back to model_view
}

void timer(int)
{
	glutPostRedisplay();					// Calls display function asap - new frame is displayed every time it's called
	glutTimerFunc(1000 / FPS, timer, 0);	// Called x time every second (depending on the FPS value set)
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
