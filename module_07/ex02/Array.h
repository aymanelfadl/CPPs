#pragma once

#include <iostream>

template <typename T>
class Array
{

private:
    T *ptr;
    size_t len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& obj);
    Array& operator=(const Array& obj);
    ~Array();

    size_t size() const;

    T& operator[](const int index);
    const T& operator[](const int index) const;
};

#include "Array.tpp"