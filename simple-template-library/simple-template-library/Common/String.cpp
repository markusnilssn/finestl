#include "String.h"
#include <cctype> 
#include <cstring> 

const bool stl::String::IsNullOrEmpty(const String& aString)
{
	if (aString.Data() == nullptr || aString.Length() == 0)
	{
		return true;
	}

	return false;
}

stl::String::String()
	: m_Buffer(nullptr)
	, m_Length(0)
{
	m_Buffer = new char[1];
	m_Length = 0;
}

stl::String::String(const char* aString)
	: m_Buffer(nullptr)
	, m_Length(0)
{
	if (aString != nullptr)
	{
		m_Length = strlen(aString);
		m_Buffer = new char[m_Length + 1];
		strcpy_s(m_Buffer, m_Length + 1, aString);
	}
}

stl::String::String(const String& aString) 
	: m_Buffer(nullptr)
	, m_Length(0)
{
	auto data = aString.Data();
	if (data != nullptr)
	{
		m_Length = aString.Length();
		m_Buffer = new char[m_Length + 1];
		strcpy_s(m_Buffer, m_Length + 1, aString.Data());
	}
}

stl::String::String(String&& aString)
	: m_Buffer(nullptr)
	, m_Length(0)
{
	auto data = aString.Data();
	if (data != nullptr)
	{
		m_Length = aString.Length();
		m_Buffer = new char[m_Length + 1];
		strcpy_s(m_Buffer, m_Length + 1, aString.Data());
	}
}

stl::String::~String()
{
	delete[] m_Buffer;
}

stl::String& stl::String::operator=(const String& aString)
{
	if (this != &aString)
	{
		delete[] m_Buffer;
		m_Length = aString.Length();
		m_Buffer = new char[m_Length + 1];
		strcpy_s(m_Buffer, m_Length + 1, aString.Data());
	}

	return *this;
}

stl::String& stl::String::operator=(String&& aString)
{
	if (this != &aString)
	{
		delete[] m_Buffer;
		m_Length = aString.Length();
		m_Buffer = new char[m_Length + 1];
		strcpy_s(m_Buffer, m_Length + 1, aString.Data());
	}

	return *this;
}

const char& stl::String::operator[](const size_t aIndex) const
{
	if (aIndex < m_Length)
	{
		return m_Buffer[aIndex];
	}
	else
	{
		return m_Buffer[m_Length];
	}
}

char& stl::String::operator[](const size_t aIndex)
{
	if (aIndex < m_Length)
	{
		return m_Buffer[aIndex];
	}
	else
	{
		return m_Buffer[m_Length];
	}
}

const char& stl::String::ElementAt(const size_t aIndex) const
{
	if (aIndex < m_Length)
	{
		return m_Buffer[aIndex];
	}
	else
	{
		return m_Buffer[m_Length];
	}
}

char& stl::String::ElementAt(const size_t aIndex)
{
	if (aIndex < m_Length)
	{
		return m_Buffer[aIndex];
	}
	else
	{
		return m_Buffer[m_Length];
	}
}

const bool stl::String::Contains(const char aLetter)
{
	for (size_t i = 0; i < m_Length; i++)
	{
		if (m_Buffer[i] == aLetter)
		{
			return true;
		}
	}

	return false;
}

const bool stl::String::Contains(const String& aString)
{
	const char* substr = aString.m_Buffer; // Get the buffer of the input string
	std::size_t substrLength = aString.m_Length; // Get the length of the input string

	const char* found = std::strstr(m_Buffer, substr); // Search for the substring

	return (found != nullptr); // Return true if the substring is found, false otherwise
}

const stl::String stl::String::ToUpper()
{
	stl::String returnValue = *this;
	for (size_t i = 0; i < m_Length; i++)
	{
		returnValue[i] = std::toupper(m_Buffer[i]);
	}

	return returnValue;
}

const stl::String stl::String::ToLower()
{
	stl::String returnValue = *this;
	for (size_t i = 0; i < m_Length; i++)
	{
		returnValue[i] = std::tolower(m_Buffer[i]);
	}
	
	return returnValue;
}

const size_t stl::String::Length() const
{
	return m_Length;
}

const char* stl::String::Data() const
{
	return m_Buffer;
}
