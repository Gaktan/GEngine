#ifndef __ENGINE__MAINLOOP_H__
#define __ENGINE__MAINLOOP_H__

#include "engine/singleton.h"

GBeginNameSpace()

class MainLoop : public Singleton<MainLoop>
{
public:
	void StartLoop();
	bool IsRunning() { return m_IsRunning; };
	void Stop() { m_IsRunning = false; };
	float GetDeltaTime() { return m_DeltaTime; };

protected:
	void BeforeLoop();
	void AfterLoop();

protected:
	bool m_IsRunning;
	float m_DeltaTime;
};

GEndNameSpace()

#endif // __ENGINE__MAINLOOP_H__
