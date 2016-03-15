#include <iostream>

class A
{
public:

    A(int value)
    : m_value{value}
    {
        std::cout << "A(" << value << ")" << std::endl;
    }

    ~A() = default;

    A(const A&) = default;

    A& operator = (const A&) = default;

private:

    int m_value;
};

class B
{
public:

    B()
    : m_first{777}
    {
        std::cout << "B()" << std::endl;
    }

    B(int f, int s)
    : m_first{f}
    , m_second{s}
    {
        std::cout << "B(" << f << ", " << s << ")" << std::endl;
    }

    ~B() = default;

    B(const B&) = default;

    B& operator = (const B&) = default;

private:

    A m_first{1};

    A m_second{2};
};

class C
{
public:

    C(int i, bool b)
    {
        std::cout << "C(int i = " << i << ", bool b = " << b << ")" << std::endl;
    }

    C(int i, double d)
    {
        std::cout << "C(int i = " << i << ", double b = " << d << ")" << std::endl;
    }

    C(std::initializer_list<long double> iList)
    {
        std::cout << "C({ ";
        for (auto& e : iList)
        {
            std::cout << e << " ";
        }
        std::cout << "})" << std::endl;
    }

    ~C() = default;

    C(const C&) = default;

    C& operator = (const C&) = default;

    C(C&&) = default;

    operator bool() const
    {
        return true;
    }

private:
};

int main()
{
    std::cout << "Inner init" << std::endl;
    B b1{7, 9};
    B b2{};
    std::cout << "Initializer list issue" << std::endl;
    
    C c1{1, true};
    C c2{2, 3.0};
    C c3{true, false};

    C c4{c3}; // Fuck!!! no copy constructor.
    C c5{std::move(c3)}; // Fuck!!! no move constructor.

    return 0;
}
