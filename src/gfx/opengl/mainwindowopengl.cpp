#include "precomp.h"

// Compile GL3W
extern "C"
{
	#include <GL/gl3w.h>
	#include <../src/gl3w.c>
}

#include "gfx/opengl/mainwindowopengl.h"

GBeginNameSpace()

MainWindowOpenGL::MainWindowOpenGL()
{
	m_Window = nullptr;
}

MainWindowOpenGL::~MainWindowOpenGL()
{
}

void error_callback(int error, const char* description)
{
	cout << "Error in MainWindowOpenGL: " << description << endl;
}

i32 MainWindowOpenGL::InitWindow(const i16 width, const i16 height, const bool fullscreen)
{
	glfwSetErrorCallback(error_callback);

	// Initialize the library
	if (!glfwInit())
		return WINDOW_LIBRARY_INIT_ERROR;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	m_RefreshRate = mode->refreshRate;

	// Create a windowed mode window and its OpenGL context
	m_Window = glfwCreateWindow(width, height, "GEngine", NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		return WINDOW_CREATION_ERROR;
	}

	if (fullscreen)
	{
		glfwSetWindowMonitor(m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}

	// Make the window's context current
	glfwMakeContextCurrent(m_Window);

	// Vsync
	glfwSwapInterval(1);

	if (gl3wInit())
	{
		cout << "failed to initialize OpenGL\n" << endl;
		return -1;
	}

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);

	cout << "Using renderer: " << (char*)renderer << ".\nOpenGL version supported: " << (char*)version << endl;
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
	glfwDestroyWindow(m_Window);

	glfwTerminate();

	delete this;
}

GEndNameSpace()
