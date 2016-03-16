#include <iostream>

void f(bool b)
{
    std::cout << "f(bool b = " << b << ")" << std::endl; 
}

void f(int i)
{
    std::cout << "f(int i = " << i << ")" << std::endl;
}

void f(void* p)
{
    std::cout << "f(void* p = " << p << ")" << std::endl;
}

// Not ok, void f(void* p) and void f(int* pi) will conflict.
//void f(int* pi)
//{
//    std::cout << "f(int* pi = " << pi << ")" << std::endl;
//}

int main()
{
    // Ok bool
    f(false);

    // Ok int
    f(0);

    // Compilation fail, call is ambiguous.
    //f(NULL);

    // Not good, but explicitly call void*
    f(static_cast<void*>(NULL));

    // OK void*
    f(nullptr);

    // nullptr have type std::nullptr_t, and we can define new NULL.
    std::nullptr_t newNull{};

    // Same as with nullptr
    f(newNull);

    // Can't asign to std::nullptr_t any poiner value.
    //int t = 7;
    //newNull = static_cast<std::nullptr_t>(&t);

    return 0;
}
