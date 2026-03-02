#include "AForm.h"

AForm::AForm()
    : formName("DefaultForm"), isSigned(false),
      gradeToSign(MINGRADE), gradeToExecute(MINGRADE)
{
}

AForm::AForm(const std::string& formName,
           const int gradeToSign,
           const int gradeToExecute) : formName(formName),
                                       isSigned(false),
                                       gradeToSign(gradeToSign),
                                       gradeToExecute(gradeToExecute)
{
    if (gradeToSign < MAXGRADE || gradeToExecute < MAXGRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > MINGRADE || gradeToExecute > MINGRADE)
        throw AForm::GradeTooLowException();
}

    AForm::AForm(const AForm &obj) : formName(obj.formName),
                              isSigned(obj.isSigned),
                              gradeToSign(obj.gradeToSign),
                              gradeToExecute(obj.gradeToExecute)
{
}

    AForm::~AForm() {}

    AForm &AForm::operator=(const AForm &obj)
{
    if (this == &obj)
        return *this;

    this->isSigned = obj.isSigned;

    return *this;
}

void AForm::beSigned(const Bureaucrat &b)
{

    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();

    isSigned = true;
}

const std::string &AForm::getFormName() const
{
    return formName;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    const char isSigned = form.getIsSigned() ? 'y' : 'n';

    os << "Form: " << form.getFormName()
       << ", Signed: " << isSigned
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute();

    return os;
}