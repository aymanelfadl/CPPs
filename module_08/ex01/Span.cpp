#include "Span.h"

Span::Span() : N(0), numbers() {}

Span::Span(const unsigned int N) : N(N), numbers() {}

Span::~Span() {}

Span::Span(const Span &obj) {

    this->N = obj.N;
    this->numbers = obj.numbers;
}

Span &Span::operator=(const Span &obj) {

    if (this == &obj)
        return *this;
    
    this->N = obj.N;
    this->numbers = obj.numbers;
    
    return *this;
}

void Span::addNumber(const int number) {

    if (this->numbers.size() == this->N)
        throw std::runtime_error("Span is full.");
    
    this->numbers.push_back(number);
    std::sort(this->numbers.begin(), this->numbers.end());
}

int Span::shortestSpan() {

    if (this->numbers.size() < 2)
        throw std::runtime_error("Span size is less than 2.");
    
    int shortest = this->numbers.back() - this->numbers.front();
    for (size_t i = 1; i < this->numbers.size(); i++)
    {
        int diff = this->numbers[i] - this->numbers[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() {
    if (this->numbers.size() < 2)
        throw std::runtime_error("Span size is less than 2.");
    
    return this->numbers.back() - this->numbers.front();
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    
    if (std::distance(begin, end) + this->numbers.size() > this->N)
        throw std::runtime_error("Span is full.");
    
    while (begin != end) {
        this->numbers.push_back(*begin);
        begin++;
    }
    std::sort(this->numbers.begin(), this->numbers.end());
}