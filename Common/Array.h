#pragma once
#include <initializer_list>
#include "Macros.h"


namespace simpletl
{
	template <typename T, size_t LENGTH>
	class Array final 
	{
	public:
		Array();
		Array(std::initializer_list<T> aList);
		~Array();

		Array(const Array&) = delete;
		Array& operator=(const Array&) = delete;

		Array(Array&&) = delete;
		Array& operator=(Array&&) = delete;

		T& ElementAt(const size_t aIndex);
		const T& ElementAt(const size_t aIndex) const;

		const bool Contains(const T& aData) const;
	
		const T& operator[](const size_t aIndex) const;
		T& operator[](const size_t aIndex);

		const size_t Size() const;
	private:
		T m_Data[LENGTH];
	};

	template<typename T, size_t LENGTH>
	inline Array<T, LENGTH>::Array()
	{
		for (size_t i = 0; i < LENGTH; i++)
		{
			m_Data[i] = T();
		}
	}

	template<typename T, size_t LENGTH>
	inline Array<T, LENGTH>::Array(std::initializer_list<T> aList)
	{
		for (auto it = aList.begin(); it != aList.end(); it++)
		{
			m_Data[it - aList.begin()] = *it;
		}
	}

	template<typename T, size_t LENGTH>
	inline Array<T, LENGTH>::~Array()
	{
		delete[] m_Data;
	}

	template<typename T, size_t LENGTH>
	inline T& Array<T, LENGTH>::ElementAt(const size_t aIndex)
	{
		assert(aIndex < LENGTH);


		return m_Data[aIndex];
	}

	template<typename T, size_t LENGTH>
	inline const T& Array<T, LENGTH>::ElementAt(const size_t aIndex) const
	{
		assert(aIndex < LENGTH);

		return m_Data[aIndex];
	}

	template<typename T, size_t LENGTH>
	inline const bool Array<T, LENGTH>::Contains(const T& aData) const
	{
		for (size_t i = 0; i < LENGTH; i++)
		{
			if (m_Data[i] == aData)
			{
				return true;
			}
		}
		
		return false;
	}

	template<typename T, size_t LENGTH>
	inline const T& Array<T, LENGTH>::operator[](const size_t aIndex) const
	{
		assert(aIndex < LENGTH);

		return m_Data[aIndex];
	}

	template<typename T, size_t LENGTH>
	inline T& Array<T, LENGTH>::operator[](const size_t aIndex)
	{
		assert(aIndex < LENGTH);

		return m_Data[aIndex];
	}

	template<typename T, size_t LENGTH>
	inline const size_t Array<T, LENGTH>::Size() const
	{
		return LENGTH;
	}

}

