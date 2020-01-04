## Maze Game
#### SOFT356 Coursework 2 - Maze Game

#### How does the user interact with your executable? How do you open and control the software you wrote (exe file)?
The user interacts with my game by using keyboard and mouse input.

The arrow keys are used to move the character up, down, left and right. Where as the mouse is used to open a config menu
which allows the user to change the speed their character is moving.

#### How does the program code work? How do the classes and functions fit together and who does what?
My code is made up from 3 different files. I have my main CPP file which handles the creation of the program and it's
relevant windows, and then I have my maze CPP and H files which contains all the "game" code such as the initialisation
of the maze and different events in the maze such as exit and character spawning.

I have used the GLUT library to create the game. So in my Main.cpp file I create a GLUT window with all the defined
properties like the width, height etc. I then have some other functions which manage other events such as the menu that
can be shown with a Right-Click of the mouse, and the timer function which counts the seconds it takes for the user to 
complete the maze. I have also included the keyboard input in my Main.cpp.

In my Maze.cpp and H file I have defined functions that run events such as defining the maze size, drawing the maze 
co-ordinates, setting the colours for the character, walls and exit, as well as drawing the positions of them all as well.

I have also added sound effects and background music to try and make the game feel nostalgic. I used the irrKlang library to add the different effects when you either win or die. I have also added some 8-bit background music for the user to listen too whilst navigating the maze.

#### What makes your program special and how does it compare to similar things? (Where did you get the idea from? What did you start with? How did you make yours unique? Did you start with a given project?)
I think my program is unique in the sense that it is incredibly difficult to complete and doesn't allow room for error.
To be able to "win" in my game you have to be very precise and patient to be able to navigate the maze. I had the idea 
of creating a maze game as soon as I read the coursework spec, but I wanted to make it different to the bog standard 
maze games that others have created. So I did. By making the character continuously move in a specified direction I feel
it added a more intense way to play, as you knew the character was never going to stop so you had to be ready at all times
to change direction. I thought about older 8-bit games that I used to play when I was younger and Snake was what gave me
the idea to add the continuous movement.

I started from scratch and used various sources on Stack Overflow to help me achieve my final product.

#### Video Report Link
https://youtu.be/vXfGI0pavQ0


