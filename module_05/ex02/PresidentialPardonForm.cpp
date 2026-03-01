#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : Form() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj), target(obj.target) {}

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

    char isSigned = obj.getIsSigned() ? 'y' : 'n';

    os << "Form: " << obj.getFormName()
       << "target: " << obj.getTarget()
       << ", Signed: " << isSigned
       << ", Grade to sign: " << obj.getGradeToSign()
       << ", Grade to execute: " << obj.getGradeToExecute();
    return os;
}