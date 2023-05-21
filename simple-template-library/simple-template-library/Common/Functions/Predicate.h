#pragma once

namespace stl
{
    template<typename T>
    class Predicate
    {
    public:
        using FunctionType = bool(*)(T);

    public:
        Predicate();
        Predicate(FunctionType aFunction);

        const bool Invoke(T&& aObject);
        const bool Invoke(const T& aObject) const;

        const bool operator()(T&& aObject);
        const bool operator()(const T& aObject) const;

    private:
        FunctionType m_Function;

    };

    template<typename T>
    inline Predicate<T>::Predicate()
		: m_Function(nullptr)
    {

    }

    template<typename T>
    inline Predicate<T>::Predicate(FunctionType aFunction)
       : m_Function(aFunction)
    {

    }

    template<typename T>
    inline const bool Predicate<T>::Invoke(T&& aObject)
    {
        if (m_Function == nullptr)
            return false;

        return m_Function(aObject);
    }

    template<typename T>
    inline const bool Predicate<T>::Invoke(const T& aObject) const
    {
        if (m_Function == nullptr)
            return false;

        return m_Function(aObject);
    }

    template<typename T>
    inline const bool Predicate<T>::operator()(T&& aObject)
    {
        return Invoke(aObject);
    }

    template<typename T>
    inline const bool Predicate<T>::operator()(const T& aObject) const
    {
        return Invoke(aObject);
    }
}