#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typename std::deque<T>::iterator begin();
        typename std::deque<T>::iterator end();
        typename std::deque<T>::const_iterator begin() const;
        typename std::deque<T>::const_iterator end() const;
};

#include "MutantStack.tpp"