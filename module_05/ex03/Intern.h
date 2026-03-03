#pragma once

#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern
{
public:
    Intern();
    Intern(Intern const & src);
    Intern & operator=(Intern const & src);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

};
