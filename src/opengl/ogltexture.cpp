#include "precomp.h"

#include "opengl/ogltexture.h"

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

void OglTexture::LoadFile(const gString &path)
{
	gByte* ret = SOIL_load_image
	(
		path.c_str(),
		&m_Width,
		&m_Height,
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

	m_Id = (gUInt) texture_id;
}

GEndNameSpace()
