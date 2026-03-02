#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("Default Target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialForm", 25, 5), target(target) {}

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
    (void)executor;
    std::cout << target << " has been pardoned.\n";
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