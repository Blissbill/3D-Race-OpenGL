#include "InitGame.h"
#include "Game.h"
#include "GL/freeglut.h"

int main(int argc, char **argv)
{
	InitGame(argc, argv);
	StartGame();
	glutMainLoop();
}
