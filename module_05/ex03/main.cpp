#include "Intern.h"

int main() {
    std::cout << "=== CPP05 - Exercise 03: Intern Tests ===" << std::endl;
    
    try {
        Intern someRandomIntern;
        
        Bureaucrat lowBureaucrat("LowGrade", 150);
        Bureaucrat midBureaucrat("MidGrade", 50);
        Bureaucrat highBureaucrat("HighGrade", 1);
        
        std::cout << "\n--- Test 1: Valid form creation ---" << std::endl;

        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
        
        if (rrf) {
            std::cout << *rrf << std::endl;
            midBureaucrat.signForm(*rrf);
            midBureaucrat.executeForm(*rrf);
            delete rrf; 
        }
        
        if (scf) {
            std::cout << *scf << std::endl;
            midBureaucrat.signForm(*scf);
            midBureaucrat.executeForm(*scf);
            delete scf;
        }
        
        if (ppf) {
            std::cout << *ppf << std::endl;
            highBureaucrat.signForm(*ppf); 
            highBureaucrat.executeForm(*ppf);
            delete ppf;
        }
        
        std::cout << "\n--- Test 2: Invalid form creation ---" << std::endl;
        try {
            AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
            delete invalidForm; 
        } catch (const std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n--- Test 3: Case sensitivity test ---" << std::endl;
        try {
            AForm* form1 = someRandomIntern.makeForm("Robotomy Request", "Bender"); // Should fail
            delete form1;
        } catch (const std::exception &e) {
            std::cout << "Exception caught for 'Robotomy Request': " << e.what() << std::endl;
        }
        
        try {
            AForm* form2 = someRandomIntern.makeForm("SHRUBBERY CREATION", "garden"); // Should fail
            delete form2;
        } catch (const std::exception &e) {
            std::cout << "Exception caught for 'SHRUBBERY CREATION': " << e.what() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}