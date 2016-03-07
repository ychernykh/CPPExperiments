#include <iostream>

#define OLD_C_STRING "Test String"

template<typename T, std::size_t N>
constexpr std::size_t arraySize(const T (&)[N]) noexcept
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

    std::cout << "Len of (as array) '" << OLD_C_STRING << "' = " << arraySize(OLD_C_STRING) << std::endl;
    
    struct Empty {};
    Empty localSArr[arraySize(globalArray)];
    std::cout << "localSArr size = " << arraySize(localSArr) << std::endl;

    return 0;
}
