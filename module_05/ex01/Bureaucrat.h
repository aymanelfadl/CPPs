#pragma once

#include <iostream>

class Bureaucrat {
    
    const std::string name;
    int grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
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

        // TODO:: to implemnt
        void signForm();
};