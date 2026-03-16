#pragma once


#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <algorithm>


class BitcoinExchange
{
private:
    static std::map<std::string, double> dataSet;
   
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

public:
    static bool loadDataSet();
    static bool processInput(const char *inputFile);
    static void bitcoinValue(const std::vector<std::string> &parts);
};