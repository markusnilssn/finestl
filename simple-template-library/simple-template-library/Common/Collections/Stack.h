#pragma once
#include <cstddef>

namespace stl
{
	template <typename T>
	class Stack final
	{
		struct Node
		{
			T value;
			Node* next;
		};

	public:
		Stack();
		~Stack();

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
	inline Stack<T>::Stack()
		: m_Head(nullptr),
		m_Tail(nullptr)
	{

	}

	template<typename T>
	inline Stack<T>::~Stack()
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
	inline void Stack<T>::Push(T& aValue)
	{
		Node* node = new Node();
		node->value = aValue;
		node->next = nullptr;
		if (m_Head == nullptr)
		{
			m_Head = node;
		}
		else
		{
			m_Tail->next = node;
		}
		m_Tail = node;
		m_Size++;
	}

	template<typename T>
	inline void Stack<T>::Push(T&& aValue)
	{
		Node* node = new Node();
		node->value = aValue;
		node->next = nullptr;
		if (m_Head == nullptr)
		{
			m_Head = node;
		}
		else
		{
			m_Tail->next = node;
		}
		m_Tail = node;
		m_Size++;
	}

	template<typename T>
	inline T& Stack<T>::Pop()
	{
		if (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->next;

			T value = temp->value;

			delete temp;

			m_Size--;

			return value;
		}
	}

	template<typename T>
	inline const T& Stack<T>::Pop() const
	{
		if (m_Head != nullptr)
		{
			Node* temp = m_Head;
			m_Head = m_Head->next;

			T value = temp->value;

			delete temp;

			m_Size--;

			return value;
		}
	}

	template<typename T>
	inline T& Stack<T>::Peek()
	{
		if (m_Tail != nullptr)
		{
			auto value = m_Tail->value;

			return value;
		}

		return T();
	}

	template<typename T>
	inline const T& Stack<T>::Peek() const
	{
		if (m_Tail != nullptr)
		{
			auto value = m_Tail->value;

			return value;
		}

		return T();
	}

	template<typename T>
	inline const bool Stack<T>::IsEmpty() const
	{
		return m_Size == 0;
	}

	template<typename T>
	inline const std::size_t Stack<T>::Size() const
	{
		return m_Size;
	}
}