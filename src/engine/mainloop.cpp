#include "precomp.h"

#include "engine/mainloop.h"
#include "math/mathutil.h"

#include "engine/clock.h"

GBeginNameSpace()

void MainLoop::BeforeLoop()
{
	cout << "Begin Loop" << endl;
}

void MainLoop::StartLoop()
{
	BeforeLoop();

	m_IsRunning = true;

	m_DeltaTime = 33L; // TODO: Hardcoded (33ms). Should put target time instead

	// Temporary to test the main loop
	gLong totalTime = 0;

	while (m_IsRunning)
	{
		Clock start;

		cout << "previous frame took " << m_DeltaTime << "ms" << endl;

		Clock::Sleep(m_DeltaTime);

		Clock end;

		m_DeltaTime = start.DeltaMs(end);

		// Temporary to test the main loop
		totalTime += m_DeltaTime;
		if (totalTime > 6000)
		{
			break;
		}
	}

	m_IsRunning = false;

	AfterLoop();
}

void MainLoop::AfterLoop()
{
	cout << "End loop" << endl;
}

GEndNameSpace()
