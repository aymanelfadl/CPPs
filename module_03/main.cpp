#include <iostream>

class  A
{
public:
    int x;
    A(){};
    A(int _x)
    {
        x = _x;
    }
    A& operator=(const A& obj)
    {
        std::cout << "hey";
        x = obj.x;
        return *this;
    }
};



int main()
{
    A a(9);
    A b;

    b = a;

    std::cout << b.x;
}