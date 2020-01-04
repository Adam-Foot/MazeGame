#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Maze.h"

int mazeX, mazeY;			// Maze x and y co-ordinates
int posX = 1, posY = 39;	// Position of character
short characterDirection;
extern bool gameover;		// Allows access to gameover bool from Main.cpp
extern bool foundExit;		// Allows access to foundExit bool from Main.cpp
int exitX, exitY;			// Holds the values of the exit cube


void initMaze(int x, int y)
{
	mazeX = x; // 40
	mazeY = y; // 40
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
	if (x == 0				||
		y == 0				||
		x == mazeX - 1		||
		y == mazeY - 1		||
		x == 1 & y == 8		||x == 1 & y == 16	||x == 1 & y == 26	||x == 1 & y == 32	||
		x == 2 & y == 2		||x == 2 & y == 3	||x == 2 & y ==4	||x == 2 & y ==5	||x == 2 & y ==6	||x == 2 & y ==8	||x == 2 & y ==9	||x == 2 & y ==10	||x == 2 & y ==12	||x == 2 & y ==13	||x == 2 & y ==14	||x == 2 & y ==16	||x == 2 & y ==18	||x == 2 & y ==19	||x == 2 & y ==20	||x == 2 & y ==21	||x == 2 & y ==22	||x == 2 & y ==23	||x == 2 & y ==24	||x == 2 & y ==26	||x == 2 & y ==28	||x == 2 & y ==29	||x == 2 & y ==30	||x == 2 & y ==32	||x == 2 & y ==34	||x == 2 & y ==35	||x == 2 & y ==36	||x == 2 & y ==37	||x == 2 & y ==38	||
		x == 3 & y ==4		||x == 3 & y ==12	||x == 3 & y ==16	||x == 3 & y ==18	||x == 3 & y ==28	||x == 3 & y ==32	||x == 3 & y ==38	||
		x == 4 & y ==1		||x == 4 & y ==2	||x == 4 & y ==4	||x == 4 & y ==5	||x == 4 & y ==6	||x == 4 & y ==7	||x == 4 & y ==8	||x == 4 & y ==9	||x == 4 & y ==10	||x == 4 & y ==11	||x == 4 & y ==12	||x == 4 & y ==14	||x == 4 & y ==15	||x == 4 & y ==16	||x == 4 & y ==18	||x == 4 & y ==19	||x == 4 & y ==20	||x == 4 & y ==21	||x == 4 & y ==22	||x == 4 & y ==23	||x == 4 & y ==24	||x == 4 & y ==25	||x == 4 & y ==26	||x == 4 & y ==27	||x == 4 & y ==28	||x == 4 & y ==30	||x == 4 & y ==31	||x == 4 & y ==32	||x == 4 & y ==33	||x == 4 & y ==34	||x == 4 & y ==35	||x == 4 & y ==36	||x == 4 & y ==38	||
		x == 5 & y==4		||x == 5 & y ==12	||x == 5 & y ==14	||x == 5 & y ==16	||x == 5 & y ==20	||x == 5 & y ==28	||x == 5 & y ==32	||x == 5 & y ==38	||
		x == 6 & y ==2		||x == 6 & y ==3	||x == 6 & y ==4	||x == 6 & y ==6	||x == 6 & y ==7	||x == 6 & y ==8	||x == 6 & y ==9	||x == 6 & y ==10	||x == 6 & y ==12	||x == 6 & y ==14	||x == 6 & y ==16	||x == 6 & y ==17	||x == 6 & y ==18	||x == 6 & y ==20	||x == 6 & y ==22	||x == 6 & y ==23	||x == 6 & y ==24	||x == 6 & y ==25	||x == 6 & y ==26	||x == 6 & y ==28	||x == 6 & y ==29	||x == 6 & y ==30	||x == 6 & y ==32	||x == 6 & y ==34	||x == 6 & y ==35	||x == 6 & y ==36	||x == 6 & y ==37	||x == 6 & y ==38	||
		x == 7 & y ==4		||x == 7 & y ==8	||x == 7 & y ==12	||x == 7 & y ==18	||x == 7 & y ==20	||x == 7 & y ==22	||x == 7 & y ==28	||x == 7 & y ==30	||x == 7 & y ==32	||x == 7 & y ==38	||
		x == 8 & y ==2		||x == 8 & y ==4	||x == 8 & y ==5	||x == 8 & y ==6	||x == 8 & y ==8	||x == 8 & y ==10	||x == 8 & y ==11	||x == 8 & y ==12	||x == 8 & y ==13	||x == 8 & y ==14	||x == 8 & y ==15	||x == 8 & y ==16	||x == 8 & y ==18	||x == 8 & y ==20	||x == 8 & y ==22	||x == 8 & y ==24	||x == 8 & y ==25	||x == 8 & y ==26	||x == 8 & y ==27	||x == 8 & y ==28	||x == 8 & y ==30	||x == 8 & y ==32	||x == 8 & y ==33	||x == 8 & y ==34	||x == 8 & y ==36	||x == 8 & y ==38	||
		x == 9 & y ==2		||x == 9 & y ==6	||x == 9 & y ==8	||x == 9 & y ==16	||x == 9 & y ==18	||x == 9 & y ==22	||x == 9 & y ==26	||x == 9 & y ==30	||x == 9 & y ==36	||
		x == 10 & y ==2		||x == 10 & y ==4	||x == 10 & y ==5	||x == 10 & y ==6	||x == 10 & y ==8	||x == 10 & y ==9	||x == 10 & y ==10	||x == 10 & y ==11	||x == 10 & y ==12	||x == 10 & y ==13	||x == 10 & y ==14	||x == 10 & y ==16	||x == 10 & y ==17	||x == 10 & y ==18	||x == 10 & y ==19	||x == 10 & y ==20	||x == 10 & y ==21	||x == 10 & y ==22	||x == 10 & y ==23	||x == 10 & y ==24	||x == 10 & y ==26	||x == 10 & y ==28	||x == 10 & y ==30	||x == 10 & y ==31	||x == 10 & y ==32	||x == 10 & y ==33	||x == 10 & y ==34	||x == 10 & y ==35	||x == 10 & y ==36	||x == 10 & y ==37	||x == 10 & y ==38	||
		x == 11 & y ==2		||x == 11 & y ==6	||x == 11 & y ==8	||x == 11 & y ==10	||x == 11 & y ==14	||x == 11 & y ==16	||x == 11 & y ==24	||x == 11 & y ==26	||x == 11 & y ==28	||x == 11 & y ==38	||
		x == 12 & y ==2		||x == 12 & y ==3	||x == 12 & y ==4	||x == 12 & y ==6	||x == 12 & y ==8	||x == 12 & y ==10	||x == 12 & y ==12	||x == 12 & y ==14	||x == 12 & y ==16	||x == 12 & y ==18	||x == 12 & y ==19	||x == 12 & y ==20	||x == 12 & y ==21	||x == 12 & y ==22	||x == 12 & y ==24	||x == 12 & y ==26	||x == 12 & y ==28	||x == 12 & y ==29	||x == 12 & y ==30	||x == 12 & y ==31	||x == 12 & y ==32	||x == 12 & y ==34	||x == 12 & y ==35	||x == 12 & y ==36	||x == 12 & y ==37	||x == 12 & y ==38	||
		x == 13 & y ==2		||x == 13 & y ==4	||x == 13 & y ==10	||x == 13 & y ==12	||x == 13 & y ==16	||x == 13 & y ==18	||x == 13 & y ==22	||x == 13 & y ==26	||x == 13 & y ==30	||x == 13 & y ==32	||x == 13 & y ==34	||x == 13 & y ==38	||
		x == 14 & y ==2		||x == 14 & y ==4	||x == 14 & y ==5	||x == 14 & y ==6	||x == 14 & y ==7	||x == 14 & y ==8	||x == 14 & y ==9	||x == 14 & y ==10	||x == 14 & y ==12	||x == 14 & y ==13	||x == 14 & y ==14	||x == 14 & y ==16	||x == 14 & y ==18	||x == 14 & y ==20	||x == 14 & y ==22	||x == 14 & y ==23	||x == 14 & y ==24	||x == 14 & y ==25	||x == 14 & y ==26	||x == 14 & y ==27	||x == 14 & y ==28	||x == 14 & y ==30	||x == 14 & y ==32	||x == 14 & y ==34	||x == 14 & y ==36	||x == 14 & y ==38	||
		x == 15 & y ==2		||x == 15 & y ==6	||x == 15 & y ==12	||x == 15 & y ==14	||x == 15 & y ==16	||x == 15 & y ==20	||x == 15 & y ==26	||x == 15 & y ==30	||x == 15 & y ==32	||x == 15 & y ==36	||x == 15 & y ==38	||
		x == 16 & y ==2		||x == 16 & y ==4	||x == 16 & y ==6	||x == 16 & y ==8	||x == 16 & y ==9	||x == 16 & y ==10	||x == 16 & y ==11	||x == 16 & y ==12	||x == 16 & y ==14	||x == 16 & y ==16	||x == 16 & y ==17	||x == 16 & y ==18	||x == 16 & y ==19	||x == 16 & y ==20	||x == 16 & y ==21	||x == 16 & y ==22	||x == 16 & y ==23	||x == 16 & y ==24	||x == 16 & y ==26	||x == 16 & y ==28	||x == 16 & y ==29	||x == 16 & y ==30	||x == 16 & y ==32	||x == 16 & y ==33	||x == 16 & y ==34	||x == 16 & y ==35	||x == 16 & y ==36	||x == 16 & y ==38	||
		x == 17 & y ==4		||x == 17 & y ==6	||x == 17 & y ==12	||x == 17 & y ==14	||x == 17 & y ==16	||x == 17 & y ==24	||x == 17 & y ==26	||x == 17 & y ==28	||x == 17 & y ==36	||
		x == 18 & y ==1		||x == 18 & y ==2	||x == 18 & y ==3	||x == 18 & y ==4	||x == 18 & y ==5	||x == 18 & y ==6	||x == 18 & y ==8	||x == 18 & y ==9	||x == 18 & y ==10	||x == 18 & y ==12	||x == 18 & y ==14	||x == 18 & y ==16	||x == 18 & y ==17	||x == 18 & y ==18	||x == 18 & y ==19	||x == 18 & y ==20	||x == 18 & y ==22	||x == 18 & y ==24	||x == 18 & y ==26	||x == 18 & y ==28	||x == 18 & y ==29	||x == 18 & y ==30	||x == 18 & y ==31	||x == 18 & y ==32	||x == 18 & y ==34	||x == 18 & y ==35	||x == 18 & y ==36	||x == 18 & y ==37	||x == 18 & y ==38	||x == 18 & y ==39	||
		x == 19 & y ==6		||x == 19 & y ==8	||x == 19 & y ==12	||x == 19 & y ==16	||x == 19 & y ==22	||x == 19 & y ==24	||x == 19 & y ==26	||x == 19 & y ==28	||x == 19 & y ==32	||x == 19 & y ==34	||
		x == 20 & y ==2		||x == 20 & y ==3	||x == 20 & y ==4	||x == 20 & y ==6	||x == 20 & y ==7	||x == 20 & y ==8	||x == 20 & y ==10	||x == 20 & y ==11	||x == 20 & y ==12	||x == 20 & y ==14	||x == 20 & y ==15	||x == 20 & y ==16	||x == 20 & y ==18	||x == 20 & y ==19	||x == 20 & y ==20	||x == 20 & y ==21	||x == 20 & y ==22	||x == 20 & y ==24	||x == 20 & y ==25	||x == 20 & y ==26	||x == 20 & y ==28	||x == 20 & y ==30	||x == 20 & y ==32	||x == 20 & y ==34	||x == 20 & y ==36	||x == 20 & y ==37	||x == 20 & y ==38	||
		x == 21 & y ==2		||x == 21 & y ==8	||x == 21 & y ==10	||x == 21 & y ==12	||x == 21 & y ==18	||x == 21 & y ==26	||x == 21 & y ==30	||x == 21 & y ==32	||x == 21 & y ==38	||
		x == 22 & y ==2		||x == 22 & y ==3	||x == 22 & y ==4	||x == 22 & y ==5	||x == 22 & y ==6	||x == 22 & y ==8	||x == 22 & y ==10	||x == 22 & y ==12	||x == 22 & y ==13	||x == 22 & y ==14	||x == 22 & y ==16	||x == 22 & y ==17	||x == 22 & y ==18	||x == 22 & y ==19	||x == 22 & y ==20	||x == 22 & y ==21	||x == 22 & y ==22	||x == 22 & y ==23	||x == 22 & y ==24	||x == 22 & y ==26	||x == 22 & y ==27	||x == 22 & y ==28	||x == 22 & y ==29	||x == 22 & y ==30	||x == 22 & y ==32	||x == 22 & y ==33	||x == 22 & y ==34	||x == 22 & y ==35	||x == 22 & y ==36	||x == 22 & y ==37	||x == 22 & y ==38	||
		x == 23 & y ==2		||x == 23 & y ==6	||x == 23 & y ==10	||x == 23 & y ==14	||x == 23 & y ==16	||x == 23 & y ==22	||x == 23 & y ==26	||x == 23 & y ==30	||x == 23 & y ==38	||
		x == 24 & y ==2		||x == 24 & y ==4	||x == 24 & y ==6	||x == 24 & y ==7	||x == 24 & y ==8	||x == 24 & y ==9	||x == 24 & y ==10	||x == 24 & y ==12	||x == 24 & y ==14	||x == 24 & y ==16	||x == 24 & y ==18	||x == 24 & y ==19	||x == 24 & y ==20	||x == 24 & y ==22	||x == 24 & y ==23	||x == 24 & y ==24	||x == 24 & y ==26	||x == 24 & y ==28	||x == 24 & y ==30	||x == 24 & y ==31	||x == 24 & y ==32	||x == 24 & y ==33	||x == 24 & y ==34	||x == 24 & y ==35	||x == 24 & y ==36	||
		x == 25 & y ==2		||x == 25 & y ==4	||x == 25 & y == 8	||x == 25 & y == 12	|| x == 25 & y == 16|| x == 25 & y == 20|| x == 25 & y == 24|| x == 25 & y == 26|| x == 25 & y == 28|| x == 25 & y == 34|| x == 25 & y == 36||
		x == 26 & y==2		||x == 26 & y ==4	||x == 26 & y ==5	||x == 26 & y ==6	||x == 26 & y ==8	||x == 26 & y ==10	||x == 26 & y ==11	||x == 26 & y ==12	||x == 26 & y ==13	||x == 26 & y ==14	||x == 26 & y ==15	||x == 26 & y ==16	||x == 26 & y ==18	||x == 26 & y ==19	||x == 26 & y ==20	||x == 26 & y ==21	||x == 26 & y ==22	||x == 26 & y ==24	||x == 26 & y ==26	||x == 26 & y ==27	||x == 26 & y ==28	||x == 26 & y ==29	||x == 26 & y ==30	||x == 26 & y ==32	||x == 26 & y ==34	||x == 26 & y ==36	||x == 26 & y ==37	||x == 26 & y ==38	||
		x == 27 & y==4		||x == 27 & y ==8	||x == 27 & y ==10	||x == 27 & y ==18	||x == 27 & y ==24	||x == 27 & y ==32	||x == 27 & y ==38	||
		x == 28 & y==1||x == 28 & y ==2||x == 28 & y ==3||x == 28 & y ==4||x == 28 & y ==6||x == 28 & y ==8||x == 28 & y ==9||x == 28 & y ==10||x == 28 & y ==12||x == 28 & y ==13||x == 28 & y ==14||x == 28 & y ==15||x == 28 & y ==16||x == 28 & y ==17||x == 28 & y ==18||x == 28 & y ==20||x == 28 & y ==21||x == 28 & y ==22||x == 28 & y ==23||x == 28 & y ==24||x == 28 & y ==25||x == 28 & y ==26||x == 28 & y ==27||x == 28 & y ==28||x == 28 & y ==29||x == 28 & y ==30||x == 28 & y ==31||x == 28 & y ==32||x == 28 & y ==33||x == 28 & y ==34||x == 28 & y ==35||x == 28 & y ==36||x == 28 & y ==37||x == 28 & y ==38||
		x == 29 & y==6||x == 29 & y ==8||x == 29 & y ==12||x == 29 & y ==16||x == 29 & y ==20||x == 29 & y ==26||x == 29 & y ==30||
		x == 30 & y==2||x == 30 & y ==3||x == 30 & y ==4||x == 30 & y ==6||x == 30 & y ==7||x == 30 & y ==8||x == 30 & y ==10||x == 30 & y ==11||x == 30 & y ==12||x == 30 & y ==13||x == 30 & y ==14||x == 30 & y ==16||x == 30 & y ==18||x == 30 & y ==19||x == 30 & y ==20||x == 30 & y ==22||x == 30 & y ==23||x == 30 & y ==24||x == 30 & y ==26||x == 30 & y ==28||x == 30 & y ==30||x == 30 & y ==32||x == 30 & y ==33||x == 30 & y ==34||x == 30 & y ==35||x == 30 & y ==36||x == 30 & y ==37||x == 30 & y ==38||x == 30 & y ==39||
		x == 31 & y ==4||x == 31 & y ==6||x == 31 & y ==10||x == 31 & y ==16||x == 31 & y ==20||x == 31 & y ==24||x == 31 & y ==28||x == 31 & y ==32||x == 31 & y ==38||
		x == 32 & y ==1||x == 32 & y ==2||x == 32 & y ==4||x == 32 & y ==6||x == 32 & y ==8||x == 32 & y ==9||x == 32 & y ==10||x == 32 & y ==12||x == 32 & y ==13||x == 32 & y ==14||x == 32 & y ==15||x == 32 & y ==16||x == 32 & y ==17||x == 32 & y ==18||x == 32 & y ==20||x == 32 & y ==21||x == 32 & y ==22||x == 32 & y ==24||x == 32 & y ==25||x == 32 & y ==26||x == 32 & y ==27||x == 32 & y ==28||x == 32 & y ==29||x == 32 & y ==30||x == 32 & y ==31||x == 32 & y ==32||x == 32 & y ==33||x == 32 & y ==34||x == 32 & y ==36||x == 32 & y ==38||
		x == 33 & y ==4||x == 33 & y ==6||x == 33 & y ==8||x == 33 & y ==14||x == 33 & y ==20||x == 33 & y ==24||x == 33 & y ==30||x == 33 & y ==36||x == 33 & y ==38||
		x == 34 & y ==2||x == 34 & y ==3||x == 34 & y ==4||x == 34 & y ==6||x == 34 & y ==8||x == 34 & y ==10||x == 34 & y ==11||x == 34 & y ==12||x == 34 & y ==14||x == 34 & y ==16||x == 34 & y ==17||x == 34 & y ==18||x == 34 & y ==19||x == 34 & y ==20||x == 34 & y ==22||x == 34 & y ==23||x == 34 & y ==24||x == 34 & y ==26||x == 34 & y ==28||x == 34 & y ==30||x == 34 & y ==32||x == 34 & y ==33||x == 34 & y ==34||x == 34 & y ==35||x == 34 & y ==36||x == 34 & y ==38||
		x == 35 & y ==2||x == 35 & y ==6||x == 35 & y ==8||x == 35 & y ==12||x == 35 & y ==14||x == 35 & y ==22||x == 35 & y ==26||x == 35 & y ==28||x == 35 & y ==32||x == 35 & y ==35||x == 35 & y ==38||
		x == 36 & y ==2||x == 36 & y ==3||x == 36 & y ==4||x == 36 & y ==5||x == 36 & y ==6||x == 36 & y ==8||x == 36 & y ==9||x == 36 & y ==10||x == 36 & y ==11||x == 36 & y ==12||x == 36 & y ==14||x == 36 & y ==15||x == 36 & y ==16||x == 36 & y ==17||x == 36 & y ==18||x == 36 & y ==19||x == 36 & y ==20||x == 36 & y ==21||x == 36 & y ==22||x == 36 & y ==23||x == 36 & y ==24||x == 36 & y ==26||x == 36 & y ==28||x == 36 & y ==29||x == 36 & y ==30||x == 36 & y ==31||x == 36 & y ==32||x == 36 & y ==34||x == 36 & y ==36||x == 36 & y ==38||
		x == 37 & y ==4||x == 37 & y ==8||x == 37 & y ==18||x == 37 & y ==24||x == 37 & y ==26||x == 37 & y ==30||x == 37 & y ==34||x == 37 & y ==36||
		x == 38 & y ==2||x == 38 & y ==4||x == 38 & y ==6||x == 38 & y ==7||x == 38 & y ==8||x == 38 & y ==10||x == 38 & y ==11||x == 38 & y ==12||x == 38 & y ==13||x == 38 & y ==14||x == 38 & y ==15||x == 38 & y ==16||x == 38 & y ==18||x == 38 & y ==19||x == 38 & y ==20||x == 38 & y ==22||x == 38 & y ==24||x == 38 & y ==25||x == 38 & y ==26||x == 38 & y ==27||x == 38 & y ==28||x == 38 & y ==30||x == 38 & y ==32||x == 38 & y ==34||x == 38 & y ==36||x == 38 & y ==37||x == 38 & y ==38||
		x == 39 & y ==2||x == 39 & y ==10||x == 39 & y ==22||x == 39 & y ==30||x == 39 & y ==32)

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
	exitX = 39;
	exitY = 1;

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
	if (posX == 0 || posX == mazeX - 1 || posY == 0 || posY == mazeY - 1 || 
		posX == 1 & posY == 8 || posX == 1 & posY == 16 || posX == 1 & posY == 26 || posX == 1 & posY == 32 ||
		posX == 2 & posY == 2 || posX == 2 & posY == 3 || posX == 2 & posY == 4 || posX == 2 & posY == 5 || posX == 2 & posY == 6 || posX == 2 & posY == 8 || posX == 2 & posY == 9 || posX == 2 & posY == 10 || posX == 2 & posY == 12 || posX == 2 & posY == 13 || posX == 2 & posY == 14 || posX == 2 & posY == 16 || posX == 2 & posY == 18 || posX == 2 & posY == 19 || posX == 2 & posY == 20 || posX == 2 & posY == 21 || posX == 2 & posY == 22 || posX == 2 & posY == 23 || posX == 2 & posY == 24 || posX == 2 & posY == 26 || posX == 2 & posY == 28 || posX == 2 & posY == 29 || posX == 2 & posY == 30 || posX == 2 & posY == 32 || posX == 2 & posY == 34 || posX == 2 & posY == 35 || posX == 2 & posY == 36 || posX == 2 & posY == 37 || posX == 2 & posY == 38 ||
		posX == 3 & posY == 4 || posX == 3 & posY == 12 || posX == 3 & posY == 16 || posX == 3 & posY == 18 || posX == 3 & posY == 28 || posX == 3 & posY == 32 || posX == 3 & posY == 38 ||
		posX == 4 & posY == 1 || posX == 4 & posY == 2 || posX == 4 & posY == 4 || posX == 4 & posY == 5 || posX == 4 & posY == 6 || posX == 4 & posY == 7 || posX == 4 & posY == 8 || posX == 4 & posY == 9 || posX == 4 & posY == 10 || posX == 4 & posY == 11 || posX == 4 & posY == 12 || posX == 4 & posY == 14 || posX == 4 & posY == 15 || posX == 4 & posY == 16 || posX == 4 & posY == 18 || posX == 4 & posY == 19 || posX == 4 & posY == 20 || posX == 4 & posY == 21 || posX == 4 & posY == 22 || posX == 4 & posY == 23 || posX == 4 & posY == 24 || posX == 4 & posY == 25 || posX == 4 & posY == 26 || posX == 4 & posY == 27 || posX == 4 & posY == 28 || posX == 4 & posY == 30 || posX == 4 & posY == 31 || posX == 4 & posY == 32 || posX == 4 & posY == 33 || posX == 4 & posY == 34 || posX == 4 & posY == 35 || posX == 4 & posY == 36 || posX == 4 & posY == 38 ||
		posX == 5 & posY == 4 || posX == 5 & posY == 12 || posX == 5 & posY == 14 || posX == 5 & posY == 16 || posX == 5 & posY == 20 || posX == 5 & posY == 28 || posX == 5 & posY == 32 || posX == 5 & posY == 38 ||
		posX == 6 & posY == 2 || posX == 6 & posY == 3 || posX == 6 & posY == 4 || posX == 6 & posY == 6 || posX == 6 & posY == 7 || posX == 6 & posY == 8 || posX == 6 & posY == 9 || posX == 6 & posY == 10 || posX == 6 & posY == 12 || posX == 6 & posY == 14 || posX == 6 & posY == 16 || posX == 6 & posY == 17 || posX == 6 & posY == 18 || posX == 6 & posY == 20 || posX == 6 & posY == 22 || posX == 6 & posY == 23 || posX == 6 & posY == 24 || posX == 6 & posY == 25 || posX == 6 & posY == 26 || posX == 6 & posY == 28 || posX == 6 & posY == 29 || posX == 6 & posY == 30 || posX == 6 & posY == 32 || posX == 6 & posY == 34 || posX == 6 & posY == 35 || posX == 6 & posY == 36 || posX == 6 & posY == 37 || posX == 6 & posY == 38 ||
		posX == 7 & posY == 4 || posX == 7 & posY == 8 || posX == 7 & posY == 12 || posX == 7 & posY == 18 || posX == 7 & posY == 20 || posX == 7 & posY == 22 || posX == 7 & posY == 28 || posX == 7 & posY == 30 || posX == 7 & posY == 32 || posX == 7 & posY == 38 ||
		posX == 8 & posY == 2 || posX == 8 & posY == 4 || posX == 8 & posY == 5 || posX == 8 & posY == 6 || posX == 8 & posY == 8 || posX == 8 & posY == 10 || posX == 8 & posY == 11 || posX == 8 & posY == 12 || posX == 8 & posY == 13 || posX == 8 & posY == 14 || posX == 8 & posY == 15 || posX == 8 & posY == 16 || posX == 8 & posY == 18 || posX == 8 & posY == 20 || posX == 8 & posY == 22 || posX == 8 & posY == 24 || posX == 8 & posY == 25 || posX == 8 & posY == 26 || posX == 8 & posY == 27 || posX == 8 & posY == 28 || posX == 8 & posY == 30 || posX == 8 & posY == 32 || posX == 8 & posY == 33 || posX == 8 & posY == 34 || posX == 8 & posY == 36 || posX == 8 & posY == 38 ||
		posX == 9 & posY == 2 || posX == 9 & posY == 6 || posX == 9 & posY == 8 || posX == 9 & posY == 16 || posX == 9 & posY == 18 || posX == 9 & posY == 22 || posX == 9 & posY == 26 || posX == 9 & posY == 30 || posX == 9 & posY == 36 ||
		posX == 10 & posY == 2 || posX == 10 & posY == 4 || posX == 10 & posY == 5 || posX == 10 & posY == 6 || posX == 10 & posY == 8 || posX == 10 & posY == 9 || posX == 10 & posY == 10 || posX == 10 & posY == 11 || posX == 10 & posY == 12 || posX == 10 & posY == 13 || posX == 10 & posY == 14 || posX == 10 & posY == 16 || posX == 10 & posY == 17 || posX == 10 & posY == 18 || posX == 10 & posY == 19 || posX == 10 & posY == 20 || posX == 10 & posY == 21 || posX == 10 & posY == 22 || posX == 10 & posY == 23 || posX == 10 & posY == 24 || posX == 10 & posY == 26 || posX == 10 & posY == 28 || posX == 10 & posY == 30 || posX == 10 & posY == 31 || posX == 10 & posY == 32 || posX == 10 & posY == 33 || posX == 10 & posY == 34 || posX == 10 & posY == 35 || posX == 10 & posY == 36 || posX == 10 & posY == 37 || posX == 10 & posY == 38 ||
		posX == 11 & posY == 2 || posX == 11 & posY == 6 || posX == 11 & posY == 8 || posX == 11 & posY == 10 || posX == 11 & posY == 14 || posX == 11 & posY == 16 || posX == 11 & posY == 24 || posX == 11 & posY == 26 || posX == 11 & posY == 28 || posX == 11 & posY == 38 ||
		posX == 12 & posY == 2 || posX == 12 & posY == 3 || posX == 12 & posY == 4 || posX == 12 & posY == 6 || posX == 12 & posY == 8 || posX == 12 & posY == 10 || posX == 12 & posY == 12 || posX == 12 & posY == 14 || posX == 12 & posY == 16 || posX == 12 & posY == 18 || posX == 12 & posY == 19 || posX == 12 & posY == 20 || posX == 12 & posY == 21 || posX == 12 & posY == 22 || posX == 12 & posY == 24 || posX == 12 & posY == 26 || posX == 12 & posY == 28 || posX == 12 & posY == 29 || posX == 12 & posY == 30 || posX == 12 & posY == 31 || posX == 12 & posY == 32 || posX == 12 & posY == 34 || posX == 12 & posY == 35 || posX == 12 & posY == 36 || posX == 12 & posY == 37 || posX == 12 & posY == 38 ||
		posX == 13 & posY == 2 || posX == 13 & posY == 4 || posX == 13 & posY == 10 || posX == 13 & posY == 12 || posX == 13 & posY == 16 || posX == 13 & posY == 18 || posX == 13 & posY == 22 || posX == 13 & posY == 26 || posX == 13 & posY == 30 || posX == 13 & posY == 32 || posX == 13 & posY == 34 || posX == 13 & posY == 38 ||
		posX == 14 & posY == 2 || posX == 14 & posY == 4 || posX == 14 & posY == 5 || posX == 14 & posY == 6 || posX == 14 & posY == 7 || posX == 14 & posY == 8 || posX == 14 & posY == 9 || posX == 14 & posY == 10 || posX == 14 & posY == 12 || posX == 14 & posY == 13 || posX == 14 & posY == 14 || posX == 14 & posY == 16 || posX == 14 & posY == 18 || posX == 14 & posY == 20 || posX == 14 & posY == 22 || posX == 14 & posY == 23 || posX == 14 & posY == 24 || posX == 14 & posY == 25 || posX == 14 & posY == 26 || posX == 14 & posY == 27 || posX == 14 & posY == 28 || posX == 14 & posY == 30 || posX == 14 & posY == 32 || posX == 14 & posY == 34 || posX == 14 & posY == 36 || posX == 14 & posY == 38 ||
		posX == 15 & posY == 2 || posX == 15 & posY == 6 || posX == 15 & posY == 12 || posX == 15 & posY == 14 || posX == 15 & posY == 16 || posX == 15 & posY == 20 || posX == 15 & posY == 26 || posX == 15 & posY == 30 || posX == 15 & posY == 32 || posX == 15 & posY == 36 || posX == 15 & posY == 38 ||
		posX == 16 & posY == 2 || posX == 16 & posY == 4 || posX == 16 & posY == 6 || posX == 16 & posY == 8 || posX == 16 & posY == 9 || posX == 16 & posY == 10 || posX == 16 & posY == 11 || posX == 16 & posY == 12 || posX == 16 & posY == 14 || posX == 16 & posY == 16 || posX == 16 & posY == 17 || posX == 16 & posY == 18 || posX == 16 & posY == 19 || posX == 16 & posY == 20 || posX == 16 & posY == 21 || posX == 16 & posY == 22 || posX == 16 & posY == 23 || posX == 16 & posY == 24 || posX == 16 & posY == 26 || posX == 16 & posY == 28 || posX == 16 & posY == 29 || posX == 16 & posY == 30 || posX == 16 & posY == 32 || posX == 16 & posY == 33 || posX == 16 & posY == 34 || posX == 16 & posY == 35 || posX == 16 & posY == 36 || posX == 16 & posY == 38 ||
		posX == 17 & posY == 4 || posX == 17 & posY == 6 || posX == 17 & posY == 12 || posX == 17 & posY == 14 || posX == 17 & posY == 16 || posX == 17 & posY == 24 || posX == 17 & posY == 26 || posX == 17 & posY == 28 || posX == 17 & posY == 36 ||
		posX == 18 & posY == 1 || posX == 18 & posY == 2 || posX == 18 & posY == 3 || posX == 18 & posY == 4 || posX == 18 & posY == 5 || posX == 18 & posY == 6 || posX == 18 & posY == 8 || posX == 18 & posY == 9 || posX == 18 & posY == 10 || posX == 18 & posY == 12 || posX == 18 & posY == 14 || posX == 18 & posY == 16 || posX == 18 & posY == 17 || posX == 18 & posY == 18 || posX == 18 & posY == 19 || posX == 18 & posY == 20 || posX == 18 & posY == 22 || posX == 18 & posY == 24 || posX == 18 & posY == 26 || posX == 18 & posY == 28 || posX == 18 & posY == 29 || posX == 18 & posY == 30 || posX == 18 & posY == 31 || posX == 18 & posY == 32 || posX == 18 & posY == 34 || posX == 18 & posY == 35 || posX == 18 & posY == 36 || posX == 18 & posY == 37 || posX == 18 & posY == 38 || posX == 18 & posY == 39 ||
		posX == 19 & posY == 6 || posX == 19 & posY == 8 || posX == 19 & posY == 12 || posX == 19 & posY == 16 || posX == 19 & posY == 22 || posX == 19 & posY == 24 || posX == 19 & posY == 26 || posX == 19 & posY == 28 || posX == 19 & posY == 32 || posX == 19 & posY == 34 ||
		posX == 20 & posY == 2 || posX == 20 & posY == 3 || posX == 20 & posY == 4 || posX == 20 & posY == 6 || posX == 20 & posY == 7 || posX == 20 & posY == 8 || posX == 20 & posY == 10 || posX == 20 & posY == 11 || posX == 20 & posY == 12 || posX == 20 & posY == 14 || posX == 20 & posY == 15 || posX == 20 & posY == 16 || posX == 20 & posY == 18 || posX == 20 & posY == 19 || posX == 20 & posY == 20 || posX == 20 & posY == 21 || posX == 20 & posY == 22 || posX == 20 & posY == 24 || posX == 20 & posY == 25 || posX == 20 & posY == 26 || posX == 20 & posY == 28 || posX == 20 & posY == 30 || posX == 20 & posY == 32 || posX == 20 & posY == 34 || posX == 20 & posY == 36 || posX == 20 & posY == 37 || posX == 20 & posY == 38 ||
		posX == 21 & posY == 2 || posX == 21 & posY == 8 || posX == 21 & posY == 10 || posX == 21 & posY == 12 || posX == 21 & posY == 18 || posX == 21 & posY == 26 || posX == 21 & posY == 30 || posX == 21 & posY == 32 || posX == 21 & posY == 38 ||
		posX == 22 & posY == 2 || posX == 22 & posY == 3 || posX == 22 & posY == 4 || posX == 22 & posY == 5 || posX == 22 & posY == 6 || posX == 22 & posY == 8 || posX == 22 & posY == 10 || posX == 22 & posY == 12 || posX == 22 & posY == 13 || posX == 22 & posY == 14 || posX == 22 & posY == 16 || posX == 22 & posY == 17 || posX == 22 & posY == 18 || posX == 22 & posY == 19 || posX == 22 & posY == 20 || posX == 22 & posY == 21 || posX == 22 & posY == 22 || posX == 22 & posY == 23 || posX == 22 & posY == 24 || posX == 22 & posY == 26 || posX == 22 & posY == 27 || posX == 22 & posY == 28 || posX == 22 & posY == 29 || posX == 22 & posY == 30 || posX == 22 & posY == 32 || posX == 22 & posY == 33 || posX == 22 & posY == 34 || posX == 22 & posY == 35 || posX == 22 & posY == 36 || posX == 22 & posY == 37 || posX == 22 & posY == 38 ||
		posX == 23 & posY == 2 || posX == 23 & posY == 6 || posX == 23 & posY == 10 || posX == 23 & posY == 14 || posX == 23 & posY == 16 || posX == 23 & posY == 22 || posX == 23 & posY == 26 || posX == 23 & posY == 30 || posX == 23 & posY == 38 ||
		posX == 24 & posY == 2 || posX == 24 & posY == 4 || posX == 24 & posY == 6 || posX == 24 & posY == 7 || posX == 24 & posY == 8 || posX == 24 & posY == 9 || posX == 24 & posY == 10 || posX == 24 & posY == 12 || posX == 24 & posY == 14 || posX == 24 & posY == 16 || posX == 24 & posY == 18 || posX == 24 & posY == 19 || posX == 24 & posY == 20 || posX == 24 & posY == 22 || posX == 24 & posY == 23 || posX == 24 & posY == 24 || posX == 24 & posY == 26 || posX == 24 & posY == 28 || posX == 24 & posY == 30 || posX == 24 & posY == 31 || posX == 24 & posY == 32 || posX == 24 & posY == 33 || posX == 24 & posY == 34 || posX == 24 & posY == 35 || posX == 24 & posY == 36 ||
		posX == 25 & posY == 2 || posX == 25 & posY == 4 || posX == 25 & posY == 8 || posX == 25 & posY == 12 || posX == 25 & posY == 16 || posX == 25 & posY == 20 || posX == 25 & posY == 24 || posX == 25 & posY == 26 || posX == 25 & posY == 28 || posX == 25 & posY == 34 || posX == 25 & posY == 36 ||
		posX == 26 & posY == 2 || posX == 26 & posY == 4 || posX == 26 & posY == 5 || posX == 26 & posY == 6 || posX == 26 & posY == 8 || posX == 26 & posY == 10 || posX == 26 & posY == 11 || posX == 26 & posY == 12 || posX == 26 & posY == 13 || posX == 26 & posY == 14 || posX == 26 & posY == 15 || posX == 26 & posY == 16 || posX == 26 & posY == 18 || posX == 26 & posY == 19 || posX == 26 & posY == 20 || posX == 26 & posY == 21 || posX == 26 & posY == 22 || posX == 26 & posY == 24 || posX == 26 & posY == 26 || posX == 26 & posY == 27 || posX == 26 & posY == 28 || posX == 26 & posY == 29 || posX == 26 & posY == 30 || posX == 26 & posY == 32 || posX == 26 & posY == 34 || posX == 26 & posY == 36 || posX == 26 & posY == 37 || posX == 26 & posY == 38 ||
		posX == 27 & posY == 4 || posX == 27 & posY == 8 || posX == 27 & posY == 10 || posX == 27 & posY == 18 || posX == 27 & posY == 24 || posX == 27 & posY == 32 || posX == 27 & posY == 38 ||
		posX == 28 & posY == 1 || posX == 28 & posY == 2 || posX == 28 & posY == 3 || posX == 28 & posY == 4 || posX == 28 & posY == 6 || posX == 28 & posY == 8 || posX == 28 & posY == 9 || posX == 28 & posY == 10 || posX == 28 & posY == 12 || posX == 28 & posY == 13 || posX == 28 & posY == 14 || posX == 28 & posY == 15 || posX == 28 & posY == 16 || posX == 28 & posY == 17 || posX == 28 & posY == 18 || posX == 28 & posY == 20 || posX == 28 & posY == 21 || posX == 28 & posY == 22 || posX == 28 & posY == 23 || posX == 28 & posY == 24 || posX == 28 & posY == 25 || posX == 28 & posY == 26 || posX == 28 & posY == 27 || posX == 28 & posY == 28 || posX == 28 & posY == 29 || posX == 28 & posY == 30 || posX == 28 & posY == 31 || posX == 28 & posY == 32 || posX == 28 & posY == 33 || posX == 28 & posY == 34 || posX == 28 & posY == 35 || posX == 28 & posY == 36 || posX == 28 & posY == 37 || posX == 28 & posY == 38 ||
		posX == 29 & posY == 6 || posX == 29 & posY == 8 || posX == 29 & posY == 12 || posX == 29 & posY == 16 || posX == 29 & posY == 20 || posX == 29 & posY == 26 || posX == 29 & posY == 30 ||
		posX == 30 & posY == 2 || posX == 30 & posY == 3 || posX == 30 & posY == 4 || posX == 30 & posY == 6 || posX == 30 & posY == 7 || posX == 30 & posY == 8 || posX == 30 & posY == 10 || posX == 30 & posY == 11 || posX == 30 & posY == 12 || posX == 30 & posY == 13 || posX == 30 & posY == 14 || posX == 30 & posY == 16 || posX == 30 & posY == 18 || posX == 30 & posY == 19 || posX == 30 & posY == 20 || posX == 30 & posY == 22 || posX == 30 & posY == 23 || posX == 30 & posY == 24 || posX == 30 & posY == 26 || posX == 30 & posY == 28 || posX == 30 & posY == 30 || posX == 30 & posY == 32 || posX == 30 & posY == 33 || posX == 30 & posY == 34 || posX == 30 & posY == 35 || posX == 30 & posY == 36 || posX == 30 & posY == 37 || posX == 30 & posY == 38 || posX == 30 & posY == 39 ||
		posX == 31 & posY == 4 || posX == 31 & posY == 6 || posX == 31 & posY == 10 || posX == 31 & posY == 16 || posX == 31 & posY == 20 || posX == 31 & posY == 24 || posX == 31 & posY == 28 || posX == 31 & posY == 32 || posX == 31 & posY == 38 ||
		posX == 32 & posY == 1 || posX == 32 & posY == 2 || posX == 32 & posY == 4 || posX == 32 & posY == 6 || posX == 32 & posY == 8 || posX == 32 & posY == 9 || posX == 32 & posY == 10 || posX == 32 & posY == 12 || posX == 32 & posY == 13 || posX == 32 & posY == 14 || posX == 32 & posY == 15 || posX == 32 & posY == 16 || posX == 32 & posY == 17 || posX == 32 & posY == 18 || posX == 32 & posY == 20 || posX == 32 & posY == 21 || posX == 32 & posY == 22 || posX == 32 & posY == 24 || posX == 32 & posY == 25 || posX == 32 & posY == 26 || posX == 32 & posY == 27 || posX == 32 & posY == 28 || posX == 32 & posY == 29 || posX == 32 & posY == 30 || posX == 32 & posY == 31 || posX == 32 & posY == 32 || posX == 32 & posY == 33 || posX == 32 & posY == 34 || posX == 32 & posY == 36 || posX == 32 & posY == 38 ||
		posX == 33 & posY == 4 || posX == 33 & posY == 6 || posX == 33 & posY == 8 || posX == 33 & posY == 14 || posX == 33 & posY == 20 || posX == 33 & posY == 24 || posX == 33 & posY == 30 || posX == 33 & posY == 36 || posX == 33 & posY == 38 ||
		posX == 34 & posY == 2 || posX == 34 & posY == 3 || posX == 34 & posY == 4 || posX == 34 & posY == 6 || posX == 34 & posY == 8 || posX == 34 & posY == 10 || posX == 34 & posY == 11 || posX == 34 & posY == 12 || posX == 34 & posY == 14 || posX == 34 & posY == 16 || posX == 34 & posY == 17 || posX == 34 & posY == 18 || posX == 34 & posY == 19 || posX == 34 & posY == 20 || posX == 34 & posY == 22 || posX == 34 & posY == 23 || posX == 34 & posY == 24 || posX == 34 & posY == 26 || posX == 34 & posY == 28 || posX == 34 & posY == 30 || posX == 34 & posY == 32 || posX == 34 & posY == 33 || posX == 34 & posY == 34 || posX == 34 & posY == 35 || posX == 34 & posY == 36 || posX == 34 & posY == 38 ||
		posX == 35 & posY == 2 || posX == 35 & posY == 6 || posX == 35 & posY == 8 || posX == 35 & posY == 12 || posX == 35 & posY == 14 || posX == 35 & posY == 22 || posX == 35 & posY == 26 || posX == 35 & posY == 28 || posX == 35 & posY == 32 || posX == 35 & posY == 35 || posX == 35 & posY == 38 ||
		posX == 36 & posY == 2 || posX == 36 & posY == 3 || posX == 36 & posY == 4 || posX == 36 & posY == 5 || posX == 36 & posY == 6 || posX == 36 & posY == 8 || posX == 36 & posY == 9 || posX == 36 & posY == 10 || posX == 36 & posY == 11 || posX == 36 & posY == 12 || posX == 36 & posY == 14 || posX == 36 & posY == 15 || posX == 36 & posY == 16 || posX == 36 & posY == 17 || posX == 36 & posY == 18 || posX == 36 & posY == 19 || posX == 36 & posY == 20 || posX == 36 & posY == 21 || posX == 36 & posY == 22 || posX == 36 & posY == 23 || posX == 36 & posY == 24 || posX == 36 & posY == 26 || posX == 36 & posY == 28 || posX == 36 & posY == 29 || posX == 36 & posY == 30 || posX == 36 & posY == 31 || posX == 36 & posY == 32 || posX == 36 & posY == 34 || posX == 36 & posY == 36 || posX == 36 & posY == 38 ||
		posX == 37 & posY == 4 || posX == 37 & posY == 8 || posX == 37 & posY == 18 || posX == 37 & posY == 24 || posX == 37 & posY == 26 || posX == 37 & posY == 30 || posX == 37 & posY == 34 || posX == 37 & posY == 36 ||
		posX == 38 & posY == 2 || posX == 38 & posY == 4 || posX == 38 & posY == 6 || posX == 38 & posY == 7 || posX == 38 & posY == 8 || posX == 38 & posY == 10 || posX == 38 & posY == 11 || posX == 38 & posY == 12 || posX == 38 & posY == 13 || posX == 38 & posY == 14 || posX == 38 & posY == 15 || posX == 38 & posY == 16 || posX == 38 & posY == 18 || posX == 38 & posY == 19 || posX == 38 & posY == 20 || posX == 38 & posY == 22 || posX == 38 & posY == 24 || posX == 38 & posY == 25 || posX == 38 & posY == 26 || posX == 38 & posY == 27 || posX == 38 & posY == 28 || posX == 38 & posY == 30 || posX == 38 & posY == 32 || posX == 38 & posY == 34 || posX == 38 & posY == 36 || posX == 38 & posY == 37 || posX == 38 & posY == 38 ||
		posX == 39 & posY == 2 || posX == 39 & posY == 10 || posX == 39 & posY == 22 || posX == 39 & posY == 30 || posX == 39 & posY == 32)
	{
		gameover = true;
	}

	if (posX == exitX && posY == exitY)
	{
		foundExit = true;
	}
	
}