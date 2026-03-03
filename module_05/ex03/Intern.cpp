#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern& src) { 
    (void)src;
}

Intern& Intern::operator=(const Intern& src) { 
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    
    const std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    int i = 0;
    while (i < 3 && names[i] != formName)
        i++;

    if (i == 0) return new PresidentialPardonForm(target);
    if (i == 1) return new RobotomyRequestForm(target);
    if (i == 2) return new ShrubberyCreationForm(target);

    std::cout << "Intern: unknown form name: " << formName << std::endl;
    return NULL;
}