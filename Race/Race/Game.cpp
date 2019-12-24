#include "Game.h"
float deltaAngle = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
float speed;

Car *porsche;
Road *road;
Camera *camera;

void StartGame()
{
	camera = new Camera();
	camera->position.x = 0;
	camera->position.y = 0;
	camera->position.z = 10;
	porsche = new Car(textures[enums::Car], textures[enums::Tyre] , models[enums::Car], models[enums::Tyre]);
	road = new Road(textures[enums::Road]);
	road->width = 10;
	glutDisplayFunc(Draw);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);
	glutIdleFunc(Draw);
	GameLoop(0);
	speed = 0;
	porsche->position.z = 2;
	camera->position.x = porsche->position.x;
	camera->position.y = porsche->position.y;
	camera->position.z = porsche->position.z;
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
}
void GameLoop(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, GameLoop, 0);
	speed -= porsche->speed / 10000;
	
	if (speed < 0)speed = (1 + speed);
}
void SpecialKeysUp(int key, int xx, int yy)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		porsche->rot = 0;
		break;
	case GLUT_KEY_RIGHT:
		porsche->rot = 0;
		break;
	}
}
void SpecialKeys(int key, int xx, int yy) {
	float fraction = 1;
	switch (key) {
	case GLUT_KEY_LEFT:
		/*camera->angle += 1;
		camera->direction.x = sin(ATOR(camera->angle));
		camera->direction.z = -cos(ATOR(camera->angle));*/
		porsche->rot = 30;
		porsche->position.x -= speed;
		break;
	case GLUT_KEY_RIGHT:
		/*camera->angle -= 1;
		camera->direction.x = sin(ATOR(camera->angle));
		camera->direction.z = -cos(ATOR(camera->angle));*/
		porsche->rot = -30;
		porsche->position.x += speed;
		break;
	case GLUT_KEY_UP:
		//camera->position.x += camera->direction.x * fraction;
		//camera->position.z += camera->direction.z * fraction;
		/*porsche->position.z -= fraction;
		camera->position.z = porsche->position.z;*/
		/*camera->angle += 0.1;
		camera->direction.y = sin(camera->angle);
		camera->direction.x = -cos(camera->angle);*/
		break;
	case GLUT_KEY_DOWN:
		//camera->position.x -= camera->direction.x * fraction;
		//camera->position.z -= camera->direction.z * fraction;
		/*porsche->position.z += fraction;
		camera->position.z = porsche->position.z;*/
		break;
	}
}

void mouseButton(int button, int state, int x, int y)
{

	//if (button == GLUT_LEFT_BUTTON) {

		// когда кнопка отпущена
		if (state == GLUT_UP) {
			//camera->angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	//}
	
}

void mouseMove(int x, int y)
{

	// если левая кнопка опущена
	if (xOrigin >= 0) {

		// обновить deltaAngle
		deltaAngle = (x - xOrigin) * 0.1;
		// Обновление направления камеры
		camera->direction.x = sin(ATOR(camera->angle + deltaAngle));
		camera->direction.z = -cos(ATOR(camera->angle + deltaAngle));

		deltaAngle = (y - yOrigin) * 0.1;
		//camera->direction.y = sin(camera->angle + deltaAngle);
		camera->direction.y = -sin(ATOR(camera->angle + deltaAngle));
	}
}

void Draw()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawSky();
	camera->DrawCamera();
	//rightEarth->DrawEarth(speed, road->width);
	//leftEarth->DrawEarth(speed, road->width);
	DrawEarth();
	road->DrawRoad(speed);
	porsche->DrawCar();
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
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	glTranslatef(0, -speed, 0);
	
	glBegin(GL_QUADS);
	
	glColor3f(1, 1, 1);
	
	glTexCoord2f(2.0, 8.0);
	glVertex3d(60, 0, -100);
	
	glTexCoord2f(0.0, 8.0);
	glVertex3d(0 + road->width/2, 0, -100);
	
	glTexCoord2f(0.0, 0.0);
	glVertex3d(0 + road->width/2, 0, 100);
	
	glTexCoord2f(2.0, 0.0);
	glVertex3d(60, 0, 100);

	glEnd();
	
	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);

	glTexCoord2f(2.0, 8.0);
	glVertex3d(0 - road->width/2, 0, -100);

	glTexCoord2f(0.0, 8.0);
	glVertex3d(-60, 0, -100);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(-60, 0, 100);

	glTexCoord2f(2.0, 0.0);
	glVertex3d(0 - road->width/2, 0, 100);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}