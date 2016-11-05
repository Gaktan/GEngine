#ifndef __GFX__TEXTURE__H__
#define __GFX__TEXTURE__H__

GBeginNameSpace()

enum GFX_TEXTURE_WRAP
{
	REPEAT,
	MIRRORED_REPEAT,
	CLAMP_TO_EDGE,
	CLAMP_TO_BORDER
};

enum GFX_TEXTURE_FILTER
{
	LINEAR,
	LINEAR_MIPMAP_NEAREST,
	LINEAR_MIPMAP_LINEAR,
	NEAREST,
	NEAREST_MIPMAP_NEAREST,
	NEAREST_MIPMAP_LINEAR
};

enum GFX_TEXTURE_FORMAT
{
	// Non-exhaustive list
	R_32_F,
	RGB_32_F,
};

class TextureBase
{
public:
	TextureBase();
	TextureBase(const TextureBase &other);
	virtual ~TextureBase();

	virtual void LoadFile(const gString &path) = 0;

	// Getters & Setters


	inline gInt GetId() const { return m_Id; }
	inline void SetId(gInt id) { m_Id = id; }

	inline gInt GetWidth() const { return m_Width; }
	inline void SetWidth(gInt width) { m_Width = width; }

	inline gInt GetHeight() const { return m_Height; }
	inline void SetHeight(gInt height) { m_Height = height; }

	inline gBool HasAlpha() const { return m_HasAlpha; }
	inline void SetHasAlpha(gBool hasAlpha) { m_HasAlpha = hasAlpha; }


	inline GFX_TEXTURE_FILTER GetFilter() const { return m_Filter; }
	inline void SetFilter(GFX_TEXTURE_FILTER filter) { m_Filter = filter; }

	inline GFX_TEXTURE_WRAP GetWrap() const { return m_Wrap; }
	inline void SetWrap(GFX_TEXTURE_WRAP wrap) { m_Wrap = wrap; }

	inline GFX_TEXTURE_FORMAT GetFormat() const { return m_Format; }
	inline void SetWrap(GFX_TEXTURE_FORMAT format) { m_Format = format; }

protected:
	gUInt m_Id;
	gInt m_Width;
	gInt m_Height;
	gBool m_HasAlpha;

	GFX_TEXTURE_FILTER m_Filter;
	GFX_TEXTURE_WRAP m_Wrap;
	GFX_TEXTURE_FORMAT m_Format;

#ifdef _DEBUG_
public:
	inline gString GetName() const { return m_Name; }
	inline void SetName(gString name) { m_Name = name; }
protected:
	gString m_Name;
#endif
};

GEndNameSpace()

// Depending if we use openGL or something else
//#ifdef _OGL_
#include "opengl/ogltexture.h"


//#endif // _OGL_

#endif // __GFX__TEXTURE__H__

