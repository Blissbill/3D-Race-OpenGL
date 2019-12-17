#include "Game.h"
void gbps_GameLoop(int value);
float speed;
void StartGame()
{
	glutDisplayFunc(Draw);
	gbps_GameLoop(0);
	speed = 0;
}
void gbps_GameLoop(int value)
{
	glutPostRedisplay();
	glutTimerFunc(10, gbps_GameLoop, 0);
	(speed -= 2) < 0 ? speed = (1 + speed) : speed = speed;
}
void Draw()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glTranslated(0.0, 0.0, -5);
	//glRotated(21, 1.0, 0.0, 0.0);
	//glRotated(0, 0.0, 1.0, 0.0);
	
	//glMatrixMode(GL_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	//glDisable(GL_CULL_FACE);

	glPushMatrix();
	glTranslatef(0,  speed, 0);
	glBindTexture(GL_TEXTURE_2D, road->GetTexture());

	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(2, 0, -10);

	glTexCoord2f(1.0, 0.0);
	glVertex3d(-2, 0, -10);

	glTexCoord2f(1.0, 4.0);
	glVertex3d(-2, 0, 10);

	glTexCoord2f(0.0, 4.0);
	glVertex3d(2, 0, 10);

	glEnd();
	glPopMatrix();
	porsche->Position.y = 4;
	glPushMatrix();
	glTranslatef(porsche->Position.x, 0.6 , porsche->Position.y);
	glBindTexture(GL_TEXTURE_2D, porsche->GetModelTextures()[enums::Car]);
	glmDraw(porsche->GetModelCar(), GLM_SMOOTH | GLM_TEXTURE);
	
	glPopMatrix();
	glutSwapBuffers();
}