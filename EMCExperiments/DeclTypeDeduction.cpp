#include <iostream>
#include <vector>
#include <deque>
#include <utility>

// Stupid compiler. Available only in C++14
//template<typename Container, typename Index>
//decltype(auto) getValue(Container&& c, Index i)
//{
//    return std::forward<Container>(c)[i];
//}

template<typename Container, typename Index>
auto getValue(Container&& c, Index i) -> decltype(std::forward<Container>(c)[i])
{
    return std::forward<Container>(c)[i];
}

auto getVector()
{
    return std::vector<int>{3, 4, 5};
}

int main()
{
    std::vector<int> vec = {1, 2, 3};
    std::deque<float> dec = {9, 8, 7};

    std::cout << getValue(vec, 1) << std::endl;
    getValue(vec, 1) = 77;
    std::cout << getValue(vec, 1) << std::endl;

    std::cout << getValue(dec, 0) << std::endl;
    getValue(dec, 0) = 77;
    std::cout << getValue(dec, 0) << std::endl;

    std::cout << getValue(getVector(), 1) << std::endl;
    std::cout << getValue(std::vector<double>{1.0, 2.0, 3.0}, 1) << std::endl;

    return 0;
}
