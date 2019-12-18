#pragma once
#include <GL/freeglut.h>
#include "Glm/glm.h"
#include <cmath>
#include "Car.h"
#include "Road.h"
#include "Camera.h"
#define ATOR(x) x * M_PI/180.0f

extern Car *porsche;
extern Road *road;
extern Camera *camera;

void GameLoop(int);
void StartGame();
void Draw();
void SpecialKeys(int, int, int);
void mouseButton(int, int, int, int);
void mouseMove(int, int);