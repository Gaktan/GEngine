#ifndef __GFX__OPENGL__MAINWINDOWOPENGL__H__
#define __GFX__OPENGL__MAINWINDOWOPENGL__H__

#include "gfx/mainwindow.h"

#include <GLFW/glfw3.h>


GBeginNameSpace()

class MainWindowOpenGL : public MainWindowAbstract
{
public:
	MainWindowOpenGL();

	virtual ~MainWindowOpenGL();

	virtual i32 InitWindow(const i16 width, const i16 height, const bool fullscreen);
	virtual bool UpdateWindow();
	virtual void DestroyWindow();

	enum WindowErrorCodes
	{
		WINDOW_NO_ERROR,
		WINDOW_LIBRARY_INIT_ERROR,
		WINDOW_CREATION_ERROR
	};

private:
	GLFWwindow* m_Window;
};

GEndNameSpace()

#endif // __GFX__OPENGL__MAINWINDOWOPENGL__H__
