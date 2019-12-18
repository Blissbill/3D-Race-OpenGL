#include "InitGame.h"
GLuint * textures;
void InitGame(int argc, char **argv)
{
	glutInit(&argc, argv);
	camera = new Camera();
	camera->position.x = 0;
	camera->position.y = 0;
	camera->position.z = 10;
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(1366, 768);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("Race");
	glShadeModel(GL_LINEAR);//avs might well change to flat
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//??
	glEnable(GL_CULL_FACE);//glFrontFace()for GL_CW or GL_CCW
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glutReshapeFunc(WindowResize);
	//glutIgnoreKeyRepeat(1);
	/*glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	glShadeModel(GL_LINEAR);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glEnable(GL_TEXTURE_2D);
	glutIgnoreKeyRepeat(1);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//might not need
	glEnable(GL_TEXTURE_2D);*/
	LoadResources();
}

void WindowResize(int w, int h)
{
	if (h == 0)h = 1;

	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1.0f * w / h, 1, 100);
	gluLookAt(0, 3, 10, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

}

void LoadResources()
{
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	GLuint *texture = new GLuint[2];
	GLMmodel ** models = new GLMmodel*[2];
	models[enums::Car] = glmReadOBJ(const_cast<char*>("Resources/car.obj"));
	models[enums::Tyre] = glmReadOBJ(const_cast<char*>("Resources/tyre.obj"));
	texture[enums::Car] = SOIL_load_OGL_texture
	(
		"Resources/car.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	texture[enums::Tyre] = SOIL_load_OGL_texture
	(
		"Resources/Tyre.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	porsche = new Car(texture, models);
	road = new Road(SOIL_load_OGL_texture
	(
		"Resources/road.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	));
}