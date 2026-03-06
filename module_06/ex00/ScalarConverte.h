#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits.h>

class ScalarConverte {

    public:

        static void convert(const char* str);

    private:
        ScalarConverte();
        ScalarConverte(const ScalarConverte& obj);
        ScalarConverte& operator=(const ScalarConverte &obj);
        ~ScalarConverte();
        
};