#pragma once 

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class Form {
    private:
        
        const std::string formName;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:

        Form();
        Form(const std::string& formName, const int gradeToSign, const int gradeToExecute);
        Form(const Form& obj);
        ~Form();

        Form& operator=(const Form &obj);

        const std::string& getFormName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const; 

        void beSigned(const Bureaucrat& b);

        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw();
        };

        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form &form);
