#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <string>

template <typename T>
class PmergeMe {
private:
    T _container;
    double _time;

    std::vector<int> generateJacobsSeq(int size);
    std::vector<int> getInsertionIndices(int pendSize);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sort(T& input);

    double getTime() const;
    const T& getContainer() const;
};

#endif