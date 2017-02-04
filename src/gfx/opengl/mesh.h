#ifndef __GFX__OPENGL__MESH__H__
#define __GFX__OPENGL__MESH__H__

GBeginNameSpace()

struct Vertex
{
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float uvX;
			float uvY;
		};
		float data[5];
	};
};

class Mesh
{
public:
	Mesh();
	virtual ~Mesh();

	void CreateMesh(const Vector<Vertex> &vertices,
					const Vector<ui32> &indices);

	void Draw();

protected:
	Vector<Vertex> m_Vertices;
	ui32 m_NumVertices;
	ui32 m_NumIndices;

	// OpenGL specific
	ui32 m_VertexArrayObject;
	ui32 m_VertexBufferObject;
	ui32 m_IndexBufferObject;

private:
};

GEndNameSpace()

#endif // __GFX__OPENGL__MESH__H__
