#pragma once

#include <iostream>
#include "AForm.h"

#define MAXGRADE 1
#define MINGRADE 150

class AForm;

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, const int& grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat &obj);

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };


        void signForm(AForm& form) const;
        void executeForm(AForm const & form) const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);