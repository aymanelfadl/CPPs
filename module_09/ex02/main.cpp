#include "PmergeMe.h"

void printContainer(const std::string &label, const std::vector<int> &c)
{
    std::cout << label;
    for (size_t i = 0; i < c.size(); ++i)
        std::cout << c[i] << (i == c.size() - 1 ? "" : " ");
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> raw;
    for (int i = 1; i < ac; ++i)
    {
        std::string s(av[i]);
        if (s.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        long val = atol(av[i]);
        if (val > 2147483647 || val < 0)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        raw.push_back(static_cast<int>(val));
    }

    std::vector<int> v_input = raw;
    std::deque<int> d_input(raw.begin(), raw.end());

    PmergeMe<std::vector<int> > v_sorter;
    v_sorter.sort(v_input);

    PmergeMe<std::deque<int> > d_sorter;
    d_sorter.sort(d_input);

    printContainer("Before: ", raw);
    printContainer("After:  ", v_sorter.getContainer());

    std::cout << "Time to process a range of " << raw.size() << " elements with std::vector : " << v_sorter.getTime() << " us" << std::endl;
    std::cout << "Time to process a range of " << raw.size() << " elements with std::deque  : " << d_sorter.getTime() << " us" << std::endl;

    return 0;
}