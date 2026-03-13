#include "Span.h"

int main()
{
    int arr[] = {6, 3, 17, 9, 11};
    
    std::vector<int> c(arr, arr + sizeof(arr) / sizeof(int));

    Span sp = Span(5);

    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);

    sp.addNumber(c.begin(), c.end());
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
 
    return 0;
}