#pragma once

#include <iostream>

// template<typename T>
// void iter(T *arr, const size_t len, void (*f)(T))
// {
//     for (size_t i = 0; i < len; i++)
//         f(arr[i]);
// }

template<typename T, typename F>
void iter(T* arr, size_t len, F f)
{
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}