#pragma once

#include <stdint.h>

namespace Engine {

	namespace Timing {

		void Init();
		typedef uint64_t tick_t;

		tick_t GetCurrentCounter();

		float  GetTimeDifferent(tick_t startTime, tick_t endTime = GetCurrentCounter());

		inline float secondToMileSecond(float seconds);
		inline float perSecondToPerMileSecond(float perSeconds);


	}

}




