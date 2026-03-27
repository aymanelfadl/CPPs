#include "PmergeMe.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>

template <typename T>
void printContainer(const std::string &label, const T &c)
{
    std::cout << label;
    for (size_t i = 0; i < c.size(); ++i)
    {
        std::cout << c[i];
        if (i != c.size() - 1)
            std::cout << " ";
        else
            std::cout << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe<std::vector<int> > v_sorter(ac, av);
        PmergeMe<std::deque<int> >  d_sorter(ac, av);

        printContainer("Vector before: ", v_sorter.getContainer());
        double v_time = v_sorter.sort();
        printContainer("Vector after:  ", v_sorter.getContainer());

        printContainer("Deque before:  ", d_sorter.getContainer());
        double d_time = d_sorter.sort();
        printContainer("Deque after:   ", d_sorter.getContainer());

        std::cout << "Time to process a range of " << v_sorter.getContainer().size() << " elements with std::vector : " << v_time << " us" << std::endl;

        std::cout << "Time to process a range of " << d_sorter.getContainer().size() << " elements with std::deque  : " << d_time << " us" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}