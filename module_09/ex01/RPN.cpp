#include "RPN.h"

std::stack<int> RPN::stack;

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}
RPN &RPN::operator=(const RPN &other)
{
    (void)other;
    return *this;
}

RPN::~RPN() {}


static bool isNumber(const std::string &token)
{
    if (token.empty())
        return false;

    for (size_t i = 0; i < token.size(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

static bool isOperator(const std::string &token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::applyOperation(const std::string &op)
{
    if (stack.size() < 2)
        throw std::runtime_error("Error: not enough operands for operator " + op);

    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();

    int result = 0;

    if (op == "+")
        result = a + b;
    else if (op == "-")
        result = a - b;
    else if (op == "*")
        result = a * b;
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        result = a / b;
    }

    stack.push(result);
}

void RPN::evaluateToken(const std::string &token)
{
    if (isNumber(token))
    {
        stack.push(std::atoi(token.c_str()));
    }
    else if (isOperator(token))
    {
        applyOperation(token);
    }
    else
    {
        throw std::runtime_error("Error: invalid token '" + token + "'");
    }
}


void RPN::ReversePolishNotation(const char *input)
{
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        try
        {
            evaluateToken(token);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression, stack size != 1");

    int result = stack.top();
    std::cout << result << std::endl;
}