#include "InitGame.h"
void InitGame(int argc, char **argv)
{
	glutInit(&argc, argv);
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
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0 };
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	GLfloat light1_position[] = { 0, 3, 10, 1.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
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
	gluPerspective(45, 1.0f * w / h, 1, 120);
	gluLookAt(0, 3, 10, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

}

void LoadResources()
{
	textures = new GLuint[20];
	models = new GLMmodel*[20];
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	models[enums::Car] = glmReadOBJ(const_cast<char*>("Resources/car.obj"));
	models[enums::Tyre] = glmReadOBJ(const_cast<char*>("Resources/tyre.obj"));
	textures[enums::Car] = SOIL_load_OGL_texture
	(
		"Resources/car.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	textures[enums::Tyre] = SOIL_load_OGL_texture
	(
		"Resources/Tyre.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	
	textures[enums::Road] = SOIL_load_OGL_texture
	(
		"Resources/road.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	
	textures[enums::Sky] = SOIL_load_OGL_texture
	(
		"Resources/sky.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
	textures[enums::Earth] = SOIL_load_OGL_texture
	(
		"Resources/earth.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
	);
}