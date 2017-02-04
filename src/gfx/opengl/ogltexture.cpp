#include "precomp.h"

#include "gfx/opengl/ogltexture.h"

#include <GL/gl.h>

#include "SOIL.H"

GBeginNameSpace()

OglTexture::OglTexture() :
	TextureBase()
{
}

OglTexture::OglTexture(const OglTexture &other) :
	TextureBase(other)
{
}

OglTexture::~OglTexture()
{
	//SOIL_free_image_data(m_Id);
}

void OglTexture::LoadFile(const String &path)
{
	byte* ret = SOIL_load_image
	(
		path.c_str(),
		(int*) &m_Width,
		(int*) &m_Height,
		0,
		SOIL_LOAD_RGB
	);

#ifdef _DEBUG_
	if (ret == NULL)
	{
		assertWithMessage(false,
			stringFormat("Loading texture '%s' failed with error: %s", path.c_str(), SOIL_last_result()));
		return;
	}
#endif

	GLuint texture_id;
	glGenTextures(1, &texture_id);

	m_Id = (ui32) texture_id;
}

GEndNameSpace()
