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
    if (!this->getIsSigned())
        throw AForm::FromNotSigned();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
    {
        std::srand(time(0));
        const int flip = std::rand() % 2;

        if (flip)
            std::cout << this->target << " has been robotomized successfull." << std::endl;
        else
            std::cout << "the robotomy failed." << std::endl;
    }
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