#pragma once

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template<typename T>
typename T::iterator easyfind(T& c, const int target) {
    
    typename T::iterator it = std::find(c.begin(), c.end(), target);
    
    if (it == c.end())
        throw std::runtime_error("not found"); 
    
    return it;
}
