#include "ScalarConverte.h"

ScalarConverte::ScalarConverte() {};

ScalarConverte::ScalarConverte(const ScalarConverte &obj)
{
    (void)obj;
};

ScalarConverte& ScalarConverte::operator=(const ScalarConverte &obj)
{
    (void)obj;
    return *this;
}

ScalarConverte::~ScalarConverte() {};

static bool isChar(const std::string& s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isInt(const std::string &s)
{
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.size())
        return false;

    while (i < s.size())
    {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string &s)
{
    if (s.size() < 3 || s[s.size() - 1] != 'f')
        return false;

    int dot = 0;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    while (i < s.size() - 1)
    {
        if (s[i] == '.')
            dot++;
        else if (!std::isdigit(s[i]))
            return false;
        i++;
    }

    return dot == 1;
}

static bool isDouble(const std::string &s)
{
    int dot = 0;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < s.size(); i++)
    {
        if (s[i] == '.')
            dot++;
        else if (!std::isdigit(s[i]))
            return false;
    }

    return dot == 1;
}

static bool isPseudoLiteral(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

static bool isValide(const std::string &s)
{
    return isPseudoLiteral(s) || isInt(s) || isFloat(s) || isDouble(s);
}

void ScalarConverte::convert(const char *str)
{
    std::string input(str);
    double value;

    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isValide(input))
        value = std::strtod(input.c_str(), NULL);
    else
    {
        std::cout << "Error: invalid input\n";
        return;
    }

    std::cout << "char: ";
    if (value < 0 || value > 127 || value != value)
        std::cout << "impossible\n";
    else 
    {
        const char c = static_cast<char>(value);
        if (!std::isprint(c))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << c << "'\n";
    }

    std::cout << "int: ";
    if (value < INT_MIN || value > INT_MAX || value != value)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";

    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
}