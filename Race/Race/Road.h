#pragma once
#include "Glm/glm.h"
#include "Common.h"

class Road//Класс, описывающий дорогу
{
	GLuint texture;//Хранит текстуру дороги
public:
	Point position;//Хранит позицию дороги
	float width;//Хранит ширину дороги
	Road(GLuint texture)//Конструктор
	{
		position.x = 0;
		position.y = 0;
		position.z = 100;
		width = 7;
		this->texture = texture;
	}
	GLuint GetTexture() const;//Метод возвращающий текстуру дороги
	void DrawRoad(float) const;////Метод рисующий дорогу
	
};
