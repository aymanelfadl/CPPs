#include "PmergeMe.h"

static void printContainer(const std::string &label, const std::vector<int> &c)
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

static std::vector<int> parse_input(int ac, char **input)
{
    std::vector<int> raw;

    for (int i = 1; i < ac; i++)
    {
        std::string s(input[i]);
        if (s.find_first_not_of("0123456789") != std::string::npos)
            throw "Error";
        long val = std::atol(input[i]);
        if (val > INT_MAX || val < 0)
            throw "Error";
        raw.push_back(static_cast<int>(val));
    }
    return raw;
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
        std::vector<int> raw = parse_input(ac, av);

        std::vector<int> v_input(raw.begin(), raw.end());
        std::deque<int> d_input(raw.begin(), raw.end());

        PmergeMe<std::vector<int> > v_sorter;
        v_sorter.sort(v_input);

        PmergeMe<std::deque<int> > d_sorter;
        d_sorter.sort(d_input);

        printContainer("Before: ", raw);
        printContainer("After: ", v_sorter.getContainer());

        std::cout << "Time to process a range of " << raw.size() 
                  << " elements with std::vector : " << v_sorter.getTime() << " us" << std::endl;
        std::cout << "Time to process a range of " << raw.size() 
                  << " elements with std::deque  : " << d_sorter.getTime() << " us" << std::endl;

        return 0;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}