#include <iostream>
#include <iomanip>

class A
{
    int b;
    int a;

public:
    A() : a(1), b(a)
    {
        std::cout << "a :" << a << ", b: " << b << std::endl;
    }
    ~A()
    {
        std::cout << "hey" << std::endl;
    }
};

int main()
{
    {
        A obj;
    }
    int a = 9;

    std::cin >> a;
    if (std::cin.fail())
        return -1;
    std::cout << std::setw(10) << std::right << a << std::endl;
    return 0;
}