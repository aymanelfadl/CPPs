#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;


    std::cout << "Variable Adress: " << &brain << std::endl;
    std::cout << "Pointer Adress: " << &stringPTR << std::endl;
    std::cout << "Reference Adress: " << &stringREF << std::endl;

    std::cout << "Variable Value: " << brain << std::endl;
    std::cout << "Pointer Value: " << *stringPTR << std::endl;
    std::cout << "Referebce Value: " << stringREF << std::endl;

    
}