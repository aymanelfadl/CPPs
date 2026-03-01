#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name("Default"), grade(MINGRADE) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name) {
    
    if (grade < MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MINGRADE)
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
    if (--this->grade < MAXGRADE)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement() {
    if (++this->grade > MINGRADE)
        throw Bureaucrat::GradeTooLowException();
} 


const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b) {
    os << "bureaucrat name: " << b.getName() << ", grade: " << b.getGrade();
    return os;
}
 

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getFormName() << std::endl;
    }
    catch (const Form::GradeTooLowException& e) {
        std::cout << name << " couldn't sign " << form.getFormName() << " because grade too low" << std::endl;
    }
}