#include "Array.h"

class A {
public:
    int a;
    A() : a(0) {}
    A(int val) : a(val) {}
};

int main() {
    try {
        Array<int> a;
        std::cout << "Size of a: " << a.size() << std::endl;

        Array<int> b(5);
        std::cout << "Size of b: " << b.size() << std::endl;

        for (size_t i = 0; i < b.size(); i++)
            b[i] = i * 10;

        for (size_t i = 0; i < b.size(); i++)
            std::cout << "b[" << i << "] = " << b[i] << std::endl;

        Array<int> c = b;
        c[0] = 999;
        std::cout << "b[0] after modifying c: " << b[0] << std::endl;
        std::cout << "c[0] after modifying c: " << c[0] << std::endl;

        Array<int> d;
        d = b;
        d[1] = 888; 
        std::cout << "b[1] after modifying d: " << b[1] << std::endl; 
        std::cout << "d[1] after modifying d: " << d[1] << std::endl;

        try {
            int x = b[10];
            std::cout << x << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Array<A> arrA(3);
        std::cout << "\nArray<A> of size: " << arrA.size() << std::endl;

        for (size_t i = 0; i < arrA.size(); i++)
            arrA[i] = A(i * 100);

        for (size_t i = 0; i < arrA.size(); i++)
            std::cout << "arrA[" << i << "].a = " << arrA[i].a << std::endl;

        Array<A> arrB = arrA;
        arrB[0].a = 999;
        std::cout << "arrA[0].a after modifying arrB: " << arrA[0].a << std::endl;
        std::cout << "arrB[0].a after modifying arrB: " << arrB[0].a << std::endl;
        arrB[arrA.size()] = 1001;

    } catch (const std::exception& e) {
        std::cout << "Exception in Array<A>: " << e.what() << std::endl;
    }

    return 0;
}