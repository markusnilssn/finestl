#pragma once

namespace stl
{
    template<typename ReturnT, typename... Args>
    class Func
    {
    public:
        using FunctionType = ReturnT(*)(Args...);

    public:
        Func();
        Func(FunctionType aFunction);

        ReturnT Invoke(Args... args);
        ReturnT operator()(Args... args);

    private:
        FunctionType m_Function;
    };

    template<typename ReturnT, typename ...Args>
    inline Func<ReturnT, Args...>::Func()
        : m_Function(nullptr)
    {
    }

    template<typename ReturnT, typename ...Args>
    inline Func<ReturnT, Args...>::Func(FunctionType aFunction)
        : m_Function(aFunction)
    {
    }

    template<typename ReturnT, typename ...Args>
    inline ReturnT Func<ReturnT, Args...>::Invoke(Args ...args)
    {
        if (m_Function == null)
            return ReturnT();

        return m_Function(args...);
    }

    template<typename ReturnT, typename ...Args>
    inline ReturnT Func<ReturnT, Args...>::operator()(Args ...args)
    {
        return Invoke(args...);
    }
}