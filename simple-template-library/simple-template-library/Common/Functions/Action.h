#pragma once

namespace stl
{
    template<typename... Args>
    class Action
    {
    public:
        using FunctionType = void(*)(Args...);

    public:
        Action();
        Action(FunctionType aFunction);

        void Invoke(Args... args);
        void operator()(Args... args);

    private:
        FunctionType m_Function;

    };

    template<typename ...Args>
    inline Action<Args...>::Action()
    {
        m_Function = nullptr;
    }

    template<typename ...Args>
    inline Action<Args...>::Action(FunctionType aFunction)
        : m_Function(aFunction)
    {

    }

    template<typename ...Args>
    inline void Action<Args...>::Invoke(Args ...args)
    {
        if (m_Function != nullptr)
            m_Function(args...);
    }

    template<typename ...Args>
    inline void Action<Args...>::operator()(Args ...args)
    {
        Invoke(args...);
    }
}