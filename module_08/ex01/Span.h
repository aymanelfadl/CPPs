#pragma once

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span();
    Span(const unsigned int N);
    Span(const Span &obj);
    Span &operator=(const Span &obj);

    ~Span();

    void addNumber(const int number);
    int shortestSpan();
    int longestSpan();

    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
