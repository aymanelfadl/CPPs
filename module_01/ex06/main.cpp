#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: too many complains" << std::endl;
        return 1;
    }

    std::string complians[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t index = 0;
    while (index < 4)
    {
        if (complians[index] == argv[1])
            break;
        index++;
    }
    Harl h;

    switch (index)
    {
    case 0:
        std::cout << "[ " << complians[index] << " ]" << std::endl;
        h.complain(complians[index]);
        index++;
        // fall through
    case 1:
        std::cout << "[ " << complians[index] << " ]" << std::endl;
        h.complain(complians[index]);
        index++;
        // fall through
    case 2:
        std::cout << "[ " << complians[index] << " ]" << std::endl;
        h.complain(complians[index]);
        index++;
        // fall through
    case 3:
        std::cout << "[ " << complians[index] << " ]" << std::endl;
        h.complain(complians[index]);
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
   return 0;
}