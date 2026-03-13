#include "Span.h"

Span::Span() : N(0), numbers() {}

Span::Span(const unsigned int N) : N(N), numbers() {}

Span::~Span() {}

Span::Span(const Span &obj)
{
    this->N = obj.N;
    this->numbers = obj.numbers;
}

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
        return *this;
    this->N = obj.N;
    this->numbers = obj.numbers;
    return *this;
}

void Span::addNumber(const int number)
{
    if (this->numbers.size() == this->N)
        throw std::runtime_error("Span is full.");
    this->numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (this->numbers.size() < 2)
        throw std::runtime_error("Span size is less than 2.");

    std::vector<int> sorted(this->numbers);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

    return *std::min_element(diffs.begin() + 1, diffs.end());
}

int Span::longestSpan()
{
    if (this->numbers.size() < 2)
        throw std::runtime_error("Span size is less than 2.");

    return *std::max_element(this->numbers.begin(), this->numbers.end()) - *std::min_element(this->numbers.begin(), this->numbers.end());
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + this->numbers.size() > this->N)
        throw std::runtime_error("Span is full.");
    this->numbers.insert(this->numbers.end(), begin, end);
}