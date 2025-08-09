#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>


std::string formatField(const std::string& str);

class PhoneBook
{
private:
    Contact accs[8];
    int size;
    int nextIndex;

public:
    PhoneBook();

    int getSize(void);
    Contact& getContact(int index);
    void addContact(Contact c);
    void displayContacts();
};
