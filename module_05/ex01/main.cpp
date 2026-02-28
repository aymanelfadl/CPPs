#include "Bureaucrat.h"


int main() {

    try {
        Bureaucrat b("ayman", 1);
        b.decrement();
        std::cout << b.getName() << " " << b.getGrade() << std::endl;
    }catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}