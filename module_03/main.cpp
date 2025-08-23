#include <iostream>

using namespace std ;

class A
{
    protected:
        int x;
    
    public:
        A(int _x);
        void setX(int _x);
        int getX(void);
};

A::A(int _x) : x(_x) { }
void A::setX(int _x) { this->x = _x; }
int A::getX(void) { return this->x; }

class B : public A
{
    private:
        int x;
    public:
        B(int _x);
        void hey(void);
};

B::B(int _x): A(_x + 1), x(_x) { };
void B::hey(void)
{
    cout << "my x is :" << this->x << endl;
}



int main()
{
    A objA(10);
    B objB(11);

    cout <<"A: x = " << objA.getX() << endl;
    cout <<"B: x = " << objB.getX() << endl;
    objB.hey();
}
