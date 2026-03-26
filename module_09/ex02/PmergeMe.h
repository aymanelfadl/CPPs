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
    double time;

    T generateJacobsSeq(int size);
    T getInsertionIndices(int pendSize);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort(T &input);

    double getTime() const;
    const T &getContainer() const;
};
