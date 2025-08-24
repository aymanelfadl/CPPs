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

class B 
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
    int x = 5;
    cout << "my x is :" << this->x << endl;
}

class c : virtual public B , public A {

};

int main()
{
    C c;

}
