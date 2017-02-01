#ifndef __GFX__MAINWINDOW__H__
#define __GFX__MAINWINDOW__H__

#include "engine/singleton.h"

GBeginNameSpace()

// Abstract class to be implemented by each platform
// in order to create a window or a rendering context
class MainWindowAbstract
{
public:
	MainWindowAbstract() {};
	MainWindowAbstract(const MainWindowAbstract &other) = delete;
	virtual ~MainWindowAbstract()
	{
		m_Instance = NULL;
	};

	static MainWindowAbstract& GetInstance();

	static void SetInstance(MainWindowAbstract* instance)
	{
		m_Instance = instance;
	}

	virtual i32 InitWindow(const i16 width, const i16 height, const bool fullscreen) = 0;
	virtual bool UpdateWindow() = 0;
	virtual void DestroyWindow() = 0;

private:
	static MainWindowAbstract *m_Instance;

};

GEndNameSpace()

#endif // __GFX__MAINWINDOW__H__
