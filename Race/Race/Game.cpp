#include "Game.h"
float deltaAngle = 0.0f;
int xOrigin = -1;
int yOrigin = -1;
float speed;
void StartGame()
{
	glutDisplayFunc(Draw);
	glutSpecialFunc(SpecialKeys);
	glutIdleFunc(Draw);
	//GameLoop(0);
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

void SpecialKeys(int key, int xx, int yy) {
	float fraction = 1;
	switch (key) {
	case GLUT_KEY_LEFT:
		camera->angle += 1;
		camera->direction.x = sin(ATOR(camera->angle));
		camera->direction.z = -cos(ATOR(camera->angle));
		break;
	case GLUT_KEY_RIGHT:
		camera->angle -= 1;
		camera->direction.x = sin(ATOR(camera->angle));
		camera->direction.z = -cos(ATOR(camera->angle));
		break;
	case GLUT_KEY_UP:
		//camera->position.x += camera->direction.x * fraction;
		//camera->position.z += camera->direction.z * fraction;
		porsche->position.z -= fraction;
		camera->position.z = porsche->position.z;
		/*camera->angle += 0.1;
		camera->direction.y = sin(camera->angle);
		camera->direction.x = -cos(camera->angle);*/
		break;
	case GLUT_KEY_DOWN:
		//camera->position.x -= camera->direction.x * fraction;
		//camera->position.z -= camera->direction.z * fraction;
		porsche->position.z += fraction;
		camera->position.z = porsche->position.z;
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
	//gluLookAt(0, 3, 10, 0, 0,2, 0, 1, 0);
	camera->DrawCamera();
	road->DrawRoad(speed);
	porsche->DrawCar();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(-10, 0, 0);
	glVertex3d(10, 0, 0);

	glVertex3d(0, -10, 0);
	glVertex3d(0, 10, 0);

	glVertex3d(0, 0, -10);
	glVertex3d(0, 0, 10);

	glEnd();
	glutSwapBuffers();
}