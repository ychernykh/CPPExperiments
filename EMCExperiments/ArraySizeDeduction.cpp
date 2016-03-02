#include <iostream>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}

int globalArray[99];

int main()
{
    double localArray[77];
    float sameSizedArray[arraySize(localArray)]; // evaluates at compile time;

    std::cout << "globalArray size = " << arraySize(globalArray) << std::endl;
    std::cout << "localArray size = " << arraySize(localArray) << std::endl;
    std::cout << "sameSizedArray size = " << arraySize(sameSizedArray) << std::endl;

    return 0;
}
