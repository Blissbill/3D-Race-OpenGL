#pragma once
#include "GL/freeglut.h"
#include "SOIL/SOIL.h"
#include "Glm/glm.h"
#include "Common.h"
#include <ctime>

extern GLuint *textures;
extern GLMmodel **models;

void InitGame(int, char **);
void WindowResize(int, int);
void LoadResources();
