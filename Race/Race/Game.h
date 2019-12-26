#pragma once
#include "GL/freeglut.h"
#include "Glm/glm.h"
#include "Car.h"
#include "Road.h"
#include <cstdio>

void GameLoop(int);
void StartGame();
void Draw();
void DrawSky();
void DrawEarth();
void SpecialKeys(int, int, int);
void SpecialKeysUp(int, int, int);
void UpdatePosition();
void glutPrint(float, float, LPVOID, char*, float, float, float, float);
void RenderScore();
void DrawGameOver();
void NewGame();
void processNormalKeys(unsigned char, int, int);
void DrawMenu();