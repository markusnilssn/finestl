#pragma once
#include "ICollection.h"
#include <initializer_list>

#include <functional>


namespace stl
{
	template <typename T>
	class List final : ICollection<T>
	{
	public:
		 List();
		 List(const size_t aCapacity);
		 List(std::initializer_list<T> aList);
		 ~List();

		 List(const List&) = delete;
		 List& operator=(const List&) = delete;

		 List(List&&) = delete;
		 List& operator=(List&&) = delete;

		 void Add(const T& aData);
		 void Add(T&& aData);

		 void Remove(const T& aData);
		 void RemoveAt(const size_t aIndex);

		 const bool Contains(const T& aData) const;

		 void Clear();

		 const T& operator[](const size_t aIndex) const;
		 T& operator[](const size_t aIndex);

		 const size_t Size() const;
		 const size_t Capacity() const;

		 const bool IsEmpty() const;
	
	private: 
		T* m_Data;
		size_t m_Size;
		size_t m_Capacity;

	};

	template<typename T>
	inline List<T>::List()
	{
		m_Data = new T[4];
		m_Size = 0;
		m_Capacity = 4;
	}

	template<typename T>
	inline List<T>::List(const size_t aCapacity)
	{
		m_Data = new T[aCapacity];
		m_Size = 0;
		m_Capacity = aCapacity;
	}

	template<typename T>
	inline List<T>::List(std::initializer_list<T> aList)
	{
		m_Data = new T[aList.size()];
		m_Size = 0;
		m_Capacity = aList.size();

		for (auto& data : aList)
		{
			Add(data);
		}
	}

	template<typename T>
	inline List<T>::~List()
	{
		delete[] m_Data;
	}

	template<typename T>
	inline void List<T>::Add(const T& aData)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;
			T* newData = new T[m_Capacity];
			for (size_t i = 0; i < m_Size; i++)
			{
				newData[i] = m_Data[i];
			}
			delete[] m_Data;
			m_Data = newData;
		}
		m_Data[(int)m_Size] = aData;
		m_Size++;
	}

	template<typename T>
	inline void List<T>::Add(T&& aData)
	{
		if (m_Size == m_Capacity)
		{
			m_Capacity *= 2;
			T* newData = new T[m_Capacity];
			for (size_t i = 0; i < m_Size; i++)
			{
				newData[i] = m_Data[i];
			}
			delete[] m_Data;
			m_Data = newData;
		}
		m_Data[(int)m_Size] = std::move(aData);
		m_Size++;
	}

	template<typename T>
	inline void List<T>::RemoveAt(const size_t aIndex)
	{
		if (aIndex >= m_Size)
		{
			return;
		}
		for (size_t i = aIndex; i < m_Size - 1; i++)
		{
			m_Data[i] = m_Data[i + 1];
		}
		m_Size--;
	}
	
	template<typename T>
	inline void List<T>::Remove(const T& aData)
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Data[i] == aData)
			{
				RemoveAt(i);
				return;
			}
		}
	}

	template<typename T>
	inline const bool List<T>::Contains(const T& aData) const
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			if (m_Data[i] == aData)
			{
				return true;
			}
		}

		return false;
	}

	template<typename T>
	inline void List<T>::Clear()
	{
		m_Size = 0;
	}

	template<typename T>
	inline const T& List<T>::operator[](const size_t aIndex) const
	{
		return m_Data[aIndex];
	}

	template<typename T>
	inline T& List<T>::operator[](const size_t aIndex)
	{
		return m_Data[aIndex];
	}

	template<typename T>
	inline const size_t List<T>::Size() const
	{
		return m_Size;
	}

	template<typename T>
	inline const size_t List<T>::Capacity() const
	{
		return m_Capacity;
	}

	template<typename T>
	inline const bool List<T>::IsEmpty() const
	{
		return m_Size == 0;
	}
}

