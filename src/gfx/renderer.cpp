#include "precomp.h"

#include "gfx/renderer.h"

#include "engine/mainloop.h"
#include "math/mathutil.h"

#include "gfx/opengl/mesh.h"

#include <GL/gl3w.h>

GBeginNameSpace()

static const char * vertexShader =
{
	"#version 330 \n" \
	" \n" \
	"layout(location = 0) in vec3 position; \n" \
	"layout(location = 1) in vec2 texCoord; \n" \
	" \n" \
	"out vec2 TexCoord; \n" \
	"out vec4 Color; \n" \
	" \n" \
	"void main() { \n" \
	" gl_Position = vec4(position, 1.0);\n" \
	" \n" \
	"	TexCoord = texCoord; \n" \
	"	Color = vec4(texCoord.x, texCoord.y, 0.0, 1.0); \n" \
	"}	 \n" \
};

static const char * fragmentShader =
{
	"#version 330 \n" \
	" \n" \
	"in vec4 Color; \n" \
	"in vec2 TexCoord; \n" \
	" \n" \
	"out vec4 color; \n" \
	" \n" \
	"uniform sampler2D u_texture;\n" \
	" \n" \
	"void main() \n" \
	"{ \n" \
	"	color = Color; \n" \
	"} \n" \
};

ui32 programID;

// TODO: make this abstract instead

void rendererInit()
{
	// Create shader
	ui32 fragmentShaderID, vertexShaderID;

	programID = glCreateProgram();
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, &fragmentShader, NULL);

	// Compile the shader
	glCompileShader(fragmentShaderID);

	// Check for errors
	GLint param;
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &param);
	if (param == GL_FALSE)
	{
		cout << "Unable to create fragment shader:" << endl;

		glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &param);

		Vector<char> v(param);
		glGetShaderInfoLog(fragmentShaderID, param, NULL, v.data());

		String str(v.begin(), v.end());

		// Print log
		cout << str << endl;
	}

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, &vertexShader, NULL);

	// Compile the shader
	glCompileShader(vertexShaderID);

	// Check for errors
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &param);
	if (param == GL_FALSE)
	{
		cout << "Unable to create fragment shader:" << endl;

		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &param);

		Vector<char> v(param);
		glGetShaderInfoLog(vertexShaderID, param, NULL, v.data());

		String str(v.begin(), v.end());

		// Print log
		cout << str << endl;
	}

	// Attach the shader
	glAttachShader(programID, fragmentShaderID);
	glAttachShader(programID, vertexShaderID);

	glLinkProgram(programID);

	// Check for linking errors
	glGetProgramiv(programID, GL_LINK_STATUS, &param);
	if (param == GL_FALSE)
	{
		cout << "Unable to link shader program" << endl;
	}

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glUseProgram(programID);
}

void rendererDrawFrame()
{
	glViewport(0, 0, 800, 600);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	static float rotation = 0.0f;

	rotation += (_PI * 0.001f) * MainLoop::GetInstance().GetDeltaTime();

	cout << MainLoop::GetInstance().GetDeltaTime() << endl;

	Mesh quad;
	Vector<Vertex> vertices;

	vertices.push_back( {-0.5f, sin(rotation) * -0.5f, 0.f, 0.f, 0.f} );
	vertices.push_back( {-0.5f, +0.5f, 0.f, 0.f, 1.f} );
	vertices.push_back( {+0.5f, +0.5f, 0.f, 1.f, 1.f} );
	vertices.push_back( {+0.5f, -0.5f, 0.f, 1.f, 0.f} );

	static const ui32 arr[] = { 0, 1, 2, 0, 2, 3 };
	Vector<ui32> indices(arr, arr + sizeof(arr) / sizeof(arr[0]));

	quad.CreateMesh(vertices, indices);

	quad.Draw();
}

void rendererEnd()
{
	glDeleteProgram(programID);
}

GEndNameSpace()
