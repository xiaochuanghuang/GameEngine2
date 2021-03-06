
#include "Windows.h"

#include <assert.h>
#include <stdint.h>

namespace Engine
{
	uint16_t AtomicIncrement(volatile uint16_t& i_Value)
	{
		static_assert(sizeof(uint16_t) == sizeof(SHORT), "uint16_t and Windows SHORT must be of same size.");
		return InterlockedIncrement16(reinterpret_cast<volatile SHORT*>(&i_Value));
	}

	uint16_t AtomicDecrement(volatile uint16_t& i_Value)
	{
		static_assert(sizeof(uint16_t) == sizeof(SHORT), "uint16_t and Windows SHORT must be of same size.");
		return InterlockedDecrement16(reinterpret_cast<volatile SHORT*>(&i_Value));
	}

	uint32_t AtomicIncrement(volatile uint32_t& i_Value)
	{
		static_assert(sizeof(uint32_t) == sizeof(LONG), "uint32_t and Windows LONG must be of same size.");
		return InterlockedIncrement(reinterpret_cast<volatile LONG*>(&i_Value));
	}

	uint32_t AtomicDecrement(volatile uint32_t& i_Value)
	{
		static_assert(sizeof(uint32_t) == sizeof(LONG), "uint32_t and Windows LONG must be of same size.");
		return InterlockedDecrement(reinterpret_cast<volatile LONG*>(&i_Value));
	}

	uint64_t AtomicIncrement(volatile uint64_t& i_Value)
	{
		static_assert(sizeof(uint64_t) == sizeof(LONG64), "uint64_t and Windows LONG64 must be of same size.");
		return InterlockedIncrement64(reinterpret_cast<volatile LONG64*>(&i_Value));
	}

	uint64_t AtomicDecrement(volatile uint64_t& i_Value)
	{
		static_assert(sizeof(uint64_t) == sizeof(LONG64), "uint64_t and Windows LONG64 must be of same size.");
		return InterlockedDecrement64(reinterpret_cast<volatile LONG64*>(&i_Value));
	}

}
