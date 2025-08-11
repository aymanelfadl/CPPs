#pragma once

#include "Contact.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>

#define MAX_SIZE 8

std::string formatField(const std::string &str);

class PhoneBook
{
private:
    Contact accs[8];
    int size;
    int index;

public:
    PhoneBook();

    int getSize(void) const;
    Contact &getContact(int index);
    void addContact(Contact c);
    void displayContacts();
};
