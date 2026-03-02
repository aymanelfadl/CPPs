#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm",72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : 
    AForm(obj), target(obj.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
    
    if (this == &obj)
        return *this;
 
    this->target = obj.target;
    
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    (void)executor;
    std::cout << target << " has been shit serwalo.\n";
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj){

    const char isSigned = obj.getIsSigned() ? 'y' : 'n';

    os << "Form: " << obj.getFormName() 
       << ", Target: " << obj.getTarget()
       << ", Signed: " << isSigned
       << ", Grade to sign: " << obj.getGradeToSign()
       << ", Grade to execute: " << obj.getGradeToExecute();

    return os;
}