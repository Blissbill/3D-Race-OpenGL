#include "GL/freeglut.h"
#include "SOIL/SOIL.h"
#include "InitGame.h"
#include "Glm/glm.h"
GLMmodel* car;
GLuint texture;
void InitGame(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1366, 768);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Race");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glutReshapeFunc(WindowResize);
	glShadeModel(GL_LINEAR);//avs might well change to flat
	glEnable(GL_CULL_FACE);//glFrontFace()for GL_CW or GL_CCW
	glEnable(GL_DEPTH_TEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glEnable(GL_FOG);
	glEnable(GL_TEXTURE_2D);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//might not need
	car = glmReadOBJ(const_cast<char*>("Resources/Stingray.obj"));
	//car = glmReadOBJ(const_cast<char*>("res/car.obj"));
	texture = SOIL_load_OGL_texture
	(
		"res/sand.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	glEnable(GL_TEXTURE_2D);
	//glPushMatrix();//for the current car
	//glRotatef(car_crash_angle, 1.0, 0, 0);
	//glTranslatef(Car.x, 0.6, -Car.y);//car translate
	//glRotatef(-Car.rot, 0, 1, 0);//car rotate
	

}
void WindowResize(int w, int h)
{
	int gbps_WindowHeight = h;
	int gbps_WindowWidth = w;
	// Prevent a divide by zero
	if (h == 0)h = 1;

	float ratio = 1.0f * w / h;
	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the clipping volume
	gluPerspective(45, ratio, 1, 1000);
	gluLookAt(0, 4, 4, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

}