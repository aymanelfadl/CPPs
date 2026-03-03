#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("Default Target"){}

// EDIT: Fixed form name from "PresidentialForm" to "PresidentialPardonForm"
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this == &obj)
        return *this;
    this->target = obj.target;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{

    const char isSigned = obj.getIsSigned() ? 'y' : 'n';

    os << "Form: " << obj.getFormName()
       << ", target: " << obj.getTarget()
       << ", Signed: " << isSigned
       << ", Grade to sign: " << obj.getGradeToSign()
       << ", Grade to execute: " << obj.getGradeToExecute();
    return os;
}