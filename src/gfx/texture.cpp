#include "precomp.h"

#include "gfx/texture.h"

GBeginNameSpace()

Texture::Texture()
{
	m_Id = -1;
	m_Width = 0;
	m_Height = 0;
	m_HasAlpha = false;
	m_Filter = LINEAR;
	m_Wrap = REPEAT;
	m_Format = R_32_F;
}

Texture::Texture(const Texture& other)
{
	m_Id = other.m_Id;
	m_Width = other.m_Width;
	m_Height = other.m_Height;
	m_HasAlpha = other.m_HasAlpha;

	m_Filter = other.m_Filter;
	m_Wrap = other.m_Wrap;
	m_Format = other.m_Format;
}

Texture::~Texture()
{

}

void Texture::LoadTexture(const gString &path)
{

}

GEndNameSpace()
