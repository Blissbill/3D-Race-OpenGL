#include "Camera.h"

void Camera::DrawCamera() const
{
	gluLookAt(position.x, position.y, position.z, 
		position.x + direction.x, position.y + direction.y, position.z + direction.z,
		0.0f, 1.0f, 0.0f);
	/*gluLookAt(position.x, position.y, position.z,
		direction.x, direction.y,  direction.z,
		0.0f, 1.0f, 0.0f);*/
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3d(-10 + position.x, position.y, position.z);
	glVertex3d(10 + position.x, position.y, position.z);

	glVertex3d(position.x, -10 + position.y, position.z);
	glVertex3d(position.x, 10 + position.y, position.z);

	glVertex3d(position.x, position.y, -10 + position.z);
	glVertex3d(position.x, position.y, 10 + position.z);

	glEnd();
}
