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
	mainWindow.InitWindow(800, 600, false);


	rendererInit();
}

void MainLoop::StartLoop()
{
	BeforeLoop();

	m_IsRunning = true;

	m_DeltaTime = 33L; // TODO: Hardcoded (33ms). Should put target time instead

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

		bool shouldClose = MainWindowAbstract::GetInstance().UpdateWindow();
		if (shouldClose)
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

	MainWindowAbstract::GetInstance().DestroyWindow();

	cout << "End loop" << endl;
}

GEndNameSpace()
