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

	virtual void LoadFile(const string &path) = 0;

	// Getters & Setters


	inline ui32 GetId() const { return m_Id; }
	inline void SetId(ui32 id) { m_Id = id; }

	inline ui16 GetWidth() const { return m_Width; }
	inline void SetWidth(ui16 width) { m_Width = width; }

	inline ui16 GetHeight() const { return m_Height; }
	inline void SetHeight(ui16 height) { m_Height = height; }

	inline bool HasAlpha() const { return m_HasAlpha; }
	inline void SetHasAlpha(bool hasAlpha) { m_HasAlpha = hasAlpha; }


	inline GFX_TEXTURE_FILTER GetFilter() const { return m_Filter; }
	inline void SetFilter(GFX_TEXTURE_FILTER filter) { m_Filter = filter; }

	inline GFX_TEXTURE_WRAP GetWrap() const { return m_Wrap; }
	inline void SetWrap(GFX_TEXTURE_WRAP wrap) { m_Wrap = wrap; }

	inline GFX_TEXTURE_FORMAT GetFormat() const { return m_Format; }
	inline void SetWrap(GFX_TEXTURE_FORMAT format) { m_Format = format; }

protected:
	ui32 m_Id;
	ui16 m_Width;
	ui16 m_Height;
	bool m_HasAlpha;

	GFX_TEXTURE_FILTER m_Filter;
	GFX_TEXTURE_WRAP m_Wrap;
	GFX_TEXTURE_FORMAT m_Format;

#ifdef _DEBUG_
public:
	inline string GetName() const { return m_Name; }
	inline void SetName(string name) { m_Name = name; }
protected:
	string m_Name;
#endif
};

GEndNameSpace()

// Depending if we use openGL or something else
//#ifdef _OGL_
#include "opengl/ogltexture.h"


//#endif // _OGL_

#endif // __GFX__TEXTURE__H__

