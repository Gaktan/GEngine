#ifndef __ENGINE__MAINLOOP_H__
#define __ENGINE__MAINLOOP_H__

#include "engine/singleton.h"

GBeginNameSpace()

class MainLoop : public Singleton<MainLoop>
{
public:
	void StartLoop();
	gBool IsRunning() { return m_IsRunning; };
	void Stop() { m_IsRunning = false; };
	gFloat GetDeltaTime() { return m_DeltaTime; };

protected:
	void BeforeLoop();
	void AfterLoop();

protected:
	gBool m_IsRunning;
	gFloat m_DeltaTime;
};

GEndNameSpace()

#endif // __ENGINE__MAINLOOP_H__
