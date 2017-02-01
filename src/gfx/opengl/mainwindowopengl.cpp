#include "precomp.h"

#include "gfx/opengl/mainwindowopengl.h"


GBeginNameSpace()

MainWindowOpenGL::MainWindowOpenGL()
{
	m_Window = nullptr;
}

MainWindowOpenGL::~MainWindowOpenGL()
{
}

i32 MainWindowOpenGL::InitWindow(const i16 width, const i16 height, const bool fullscreen)
{
	// Initialize the library
	if (!glfwInit())
		return WINDOW_LIBRARY_INIT_ERROR;

	// Create a windowed mode window and its OpenGL context
	m_Window = glfwCreateWindow(width, height, "GEngine", NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		return WINDOW_CREATION_ERROR;
	}

	if (fullscreen)
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(monitor);
		glfwSetWindowMonitor(m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}

	// Make the window's context current
	glfwMakeContextCurrent(m_Window);

	return WINDOW_NO_ERROR;
}

bool MainWindowOpenGL::UpdateWindow()
{
	// Swap front and back buffers
	glfwSwapBuffers(m_Window);

	// Poll for and process events
	glfwPollEvents();

	return glfwWindowShouldClose(m_Window);
}

void MainWindowOpenGL::DestroyWindow()
{
	glfwTerminate();

	glfwDestroyWindow(m_Window);

	delete this;
}

GEndNameSpace()
