#include "Harl.hpp"

int main()
{
    Harl h;
    std::string complians[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "nothing"};
    for (size_t i = 0; i < complians->length(); i++)
    {
        h.complain(complians[i]);
    }
}