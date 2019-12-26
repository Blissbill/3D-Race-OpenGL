#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"

float speed;
int horPos = 0;
int horPosEnemy = -1;
bool horMove = false;
bool t = false;
int choose;

enums::Flags Flag = enums::Menu;
Car *porsche;
Road *road;
Car *enemy;

int score;

void StartGame()
{
	porsche = new Car(textures[enums::Car], textures[enums::Tyre], models[enums::Car], models[enums::Tyre]);
	enemy = new Car(textures[enums::CarEnemy], textures[enums::Tyre], models[enums::Car], models[enums::Tyre]);
	road = new Road(textures[enums::Road]);
	road->width = 10;
	glutDisplayFunc(Draw);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutIdleFunc(Draw);
	glutKeyboardFunc(processNormalKeys);
	enemy->position.z = -100;
	GameLoop(0);
	speed = 0;
	porsche->position.z = 10;
	choose = 1;
	// создать меню
	// сообщить GLUT что "processMenuEvents" будет
	// обрабатывать события
}
void GameLoop(int value)
{
	if (Flag == enums::Game)
	{
		glutTimerFunc(1000 / 60, GameLoop, 0);
		speed -= porsche->speed / 1000;
		if (speed < 0)speed = (1 + speed);
		UpdatePosition();
	}
}
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		if (Flag == enums::GameOver || Flag == enums::Game)
		{
			Flag = enums::Menu;
		}
	if (key == 13)
	{
		if (Flag == enums::GameOver)
		{
			Flag = enums::Menu;
		}
		else
			if (Flag = enums::Menu)
			{
				switch (choose)
				{
				case 1:
					NewGame();
					Flag = enums::Game;
					break;
				case 2:
					MessageBox(0, "Необходимо объезжать попутные машины не задевая их.\nЗа каждую машину оставленную позади игроку начисляются баллы\nв зависимости от скорости, с которой объехали машину соперника.\nИмеются три скорости: 200, 100, 50 км/ч.\nУправление осуществляется при помощи стрелок на клавиатуре.\nНавигация по пунктам меню осуществляется также при помощью стрелок.", "Правила", MB_OK);
					break;
				case 3:
					MessageBox(0, "Игра 'Гонки'.\nВыполнил студент группы ЕТ-412\nРоманов Никита\nЮУрГУ 2019г.", "Об игре", MB_OK);
					break;
				case 4:
					exit(0);
					break;
				}
			}
	}
}
void SpecialKeysUp(int key, int xx, int yy)
{
	if (Flag == enums::Game)
	{
		switch (key) {
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
			horPos = 0;
			break;
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
			porsche->speed = 100;
			break;
		}
	}
}
void SpecialKeys(int key, int xx, int yy) {
	if (Flag == enums::Game)
	{
		switch (key) {
		case GLUT_KEY_LEFT:
			horPos = -1;
			break;
		case GLUT_KEY_RIGHT:
			horPos = 1;
			break;
		case GLUT_KEY_UP:
			porsche->speed = 200;
			break;
		case GLUT_KEY_DOWN:
			porsche->speed = 50;
			break;
		}
	}
	if (Flag == enums::Menu)
	{
		switch (key) {
		case GLUT_KEY_UP:
			choose = choose == 1 ? 4 : choose - 1;
			break;
		case GLUT_KEY_DOWN:
			choose = choose == 4 ? 1 : choose + 1;
			break;
		}
	}
}

void UpdatePosition()
{
	if (porsche->rotTyre == 720)
		porsche->rotTyre = 0;
	porsche->rotTyre += 20;
	enemy->position.z += porsche->speed / 30;
	if (horMove)
	{
		if (enemy->position.x >= -3 && enemy->position.x <= 3)
		{

			enemy->position.x += horPosEnemy * porsche->speed / 100 * 0.2;
			if (fabs(enemy->position.x) > 3)
			{
				enemy->position.x = 3 * horPosEnemy;
				horPosEnemy = horPosEnemy == 1 ? -1 : 1;
			}
		}
	}
	if (enemy->position.z > 20)
	{
		enemy->position.z = -100;
		enemy->position.x = (-300 + rand() % 600) / 100;
		horMove = rand() % 2 == 1 ? true : false;
		t = false;
	}
	if (horPos != 0 && porsche->position.x >= -3 && porsche->position.x <= 3)
	{

		porsche->rot = 20 * (-horPos);
		porsche->position.x += horPos * porsche->speed / 100 * 0.3;
		if (fabs(porsche->position.x) > 3)
		{
			porsche->position.x = 3 * horPos;
			porsche->rot = 0;
		}
	}
	else
	{
		porsche->rot = 0;
	}
	if (fabs(enemy->position.x - porsche->position.x) < 2)
	{
		if (fabs(enemy->position.z - porsche->position.z) < 4)
		{
			porsche->speed = 0;
			porsche->rotTyre = 0;
			Flag = enums::GameOver;
			return;
		}
	}
	if (enemy->position.z > 15 && !t)
	{
		score += porsche->speed;
		t = true;
	}
}

void RenderScore()
{
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);

	char sc[100];
	sprintf(sc, "Speed : %.0f", porsche->speed);
	glutPrint(-10, 5, GLUT_BITMAP_TIMES_ROMAN_24, sc, 225, 0, 0, 1);
	sprintf(sc, "Score : %d", score);
	glutPrint(5, 5, GLUT_BITMAP_TIMES_ROMAN_24, sc, 225, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

}

void glutPrint(float x, float y, LPVOID font, char* text, float r, float g, float b, float a)
{
	if (!text || !strlen(text)) return;
	//glEnable(GL_BLEND);
	glColor4f(r, g, b, a);
	glRasterPos3f(x, y, -10);
	while (*text)
	{
		glutBitmapCharacter(font, *text);
		text++;
	}
	//glDisable(GL_BLEND);
}

void Draw()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (Flag == enums::Game || Flag == enums::GameOver)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 1.0f * 1366 / 768, 1, 120);
		gluLookAt(0, 3, 17, 0, 0, 0, 0, 1, 0);
		glMatrixMode(GL_MODELVIEW);
		DrawSky();
		DrawEarth();
		road->DrawRoad(speed);
		porsche->DrawCar();
		enemy->DrawCar();
		RenderScore();
		if (Flag == enums::GameOver)
		{
			DrawGameOver();
		}
	}
	if (Flag == enums::Menu)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 1.0f * 1366 / 768, 1, 120);
		gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
		glMatrixMode(GL_MODELVIEW);
		DrawMenu();
		//DrawSky();
	}

	glutSwapBuffers();
}
void DrawSky()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, textures[enums::Sky]);
	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(120, 60, -100);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(-120, 60, -100);
	glTexCoord2f(0.0, 0.0);
	glVertex3d(-120, -60, -100);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(120, -60, -100);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void DrawEarth()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[enums::Earth]);
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glTranslatef(0, -speed, 0);

	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);

	glTexCoord2f(2.0, 8.0);
	glVertex3d(60, 0, -100);

	glTexCoord2f(0.0, 8.0);
	glVertex3d(0 + road->width / 2, 0, -100);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(0 + road->width / 2, 0, 100);

	glTexCoord2f(2.0, 0.0);
	glVertex3d(60, 0, 100);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);

	glTexCoord2f(2.0, 8.0);
	glVertex3d(0 - road->width / 2, 0, -100);

	glTexCoord2f(0.0, 8.0);
	glVertex3d(-60, 0, -100);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(-60, 0, 100);

	glTexCoord2f(2.0, 0.0);
	glVertex3d(0 - road->width / 2, 0, 100);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void DrawGameOver()
{
	glEnable(GL_BLEND);     // Turn Blending On
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, textures[enums::GameEnd]);

	glScalef(0.5, 0.5, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(1.0, 1.0); glVertex3f(20.0, 8.0, 3.0);
	glTexCoord2d(0.0, 1.0); glVertex3f(-20.0, 8.0, 3.0);
	glTexCoord2d(0.0, 0.0); glVertex3f(-20.0, -5.0, 3.0);
	glTexCoord2d(1.0, 0.0); glVertex3f(20.0, -5.0, 3.0);

	glEnd();



	glEnable(GL_DEPTH_TEST);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_BLEND);
}
void NewGame()
{
	enemy->position.z = -100;
	enemy->position.x = (-300 + rand() % 600) / 100;
	horMove = rand() % 2 == 1 ? true : false;
	Flag = enums::Game;
	porsche->speed = 100;
	porsche->rotTyre = 20;
	score = 0;
	GameLoop(0);
}
void DrawMenu()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, textures[enums::Background]);

	glScalef(0.6, 0.9, 0.1);

	glBegin(GL_QUADS);
	//glColor3f(255, 1, 1);
	glTexCoord2d(1.0, 1.0); glVertex3f(20.0, 5.0, 3.0);
	glTexCoord2d(0.0, 1.0); glVertex3f(-20.0, 5.0, 3.0);
	glTexCoord2d(0.0, 0.0); glVertex3f(-20.0, -5.0, 3.0);
	glTexCoord2d(1.0, 0.0); glVertex3f(20.0, -5.0, 3.0);

	glEnd();



	glEnable(GL_DEPTH_TEST);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glEnable(GL_BLEND);     // Turn Blending On
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, textures[enums::MenuText]);

	//glScalef(0.7, 0.7, 1.0);

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2d(1.0, 1.0); glVertex3f(-2.0, 2.0, 3.0);
	glTexCoord2d(0.0, 1.0); glVertex3f(-5.0, 2.0, 3.0);
	glTexCoord2d(0.0, 0.0); glVertex3f(-5.0, 1.0, 3.0);
	glTexCoord2d(1.0, 0.0); glVertex3f(-2.0, 1.0, 3.0);

	glEnd();



	glEnable(GL_DEPTH_TEST);

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_BLEND);

	glPushMatrix();

	glEnable(GL_BLEND);     // Turn Blending On
							//glDisable(GL_DEPTH_TEST);
	glColor4f(0, 0, 205, 0.8);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glScalef(0.8, 0.5, 1.0);
	glTranslatef(-4, 0.6, 0.00);
	switch (choose)
	{
	case 1:
		glTranslatef(-5.0, 4.5, 0.00);
		break;
	case 2:
		glTranslatef(-5.0, 3.75, 0.00);
		break;
	case 3:
		glTranslatef(-5.0, 3, 0.00);
		break;
	case 4:
		glTranslatef(-5.0, 2.3, 0.00);
		break;
	}

	glScalef(1.0, 0.8, 1.0);


	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(6.0, 0);
	glVertex2f(6.0, 1.0);
	glVertex2f(0, 1.0);
	glEnd();

	glDisable(GL_BLEND);     // Turn B
	glEnable(GL_DEPTH_TEST);
	//glColor4f(1.0, 1.0, 1.0, 1.0);
	glPopMatrix();
}