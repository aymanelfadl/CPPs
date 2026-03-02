#pragma once 

#include <iostream>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm {
    private:
        
        const std::string formName;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:

        AForm();
        AForm(const std::string& formName, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& obj);
        virtual ~AForm();

        AForm& operator=(const AForm &obj);

        const std::string& getFormName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const; 

        void beSigned(const Bureaucrat& b);

        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooLowException : public std::exception {
            public:
                const char * what() const throw();
        };

        class GradeTooHighException : public std::exception {
            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm &form);
