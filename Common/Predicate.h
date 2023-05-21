#pragma once

namespace stl
{
    template<typename T>
    class Predicate
    {
    public:
        using FunctionType = bool(*)(T);

        Predicate(FunctionType m_Function) 
            : m_Function(m_Function) 
        {
        
        }

        bool operator()(T arg) const
        {
            return m_Function(arg);
        }

    private:
        FunctionType m_Function;
    };
}