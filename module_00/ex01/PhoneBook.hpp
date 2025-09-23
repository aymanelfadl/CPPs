#pragma once

#include "Contact.hpp"
#include <sstream>
#include <iostream>

#define MAX_SIZE 8

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
