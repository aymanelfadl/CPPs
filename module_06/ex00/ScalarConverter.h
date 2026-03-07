#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits.h>
#include <cctype>  // Added: explicit include for std::isdigit, std::isprint

// Fixed: typo in class name - ScalarConverte -> ScalarConverter
class ScalarConverter {

    public:

        static void convert(const char* str);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ScalarConverter& operator=(const ScalarConverter &obj);
        ~ScalarConverter();
        
};