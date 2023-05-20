#pragma once
#include "Macros.h"
#include <memory>

namespace simpletl
{
	class String
	{
	public:
		static const bool IsNullOrEmpty(const String& aString);

	public:
		String();
		String(const char* aString);
		String(const String& aString);
		String(String&& aString);
		~String();

		String& operator=(const String& aString);
		String& operator=(String&& aString);

		const char& operator[](const size_t aIndex) const;
		char& operator[](const size_t aIndex);
		
		const char& ElementAt(const size_t aIndex) const;
		char& ElementAt(const size_t aIndex);

		const bool Contains(const char aLetter);
		const bool Contains(const String& aString);

		const String ToUpper(); // Copy
		const String ToLower(); // Copy

		const size_t Length() const;

		const char* Data() const;

	private:
		char* m_Buffer;
		std::size_t m_Length;
		
	};
}