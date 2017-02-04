#ifndef __GFX__OPENGL__OGLTEXTURE__H__
#define __GFX__OPENGL__OGLTEXTURE__H__

#include "gfx/texture.h"

GBeginNameSpace()

class OglTexture : public TextureBase
{
public:
	OglTexture();
	OglTexture(const OglTexture &other);
	virtual ~OglTexture();

	virtual void LoadFile(const String &path);
};

typedef OglTexture gTexture;

GEndNameSpace()

#endif // __GFX__OPENGL__OGLTEXTURE__H__
