#pragma once
#include "Glm/glm.h"
#include "Common.h"

class Car//Класс, описывающий автомобиль
{
	GLuint carTexture;//Хранит текстуру автомобиля
	GLuint tyreTexture;//Хранит текстуру колеса
	GLMmodel* car;//Хранит модель автомобиля
	GLMmodel* tyre;//Хранит модель колеса
public:
	Point position;//Хранит позицию автомобиля
	float speed;//Хранит скорость автомобиля
	float rot;//Хранит угол поворота автомобиля
	float rotTyre;//Хранит угол вращения колёс
	Car(GLuint carTexture, GLuint tyreTexture, GLMmodel* carModel, GLMmodel* tyreModel)//Конструктор
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
		speed = 100;
		this->carTexture = carTexture;
		this->tyreTexture = tyreTexture;
		car = carModel;
		tyre = tyreModel;
		rot = 0;
		rotTyre = 20;
	}

	GLMmodel* GetModelCar() const;//Метод возвращающий модель автомобиля
	GLMmodel* GetModelTyre() const;//Метод возвращающий модель колеса
	GLuint GetModelTextures() const;//Метод возвращающий текстуру автомобиля
	void DrawCar() const;//Метод рисующий машину
	GLuint GetTyreTextures() const;//Метод возвращающий модель колеса
};
