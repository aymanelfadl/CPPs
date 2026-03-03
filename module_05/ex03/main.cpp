
#include "Intern.h"

int main()
{
    Intern intern;
    AForm* form;

    form = intern.makeForm("presidential pardon", "Arthur");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("robotomy request", "Bender");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("shrubbery creation", "Garden");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("unknown form", "Nobody");
    if (!form)
        std::cout << "No form created" << std::endl;

}