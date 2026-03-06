#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

int main () {
    Base* obj = generate();

    std::cout << "Random object created.\n";

    identify(*obj);
    
    identify(obj);

    delete obj;

    return 0;
}