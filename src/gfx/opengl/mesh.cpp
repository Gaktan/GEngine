#include "precomp.h"

#include "gfx/opengl/mesh.h"

#include <GL/gl3w.h>

GBeginNameSpace()

Mesh::Mesh()
{
	//ctor
}

Mesh::~Mesh()
{
	//glDeleteBuffers(1, &m_IndexBufferObject);
	glDeleteBuffers(1, &m_VertexBufferObject);
	glDeleteVertexArrays(1, &m_VertexArrayObject);
}

void Mesh::CreateMesh(const Vector<Vertex> &vertices,
					  const Vector<ui32> &indices)
{
	m_Vertices = vertices;
	m_NumVertices = m_Vertices.size();
	m_NumIndices = indices.size();

	// Generate objects
	glGenVertexArrays(1, &m_VertexArrayObject);
	glGenBuffers(1, &m_VertexBufferObject);
	glGenBuffers(1, &m_IndexBufferObject);

	// Bind VAO
	glBindVertexArray(m_VertexArrayObject);

	// Set vertices
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(Vertex), &m_Vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(ui32), &indices[0], GL_STATIC_DRAW);

	ui32 floatSize = sizeof(float);

	// TODO: do this based on vertex declaration
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) (3 * floatSize));
}

void Mesh::Draw()
{
	glBindVertexArray(m_VertexArrayObject);

	glDrawElements(GL_TRIANGLES, m_NumIndices, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

GEndNameSpace()
