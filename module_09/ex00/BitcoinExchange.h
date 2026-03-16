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
public:
    static bool processInput(const char* inputFile);

private:
    static std::map<std::string, double> dataSet;

    static bool loadDataSet();
    static void bitcoinValue(const std::vector<std::string> &parts);

};

