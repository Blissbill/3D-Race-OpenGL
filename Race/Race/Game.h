#pragma once
#include <GL/freeglut.h>
#include "Glm/glm.h"
#include "Car.h"
#include "Road.h"
#include "Camera.h"

void GameLoop(int);
void StartGame();
void Draw();
void DrawSky();
void DrawEarth();
void SpecialKeys(int, int, int);
void mouseButton(int, int, int, int);
void mouseMove(int, int);