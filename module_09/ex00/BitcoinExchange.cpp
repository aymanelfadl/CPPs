#include "BitcoinExchange.h"

std::map<std::string, double> BitcoinExchange::dataSet;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    (void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

static std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delimiter))
        tokens.push_back(trim(item));

    return tokens;
}

bool BitcoinExchange::loadDataSet()
{
    std::ifstream file("DB/data.csv");
    if (!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::vector<std::string> parts = split(line, ',');

        std::string date = parts[0];
        double rate = std::atof(parts[1].c_str());

        dataSet[date] = rate;
    }

    file.close();
    return true;
}

static bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static void valideDate(const std::string &date)
{
    if (date.size() != 10)
        throw std::runtime_error("bad input => " + date);

    if (date[4] != '-' || date[7] != '-')
        throw std::runtime_error("bad input => " + date);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        throw std::runtime_error("bad input => " + date);

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        throw std::runtime_error("bad input => " + date);
}

static void valideValue(const std::string &value)
{
    if (value.empty())
        throw std::runtime_error("not a positive number.");

    int dotCount = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        char c = value[i];
        if (c == '.')
        {
            dotCount++;
            if (dotCount > 1)
                throw std::runtime_error("not a positive number: " + value);
        }
        else if (!std::isdigit(c))
        {
            throw std::runtime_error("not a positive number: " + value);
        }
    }

    double val = std::atof(value.c_str());
    if (val < 0.0)
        throw std::runtime_error("negative number: " + value);
    if (val > 1000.0)
        throw std::runtime_error("too large number: " + value);
}

void BitcoinExchange::bitcoinValue(const std::vector<std::string> &parts)
{
    if (parts.size() != 2)
        throw std::runtime_error("Bad input format.");

    const std::string &dateStr  = parts[0];
    const std::string &valueStr = parts[1];

    valideDate(dateStr);
    valideValue(valueStr);

    double amount = std::atof(valueStr.c_str());

    std::map<std::string,double>::iterator it = dataSet.upper_bound(dateStr);

    if (it == dataSet.begin())
        throw std::runtime_error("date earlier than database.");
    
    it--;
    double rate = it->second;

    std::cout << dateStr
              << " => "
              << amount
              << " = "
              << amount * rate
              << std::endl;
}

bool BitcoinExchange::processInput(const char *inputFile)
{
    if (dataSet.empty() && !loadDataSet())
    {
        std::cout << "Failed to load dataset" << std::endl;
        return false;
    }

    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Cannot open input file" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::vector<std::string> parts = split(line, '|');
        try
        {
            bitcoinValue(parts);
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    file.close();
    return true;
}