#define _CRT_SECURE_NO_WARNINGS
#include "InitGame.h"
#include "Game.h"
#include "GL/freeglut.h"
#include "Road.h"

Car *porsche;
Road *road;

void draw();
int main(int argc, char **argv)
{
	InitGame(argc, argv);
	StartGame();
	glutMainLoop();
}
