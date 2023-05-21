#pragma once
#include <cstddef>

namespace stl
{
	template <typename T>
	class Queue final
	{
		struct Node
		{
			T value;
			Node* next;
		};

	public:
		Queue();
		~Queue();

		void Push(T& aValue);
		void Push(T&& aValue);

		T& Pop();
		const T& Pop() const;

		T& Peek();
		const T& Peek() const;

		const bool IsEmpty() const;

		const std::size_t Size() const;

	private:
		Node* m_Head;
		Node* m_Tail;

		std.:size_t m_Size;
	};

	template<typename T>
	inline Queue<T>::Queue()
		: m_Head(nullptr)
		, m_Tail(nullptr)
		, m_Size(0)
	{

	}

	template<typename T>
	inline Queue<T>::~Queue()
	{
		while (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->next;

			delete temp;
		}

		m_Size = 0;
	}

	template<typename T>
	inline void Queue<T>::Push(T& aValue)
	{
		Node* newNode = new Node;
		newNode->value = aValue;
		newNode->next = nullptr;

		if (m_Tail != nullptr)
		{
			m_Tail->next = newNode;
			m_Tail = newNode;
		}
		else
		{
			m_Head = newNode;
			m_Tail = newNode;
		}

		++m_Size;
	}

	template<typename T>
	inline void Queue<T>::Push(T&& aValue)
	{
		Node* newNode = new Node;
		newNode->value = aValue;
		newNode->next = nullptr;

		if (m_Tail != nullptr)
		{
			m_Tail->next = newNode;
			m_Tail = newNode;
		}
		else
		{
			m_Head = newNode;
			m_Tail = newNode;
		}

		++m_Size;
	}

	template<typename T>
	inline T& Queue<T>::Pop()
	{
		if (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->next;

			T& value = temp->value;
			delete temp;

			--m_Size;

			return value;
		}

		return T();
	}

	template<typename T>
	inline const T& Queue<T>::Pop() const
	{
		if (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->next;

			T& value = temp->value;
			delete temp;

			--m_Size;

			return value;
		}

		return T();
	}

	template<typename T>
	inline T& Queue<T>::Peek()
	{
		if (m_Head != nullptr)
		{
			auto value = m_Head->value;

			return value;
		}

		return T();
	}

	template<typename T>
	inline const T& Queue<T>::Peek() const
	{
		if (m_Head != nullptr)
		{
			auto value = m_Head->value;

			return value;
		}
	}

	template<typename T>
	inline const bool Queue<T>::IsEmpty() const
	{
		return m_Size == 0;
	}

	template<typename T>
	inline const std::size_t Queue<T>::Size() const
	{
		return m_Size;
	}
}