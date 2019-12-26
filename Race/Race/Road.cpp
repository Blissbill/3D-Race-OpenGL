#include "Road.h"
GLuint Road::GetTexture() const
{
	return texture;

}
void Road::DrawRoad(float speed) const
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, GetTexture());
	glPushMatrix();
	glMatrixMode(GL_TEXTURE);
	
	glTranslatef(0, speed, 0);
	

	glBegin(GL_QUADS);

	glColor3f(1, 1, 1);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(width/2 + position.x, position.y, -position.z);

	glTexCoord2f(1, 0.0);
	glVertex3d(-width / 2 + position.x, position.y, -position.z);

	glTexCoord2f(1.0, 8.0);
	glVertex3d(-width / 2 + position.x, position.y, position.z);

	glTexCoord2f(0.0, 8.0);
	glVertex3d(width / 2 + position.x, position.y, position.z);

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}