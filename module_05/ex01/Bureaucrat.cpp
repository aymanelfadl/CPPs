#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name) {
    
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj) {
    
    if (this == &obj)
        return *this;

    this->grade = obj.grade;
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::increment() {
    this->grade--;
}

void Bureaucrat::decrement() {
    this->grade++;
} 


const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "too low";
}
const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "too heigh";
}

