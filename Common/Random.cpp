#include "Random.h"

namespace stl
{
	Random::Random() 
		: m_Engine(m_RandomDevice()) 
	{
	
	}

	const int Random::Next(const int aMax)
	{
		std::uniform_int_distribution distribution(0, aMax);
		return distribution(m_Engine);
	}
	
	const int Random::Next(const int aMin, const int aMax)
	{
		std::uniform_int_distribution distribution(aMin, aMax);
		return distribution(m_Engine);
	}
	
	const float Random::Next(const float aMax)
	{
		std::uniform_real_distribution<float> distribution(0, aMax);
		return distribution(m_Engine);
	}

	const float Random::Next(const float aMin, const float aMax)
	{
		std::uniform_real_distribution<float> distribution(aMin, aMax);
		return distribution(m_Engine);
	}
}

