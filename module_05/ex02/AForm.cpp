#include "AForm.h"

Form::Form()
    : formName("DefaultForm"), isSigned(false),
      gradeToSign(MINGRADE), gradeToExecute(MINGRADE)
{
}

Form::Form(const std::string& formName,
           const int gradeToSign,
           const int gradeToExecute) : formName(formName),
                                       isSigned(false),
                                       gradeToSign(gradeToSign),
                                       gradeToExecute(gradeToExecute)
{
    if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &obj) : formName(obj.formName),
                              isSigned(obj.isSigned),
                              gradeToSign(obj.gradeToSign),
                              gradeToExecute(obj.gradeToExecute)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &obj)
{
    if (this == &obj)
        return *this;

    this->isSigned = obj.isSigned;

    return *this;
}

void Form::beSigned(const Bureaucrat &b)
{

    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();

    isSigned = true;
}

const std::string &Form::getFormName() const
{
    return formName;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{

    char isSigned = form.getIsSigned() ? 'y' : 'n';

    os << "Form: " << form.getFormName()
       << ", Signed: " << isSigned
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute();

    return os;
}