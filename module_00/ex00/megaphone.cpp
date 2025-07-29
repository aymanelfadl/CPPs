#include <string>
#include <iostream>

std::string wrapToUpper(char *str)
{
    std::string result;

    result = "";
    while (*str)
    {
        result += std::toupper((*str));
        str++;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int i;

    if (argc  < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
    i = 1;
    while (i < argc)
    {
        std::cout << wrapToUpper(argv[i]);
        i++;
    }
    std::cout << std::endl;
    return 0;
}