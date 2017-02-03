#include "precomp.h"

#include "gfx/renderer.h"

#include "engine/mainloop.h"
#include "math/mathutil.h"

#include <GL/gl.h>

GBeginNameSpace()


// TODO: make this abstract instead

void rendererInit()
{
	glViewport(0, 0, 800, 600);

	float ratio = 800.0f / 600.0f;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void rendererDrawFrame()
{
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	static float rotation = 0.0f;
	static float x = 0.0;

	rotation += (360.0f * 0.001f) * MainLoop::GetInstance().GetDeltaTime();

	cout << MainLoop::GetInstance().GetDeltaTime() << endl;

	glRotatef(rotation, 0.f, 0.f, 1.f);
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
	glPopMatrix();
}

void rendererEnd()
{
}

GEndNameSpace()
