#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"


static void line(const std::string& title)
{
    std::cout << "\n===== " << title << " =====\n";
}

int main() {

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    line("PRESIDENTIAL - success path");
    PresidentialPardonForm presidential("Arthur Dent");
    std::cout << presidential << std::endl;
    boss.signForm(presidential);
    presidential.execute(boss);

    line("PRESIDENTIAL - sign failure");
    PresidentialPardonForm presidentialFail("Ford Prefect");
    intern.signForm(presidentialFail);

    line("ROBOTOMY - success path");
    RobotomyRequestForm robotomy("Marvin");
    std::cout << robotomy << std::endl;
    boss.signForm(robotomy);
    robotomy.execute(boss);

    line("ROBOTOMY - sign failure");
    RobotomyRequestForm robotomyFail("Random User");
    intern.signForm(robotomyFail);

    line("SHRUBBERY - success path");
    ShrubberyCreationForm shrubbery("garden");
    std::cout << shrubbery << std::endl;
    boss.signForm(shrubbery);
    shrubbery.execute(boss);

    line("SHRUBBERY - sign failure");
    ShrubberyCreationForm shrubberyFail("home");
    intern.signForm(shrubberyFail);

    return 0;
}