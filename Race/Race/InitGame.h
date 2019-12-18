#pragma once
#include "GL/freeglut.h"
#include "SOIL/SOIL.h"
#include "Glm/glm.h"
#include "Car.h"
#include "Road.h"
#include "Camera.h"

extern Car *porsche;
extern Road *road;
extern Camera *camera;

void InitGame(int, char **);
void WindowResize(int, int);
void LoadResources();
