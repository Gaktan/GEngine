#include "precomp.h"

#include "gfx/mainwindow.h"

GBeginNameSpace()

MainWindowAbstract* MainWindowAbstract::m_Instance = nullptr;

MainWindowAbstract& MainWindowAbstract::GetInstance()
{
	assert(m_Instance);
	return *m_Instance;
}

GEndNameSpace()
