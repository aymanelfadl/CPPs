#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
    std::cout << "=== EXERCISE 02: Abstract Forms and Execution Tests ===" << std::endl;

    {
        std::cout << "\n--- Test 1: ShrubberyCreationForm ---" << std::endl;
        try
        {
            Bureaucrat bob("Bob", 60);        
            Bureaucrat alex("Alex", 149);    
            Bureaucrat intern("Intern", 150); 

            ShrubberyCreationForm form("form");
            std::cout <<  std::endl;
            std::cout << form << std::endl;
            std::cout <<  std::endl;


            intern.signForm(form);
            alex.signForm(form);
            bob.signForm(form);


            intern.executeForm(form);
            alex.executeForm(form);
            bob.executeForm(form);
            
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 2: RobotomyRequestForm ---" << std::endl;
        try
        {
            Bureaucrat bob("Bob", 40);        
            Bureaucrat alex("Alex", 60);    
            Bureaucrat intern("Intern", 150); 

            RobotomyRequestForm form("alice");
            std::cout <<  std::endl;
            std::cout << form << std::endl;
            std::cout <<  std::endl;


            intern.signForm(form);
            alex.signForm(form);
            bob.signForm(form);


            intern.executeForm(form);
            alex.executeForm(form);
            bob.executeForm(form);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 3: PresidentialPardonForm ---" << std::endl;
        try
        {
            Bureaucrat president("president", 2);        
            Bureaucrat alex("Alex", 20);    
            Bureaucrat intern("Intern", 100); 


            PresidentialPardonForm form("criminal");
            std::cout <<  std::endl;
            std::cout << form << std::endl;
            std::cout <<  std::endl;

            intern.signForm(form);
            alex.signForm(form);
            president.signForm(form);


            intern.executeForm(form);
            alex.executeForm(form);
            president.executeForm(form);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 5: Execution Without Signing ---" << std::endl;
        try
        {
            Bureaucrat alex("Alex", 1);

            PresidentialPardonForm form;

            alex.executeForm(form);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught expected exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 6: Copy and Assignment Tests ---" << std::endl;
        try
        {
            PresidentialPardonForm original1;
            RobotomyRequestForm original2;
            ShrubberyCreationForm original3;

            std::cout << "before copy : " <<std::endl;
            std::cout << original1 << std::endl;
            std::cout << original2 << std::endl;
            std::cout << original3 << std::endl;
            std::cout <<  std::endl;

            PresidentialPardonForm copy1(original1);
            RobotomyRequestForm copy2(original2);
            ShrubberyCreationForm copy3(original3);

            std::cout << "after copy : " <<std::endl;
            std::cout << copy1 << std::endl;
            std::cout << copy2 << std::endl;
            std::cout << copy3 << std::endl;
            std::cout <<  std::endl;


            PresidentialPardonForm c1;
            RobotomyRequestForm c2;
            ShrubberyCreationForm c3;

            c1 = copy1;
            c2 = copy2;
            c3 = copy3;

            std::cout << "after copy 2 : " <<std::endl;
            std::cout << c1 << std::endl;
            std::cout << c2 << std::endl;
            std::cout << c3 << std::endl;
            std::cout <<  std::endl;

        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 7: Polymorphism Test ---" << std::endl;
        try
        {
            Bureaucrat ceo("Boss", 1);

            AForm* forms[3];
            forms[0] = new PresidentialPardonForm("prisoner");
            forms[1] = new RobotomyRequestForm("target");
            forms[2] = new ShrubberyCreationForm("garden");

            std::cout << "\nsigning all forms:" << std::endl;
            for (int i = 0; i < 3; i++)
            {
                std::cout << *forms[i] << std::endl;
                ceo.signForm(*forms[i]);
            }

            std::cout << "\nExecuting all forms:" << std::endl;
            for (int i = 0; i < 3; i++)
            {
                ceo.executeForm(*forms[i]);
            }

            for (int i = 0; i < 3; i++)
            {
                delete forms[i];
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}