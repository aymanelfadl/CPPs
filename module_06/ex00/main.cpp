#include "ScalarConverter.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
        return 0;
    }
    std::cout << "Error: need just one argument." << std::endl;
}