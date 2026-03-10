#include "iter.h"

void printInt(const int& value)
{
    std::cout << value << std::endl;
}

void printStr(const std::string& value)
{
    std::cout << value << std::endl;
}

void increment(int& x)
{
    x++;
}

int main()
{
    int list[] = {1,2,3,4,5};
    
    iter(list, sizeof(list)/sizeof(int), increment);
    iter(list, sizeof(list)/sizeof(int), printInt);

    std::string strs[] = {"1337", "is", "the", "best"};
    iter(strs, sizeof(strs)/sizeof(std::string), printStr);
}