#pragma once
#include "GL/freeglut.h"
#include <cmath>
#include "Glm/glm.h"

#define ATOR(x) x * M_PI/180.0f
extern GLuint *textures;
extern GLMmodel **models;
struct Point//���������, ����������� ������� ��������
{
	float x;//���������� �� X
	float y;//���������� �� Y
	float z;//���������� �� Z
};
namespace enums
{
	enum Models
	{
		Car = 0,
		Tyre,
		Road,
		Sky,
		Earth,
		GameEnd,
		Background,
		MenuText,
		CarEnemy
	};
	enum Flags
	{
		Game,
		Menu,
		GameOver
	};
}