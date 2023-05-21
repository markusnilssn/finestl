#pragma once

#include "Macros.h"
#include <memory>
#include "Action.h"

#include "List.h"

namespace stl
{
	template<typename T>
	class ObservableList final
	{
	public:
		ObservableList();
		ObservableList(const size_t aCapacity);
		ObservableList(std::initializer_list<T> aList);
		~ObservableList();

		ObservableList(const ObservableList&) = delete;
		ObservableList& operator=(const ObservableList&) = delete;

		ObservableList(ObservableList&&) = delete;
		ObservableList& operator=(ObservableList&&) = delete;

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

		void Watch(const Action<List<T>>& aCallback);
		void Unwatch(const Action<List<T>>& aCallback);

		void Batch();
		void Commit();

	private:
		List<T> m_List;
		List<Action<T>> m_Watchers; // ;) 

		bool m_IsBatching;
		void Invoke();
	};

	template<typename T>
	inline ObservableList<T>::ObservableList()
	{
		m_List = List<T>();
	}

	template<typename T>
	inline ObservableList<T>::ObservableList(const size_t aCapacity)
	{
		m_List = List<T>(aCapacity);
	}

	template<typename T>
	inline ObservableList<T>::ObservableList(std::initializer_list<T> aList)
	{
		m_List = List<T>(aList);
	}
	
	template<typename T>
	inline ObservableList<T>::~ObservableList()
	{	
		m_List.Clear();
		m_Watchers.Clear();
	}
	
	template<typename T>
	inline void ObservableList<T>::Add(const T& aData)
	{
		m_List.Add(aData);
		Invoke();
	
	}
	
	template<typename T>
	inline void ObservableList<T>::Add(T&& aData)
	{
		m_List.Add(aData);
		Invoke();
	}

	template<typename T>
	inline void ObservableList<T>::Remove(const T& aData)
	{
		m_List.Remove(aData);
		Invoke();
	}
	
	template<typename T>
	inline void ObservableList<T>::RemoveAt(const size_t aIndex)
	{
		m_List.Remove(aIndex);
		Invoke();
	}
	
	template<typename T>
	inline const bool ObservableList<T>::Contains(const T& aData) const
	{
		return m_List.Contains(aData);
	}
	
	template<typename T>
	inline void ObservableList<T>::Clear()
	{
		m_List.Clear();
	}
	
	template<typename T>
	inline const T& ObservableList<T>::operator[](const size_t aIndex) const
	{
		return m_List[aIndex];
	}
	
	template<typename T>
	inline T& ObservableList<T>::operator[](const size_t aIndex)
	{
		return m_List[aIndex];
	}
	
	template<typename T>
	inline const size_t ObservableList<T>::Size() const
	{
		return m_List.Size();
	}
	
	template<typename T>
	inline const size_t ObservableList<T>::Capacity() const
	{
		return m_List.Capacity();
	}
	
	template<typename T>
	inline const bool ObservableList<T>::IsEmpty() const
	{
		return m_List.IsEmpty();
	}

	template<typename T>
	inline void ObservableList<T>::Watch(const Action<List<T>>& aCallback)
	{
		if (aCallback == nullptr)
			return;

		m_Watchers.Add(aCallback);
	}

	template<typename T>
	inline void ObservableList<T>::Unwatch(const Action<List<T>>& aCallback)
	{
		if (aCallback == nullptr)
			return;

		m_Watchers.Remove(aCallback);
	}

	template<typename T>
	inline void ObservableList<T>::Batch()
	{
		m_IsBatching = true;
	}

	template<typename T>
	inline void ObservableList<T>::Commit()
	{
		// fine to skip if
		Invoke();
	}

	template<typename T>
	inline void ObservableList<T>::Invoke()
	{
		if (m_IsBatching)
			return;

		for (int i = 0; i < m_Watchers.Size(); i++)
		{
			if(m_Watchers[i] != nullptr)
				m_Watchers[i](m_List);
		}
	}
}