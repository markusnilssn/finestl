#pragma once

namespace simpletl
{
    template<typename ReturnT, typename... Args>
    class Func
    {
    public:
        using FunctionType = ReturnT(*)(Args...);

        Func(FunctionType m_Function) 
            : m_Function(m_Function) 
        {
        
        }

        ReturnT operator()(Args... args) const
        {
           return m_Function(args...);
        }

    private:
        FunctionType m_Function;
    };
}