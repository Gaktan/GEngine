#ifndef __GFX__GFXCONTEXT__H__
#define __GFX__GFXCONTEXT__H__

#define VIRTUAL_FUNC(function) virtual function = 0

GBeginNameSpace()

class GfxContext
{
public:
	GfxContext();
	GfxContext(const GfxContext &other);
	virtual ~GfxContext();

	// Works like a singleton for now, until I can make it work asynchronously
	static GfxContext& GetContext() const;

protected:
	GfxContext m_Context;
};

GEndNameSpace()

#endif // __GFX__GFXCONTEXT__H__
