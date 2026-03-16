#include "BitcoinExchange.h"

int main(int ac, char **av) {

    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange::processInput(av[1]);
}