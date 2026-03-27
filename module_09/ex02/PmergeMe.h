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

    void sort(const T &input);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    double execute(const T& input);

    const T &getContainer() const;
};
