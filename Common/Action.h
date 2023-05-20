#pragma once

namespace simpletl
{
    template<typename... Args>
    class Action
    {
    public:
        using FunctionType = void(*)(Args...);
    public:

        Action(FunctionType m_Function) : m_Function(m_Function) {}

        void operator()(Args... args) const
        {
            m_Function(args...);
        }

    private:
        FunctionType m_Function;

	};
}