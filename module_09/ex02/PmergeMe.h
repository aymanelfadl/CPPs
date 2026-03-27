#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <climits>

template <typename T>
class PmergeMe
{
private:
    T container;

    T generateJacobsSeq(int size);
    T getInsertionIndices(int pendSize);
    
    T parser_input(int ac, char **input);

    T sort(T& input);

public:
    PmergeMe();
    PmergeMe(int ac, char **input);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    double sort();

    const T &getContainer() const;
};
