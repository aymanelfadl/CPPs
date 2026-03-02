#pragma once

#include "AForm.h"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    
    public:

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

    std::string getTarget() const;
    void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm& obj);