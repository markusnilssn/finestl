#pragma once
#include <memory>
#include "Macros.h"

namespace simpletl
{
	template <typename T, typename V>
	class Map final
	{ 
	public:
		Map();
		Map(const size_t aCapacity);
		
		~Map();
		
		Map(const Map&) = delete;
		Map& operator=(const Map&) = delete;

		Map(Map&&) = delete;
		Map& operator=(Map&&) = delete;
		
		void Add(const T& aKey, const V& aValue);
		void Add(T&& aKey, V&& aValue);
		
		void Remove(const T& aKey);
		void Remove(const size_t aIndex);
		
		void Clear();
		
		const bool Contains(const T& aKey) const;

		V& ElementAt(const T& aKey);
		const V& ElementAt(const T& aKey) const;
		
		const V& operator[](const T& aKey) const;
		V& operator[](const T& aKey);
		
		const size_t Size() const;
		const size_t Capacity() const;
		
		const bool IsEmpty() const;

	private:
		T* m_Keys;
		V* m_Values;
		size_t m_Size;
		size_t m_Capacity;

	};

	template<typename T, typename V>
	inline Map<T, V>::Map()
	{
		m_Keys = new T[4];
		m_Values = new V[4];

		m_Size = 0;
		m_Capacity = 4;
	}

	template<typename T, typename V>
	inline Map<T, V>::Map(const size_t aCapacity)
	{
		m_Keys = new T[aCapacity];
		m_Values = new V[aCapacity];
		
		m_Size = 0;
		m_Capacity = aCapacity;
	}

	template<typename T, typename V>
	inline Map<T, V>::~Map()
	{
		delete[] m_Keys;
		delete[] m_Values;
	}

	template<typename T, typename V>
	inline void Map<T, V>::Add(const T& aKey, const V& aValue)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;

			T* newKeys = new T[m_Capacity];
			V* newValues = new V[m_Capacity];

			for (size_t i = 0; i < m_Size; i++)
			{
				newKeys[i] = m_Keys[i];
				newValues[i] = m_Values[i];
			}

			delete[] m_Keys;
			delete[] m_Values;

			m_Keys = newKeys;
			m_Values = newValues;
		}

		m_Keys[m_Size] = aKey;
		m_Values[m_Size] = aValue;
		
		m_Size++;
	}

	template<typename T, typename V>
	inline void Map<T, V>::Add(T&& aKey, V&& aValue)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;
			
			T* newKeys = new T[m_Capacity];
			V* newValues = new V[m_Capacity];
			
			for (size_t i = 0; i < m_Size; i++)
			{
				newKeys[i] = m_Keys[i];
				newValues[i] = m_Values[i];
			}

			delete[] m_Keys;
			delete[] m_Values;
			
			m_Keys = newKeys;
			m_Values = newValues;
		}
		m_Keys[m_Size] = std::move(aKey);
		m_Values[m_Size] = std::move(aValue);
		
		m_Size++;
	}
	template<typename T, typename V>
	inline void Map<T, V>::Remove(const T& aKey)
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				m_Keys[i] = m_Keys[m_Size - 1];
				m_Values[i] = m_Values[m_Size - 1];
				m_Size--;
			}
		}
	}

	template<typename T, typename V>
	inline void Map<T, V>::Remove(const size_t aIndex)
	{
		if (aIndex < m_Size)
		{
			m_Keys[aIndex] = m_Keys[m_Size - 1];
			m_Values[aIndex] = m_Values[m_Size - 1];
			m_Size--;
		}
	}

	template<typename T, typename V>
	inline void Map<T, V>::Clear()
	{
		m_Size = 0;
	}

	template<typename T, typename V>
	inline const bool Map<T, V>::Contains(const T& aKey) const
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				return true;
			}
		}

		return false;
	}

	template<typename T, typename V>
	inline V& Map<T, V>::ElementAt(const T& aKey)
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				return m_Values[i];
			}
		}

		return m_Values[0];
	}

	template<typename T, typename V>
	inline const V& Map<T, V>::ElementAt(const T& aKey) const
	{

		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				return m_Values[i];
			}
		}

		return m_Values[0];
	}

	template<typename T, typename V>
	inline const V& Map<T, V>::operator[](const T& aKey) const
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				return m_Values[i];
			}
		}

		return m_Values[0];
	}

	template<typename T, typename V>
	inline V& Map<T, V>::operator[](const T& aKey)
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Keys[i] == aKey)
			{
				return m_Values[i];
			}
		}

		return m_Values[0];
	}

	template<typename T, typename V>
	inline const size_t Map<T, V>::Size() const
	{
		return m_Size;
	}

	template<typename T, typename V>
	inline const size_t Map<T, V>::Capacity() const
	{
		return m_Capacity;
	}

	template<typename T, typename V>
	inline const bool Map<T, V>::IsEmpty() const
	{
		return m_Size == 0;
	}
}