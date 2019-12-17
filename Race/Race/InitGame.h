#pragma once
#include "GL/freeglut.h"
#include "SOIL/SOIL.h"
#include "Glm/glm.h"
#include "Car.h"
#include "Road.h"

extern Car *porsche;
extern Road *road;

void InitGame(int, char **);
void WindowResize(int, int);
void LoadResources();
