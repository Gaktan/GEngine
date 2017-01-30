#include "precomp.h"

#include "engine/mainloop.h"

#include "engine/clock.h"
#include "math/mathutil.h"
#include "gfx/renderer.h"


GBeginNameSpace()

void MainLoop::BeforeLoop()
{
	cout << "Begin Loop" << endl;
	rendererInit();
}

void MainLoop::StartLoop()
{
	BeforeLoop();

	m_IsRunning = true;

	m_DeltaTime = 33L; // TODO: Hardcoded (33ms). Should put target time instead

	// Temporary to test the main loop
	ui32 totalTime = 0;

	while (m_IsRunning)
	{
		Clock start;

		// Loop start

		rendererDrawFrame();
		cout << "previous frame took " << m_DeltaTime << "ms" << endl;

		Clock::Sleep(1000);

		// Loop end

		Clock end;
		m_DeltaTime = start.DeltaMs(end);

		// Temporary to test the main loop
		totalTime += m_DeltaTime;
		if (totalTime > 60000)
		{
			break;
		}
	}

	m_IsRunning = false;

	AfterLoop();
}

void MainLoop::AfterLoop()
{
	rendererEnd();
	cout << "End loop" << endl;
}

GEndNameSpace()
