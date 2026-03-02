#pragma once 

#include "AForm.h"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const PresidentialPardonForm& obj);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &obj);