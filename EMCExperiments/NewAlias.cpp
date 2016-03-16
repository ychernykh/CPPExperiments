#include <iostream>
#include <vector>

// New C++11 style
template<typename T>
using NewVector = std::vector<T>;

// Old C++98 stype (using dependet type)
template<typename T>
struct OldVector
{
    typedef std::vector<T> type;
};

// Dependent template.
template<typename T>
struct A
{
    // Simple new style
    NewVector<T>                m_new;

    // Old verbose style
    typename OldVector<T>::type m_old;
};

int main()
{
    NewVector<int>       vec1{1, 2, 3};
    OldVector<int>::type vec2{1, 2, 3};

    A<int> a1{};

    return 0;
}
