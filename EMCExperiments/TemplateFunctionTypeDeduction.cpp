#include <iostream>
#include <typeinfo>

class Value
{
public:
    int holder[1024] = {0};
};

template<typename T>
void funcRef(T& param)
{
    std::cout << "funcRef<" << typeid(T).name() << ">(" << typeid(param).name() << ")" << std::endl;
}

template<typename T>
void funcConstRef(const T& param)
{
    std::cout << "funcConstRef<" << typeid(T).name() << ">(" << typeid(param).name() << ")" << std::endl;
}

template<typename T>
void funcVal(T param)
{
    std::cout << "funcVal<" << typeid(T).name() << ">(" << typeid(param).name() << ")" << std::endl;
}

template<typename T>
void funcURef(T&& param)
{
    std::cout << "funcURef<" << typeid(T).name() << ">(" << typeid(param).name() << ")" << std::endl;
}

int main()
{
    Value        value;
    const Value  cValue  = value;
    Value&       rValue  = value;
    const Value& crValue = value;

    funcRef(value);
    funcRef(cValue);
    funcRef(rValue);
    funcRef(crValue);

    funcConstRef(value);
    funcConstRef(cValue);
    funcConstRef(rValue);
    funcConstRef(crValue);

    funcURef(value);
    funcURef(cValue);
    funcURef(rValue);
    funcURef(crValue);

    funcVal(value);
    funcVal(cValue);
    funcVal(rValue);
    funcVal(crValue);

    return 0;
}
