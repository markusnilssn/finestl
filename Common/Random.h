#pragma once

#include <random>

namespace stl
{
	class Random
	{
	public:
		Random();

		Random(const Random&) = delete;
		Random& operator=(const Random&) = delete;

		Random(Random&&) = delete;
		Random& operator=(Random&&) = delete;
		
		const int Next(const int aMax);
		const int Next(const int aMin, const int aMax);

		const float Next(const float aMax);
		const float Next(const float aMin, const float aMax);

	private:
		std::random_device m_RandomDevice;
		std::mt19937 m_Engine;
	};
}