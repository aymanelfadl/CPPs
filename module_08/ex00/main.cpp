#include "easyfind.h"

int main() {
    
    int arr[] = {1, 2, 3, 4, 5};

    std::vector<int> c(arr, arr + sizeof(arr)/sizeof(int));
    try {
    
        std::vector<int>::iterator it = easyfind(c, 10);
        std::cout << "Found: " << *it << std::endl;
    
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> l;
    std::vector<int>::iterator it = c.begin();
    while (it != c.end())
    {
        l.push_back(*it);
        it++;
    }
    try
    {   
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "Found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}