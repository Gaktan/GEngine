#ifndef __ENGINE__CLOCK__H__
#define __ENGINE__CLOCK__H__

#include "math/mathutil.h"

// Can be cross platform. Should be working on Linux but untested
// Credits: https://gist.github.com/erichschroeter/8199129

//#if defined(WINDOWS)
#include <windows.h>
//#elif defined(LINUX)
//#include <unistd.h>
//#include <time.h>
//#else
//#error "Clock Not supported for this platform"
//#endif

GBeginNameSpace()

class ClockBase
{
public:
	float DeltaMs(const ClockBase& other) const
	{
		return Diff(other, 1000.0f, 1000.0f);
	}

	float DeltaMicro(const ClockBase& other) const
	{
		return Diff(other, 1000000.0f, 1000.0f);
	}

	static float DeltaMs(const ClockBase& start, const ClockBase& end)
	{
		return start.DeltaMs(end);
	}

	static float DeltaMicro(const ClockBase& start, const ClockBase& end)
	{
		return start.DeltaMicro(end);
	}

	static void Sleep(const ui32 ms);

private:
	virtual float Diff(const ClockBase& other, const float mul, const float div) const = 0;
};

#if defined(_WIN32_)
class ClockWindows : public ClockBase
{
public:
	ClockWindows()
	{
		QueryPerformanceCounter(&data);
	};

	static void Sleep(const ui32 ms)
	{
		::Sleep(ms);
	}

protected:
	float Diff(const ClockBase& other, const float mul, const float div) const
	{
		return Diff((ClockWindows&) other, mul, div);
	}

	float Diff(const ClockWindows& other, const float mul, const float div) const
	{
		LARGE_INTEGER frequency;

		QueryPerformanceFrequency(&frequency);
		float elapsedTime = other.data.QuadPart - data.QuadPart;

		elapsedTime *= (float) mul;
		elapsedTime /= (float) frequency.QuadPart;

		return elapsedTime;
	};

private:
	LARGE_INTEGER data;
};

typedef ClockWindows Clock;

#elif defined(UNIX)

class ClockUnix : public ClockBase
{
public:
	ClockUnix()
	{
		clock_gettime(CLOCK_MONOTONIC, &data);
	}

	static void Sleep(const ui32 ms)
	{
		// usleep takes sleep time in micro seconds
		usleep(sleepMs * 1000);
	}

private:
		float Diff(const ClockBase& other, const float mul, const float div) const
	{
		return Diff((ClockUnix&) other, mul, div);
	}

	float Diff(const ClockUnix& other, const float mul, const float div) const
	{
		return ((other.data.tv_sec * mul) + (other.data.tv_nsec / div)) -
		((data.tv_sec * mul) + (data.tv_nsec / div));
	}

private:
	struct timespec data;
};

typedef ClockUnix Clock;

#endif

GEndNameSpace()

#endif // __ENGINE__CLOCK__H__
