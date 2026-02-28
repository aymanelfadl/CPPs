#include "form.h"


Form::Form() : formName("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150){}

Form::Form(const std::string formName, bool isSigned, const int gradeToSign, const int gradeToExecute)
    : formName(formName), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {}

Form::Form(const Form& obj)
    : formName(obj.formName), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {}

Form::~Form() {}

Fomr::Form& operator=(Form &obj);



