#include <iostream>

class  A
{
private:
    int x;
public:
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
    for(int i = 0 ; i < 9 ; i++)
    {
        for (int i = 0; i < 1; i++)
        {
            std::cout << "hey";
        }
        std::cout << std::endl;
    }
}