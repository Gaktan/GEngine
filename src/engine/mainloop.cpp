#include "precomp.h"

#include "engine/mainloop.h"

#include "engine/clock.h"
#include "math/mathutil.h"
#include "gfx/renderer.h"
#if defined (_OPENGL_)
#include "gfx/opengl/mainwindowopengl.h"
#endif

GBeginNameSpace()

void MainLoop::BeforeLoop()
{
	cout << "Begin Loop" << endl;

#if defined (_OPENGL_)
	MainWindowAbstract::SetInstance(new MainWindowOpenGL());
#else
#error Not yet implemented
#endif

	MainWindowAbstract &mainWindow = MainWindowAbstract::GetInstance();
	i32 result = mainWindow.InitWindow(800, 600, false);

	if (result != 0)
	{
		m_IsRunning = false;
	}

	rendererInit();
}

void MainLoop::StartLoop()
{
	m_IsRunning = true;

	BeforeLoop();


	m_DeltaTime = 33.0f; // TODO: Hardcoded (33ms). Should put target time instead

	while (m_IsRunning)
	{
		Clock start;

		// Loop start

		rendererInit();
		rendererDrawFrame();
		rendererEnd();

		// Loop end

		bool shouldClose = MainWindowAbstract::GetInstance().UpdateWindow();
		if (shouldClose)
		{
			break;
		}

		Clock end;
		m_DeltaTime = start.DeltaMs(end);
		// So delta time doesn't get too big with big lag spikes
		m_DeltaTime = clamp(m_DeltaTime, 0.0f, 33.0f);
	}

	m_IsRunning = false;

	AfterLoop();
}

void MainLoop::AfterLoop()
{
	rendererEnd();

	MainWindowAbstract::GetInstance().DestroyWindow();

	cout << "End loop" << endl;
}

GEndNameSpace()
