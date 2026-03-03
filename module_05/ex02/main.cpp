#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

static void line(const std::string &title)
{
    std::cout << "\n===== " << title << " =====\n";
}

int main()
{

    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        line("PRESIDENTIAL - success path");
        PresidentialPardonForm presidential("Arthur");
        std::cout << presidential << std::endl;
        boss.signForm(presidential);
        intern.executeForm(presidential);
        line("Roboto - success path");
        RobotomyRequestForm robo("ribi");
        std::cout << robo << std::endl;
        boss.signForm(robo);
        intern.executeForm(robo);
        line("shrubbery - success path");
        ShrubberyCreationForm tota("tota");
        std::cout << tota << std::endl;
        boss.signForm(tota);
        boss.executeForm(tota);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}