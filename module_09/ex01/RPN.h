#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
    static std::stack<int> stack;

    RPN();                           
    RPN(const RPN& other);           
    RPN& operator=(const RPN& other);
    ~RPN();
    
    static void evaluateToken(const std::string &token);
    static void applyOperation(const std::string &op);

public:
    static void ReversePolishNotation(const char *inputFile);
};