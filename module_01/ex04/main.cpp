#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;

    std::fstream ifStream; 
    ifStream.open(argv[1], std::ios::in | std::ios::out);
    if (!ifStream.is_open())
        return 0;

    std::string word{"hey"};
    ifStream << word;

    return 1;
}
