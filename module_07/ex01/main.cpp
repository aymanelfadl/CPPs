#include "iter.h"

void printInt(const int& value)
{
    std::cout << value << " ";
}

void printStr(const std::string& value)
{
    std::cout << value << " ";
}

void increment(int& x)
{
    x++;
}

void upper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}

int main()
{
    int list[] = {1,2,3,4,5};
    
    iter(list, sizeof(list)/sizeof(int), increment);
    iter(list, sizeof(list)/sizeof(int), printInt);
    std::cout << std::endl;
    std::string strs[] = {"1337", "is", "the", "best"};
    iter(strs, sizeof(strs)/sizeof(std::string), upper);
    iter(strs, sizeof(strs)/sizeof(std::string), printStr);
    std::cout << std::endl;

}