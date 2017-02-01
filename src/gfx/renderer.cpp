#include "precomp.h"

#include "gfx/renderer.h"

#include <GL/gl.h>

GBeginNameSpace()


// TODO: make this abstract instead

void rendererInit()
{
	glViewport(0, 0, 800, 600);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rendererDrawFrame()
{
	float ratio = 800.0f / 600.0f;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(50.f, 0.f, 0.f, 1.f);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
	}
	glEnd();

}

void rendererEnd()
{
}

GEndNameSpace()