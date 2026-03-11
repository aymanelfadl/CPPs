#include "Array.h"

class A {
public:
    int a;
    A() : a(0) {}
    A(int val) : a(val) {}
};

int main()
{

    Array<A> a;
    std::cout << "default size: " << a.size() << std::endl;

    Array<A> b(5);
    for (size_t i = 0; i < b.size(); i++)
        b[i] = A(i * 10);

    Array<A> c = b;
    c[0].a = 999;
    std::cout << "b[0].a should be 0:   " << b[0].a << std::endl;
    std::cout << "c[0].a should be 999: " << c[0].a << std::endl;

    Array<A> d;
    d = b;
    d[1].a = 888;
    std::cout << "b[1].a should be 10:  " << b[1].a << std::endl;
    std::cout << "d[1].a should be 888: " << d[1].a << std::endl;

    Array<A>& ref = b;
    b = ref;
    std::cout << "b[4].a after self-assign: " << b[4].a << std::endl;
    
    try {
        b[10] = A(1);
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    try {
        b[-1] = A(1);
    } catch (const std::out_of_range& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}