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
	gLong DeltaMs(const ClockBase& other) const
	{
		return Diff(other, 1000, 1000);
	}

	gLong DeltaMicro(const ClockBase& other) const
	{
		return Diff(other, 1000000, 1000);
	}

	static gLong DeltaMs(const ClockBase& start, const ClockBase& end)
	{
		return start.DeltaMs(end);
	}

	static gLong DeltaMicro(const ClockBase& start, const ClockBase& end)
	{
		return start.DeltaMicro(end);
	}

	static void Sleep(const gLong ms);

private:
	virtual gLong Diff(const ClockBase& other, const gLong mul, const gLong div) const = 0;
};

// TODO: Clock HARDCODED FOR WINDOW
#if 1
//#if defined(WINDOWS)
class ClockWindows : public ClockBase
{
public:
	ClockWindows()
	{
		QueryPerformanceCounter(&data);
	};

	static void Sleep(const gLong ms)
	{
		::Sleep(ms);
	}

protected:
	gLong Diff(const ClockBase& other, const gLong mul, const gLong div) const
	{
		return Diff((ClockWindows&) other, mul, div);
	}

	gLong Diff(const ClockWindows& other, const gLong mul, const gLong div) const
	{
		LARGE_INTEGER frequency, elapsed;

		QueryPerformanceFrequency(&frequency);
		elapsed.QuadPart = other.data.QuadPart - data.QuadPart;

		elapsed.QuadPart *= mul;
		elapsed.QuadPart /= frequency.QuadPart;

		return elapsed.QuadPart;
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

	static void Sleep(const gLong ms)
	{
		// usleep takes sleep time in micro seconds
		usleep(sleepMs * 1000);
	}

private:
		gLong Diff(const ClockBase& other, const gLong mul, const gLong div) const
	{
		return Diff((ClockUnix&) other, mul, div);
	}

	gLong Diff(const ClockUnix& other, const gLong mul, const gLong div) const
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
