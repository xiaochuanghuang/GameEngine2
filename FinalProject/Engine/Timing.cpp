#include "Timing.h"

#include <Windows.h>

#include <assert.h>

#include <limits.h>

namespace Engine
{
	namespace Timing {

		unsigned int lastFrame;

		LARGE_INTEGER performanceFre = { 0 };

		void Init()
		{
			BOOL success = QueryPerformanceFrequency(&performanceFre);

			assert(success == TRUE);

		}

		tick_t GetCurrentCounter()
		{
			LARGE_INTEGER currentFrameCounter;

			BOOL success = QueryPerformanceFrequency(&currentFrameCounter);

			assert(success == TRUE);

			return currentFrameCounter.QuadPart;

		}

		float GetTimeDifferent(tick_t startTime, tick_t endTime)
		{
			assert(performanceFre.QuadPart != 0);

			return (1000.0f * static_cast<float>(endTime - startTime)) / performanceFre.QuadPart;

		}

		//Bootstrapper TimingBoot

	}

}
