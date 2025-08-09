#include "PhoneBook.hpp"
#include <sstream>

std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";

    std::ostringstream oss;
    oss << std::setw(10) << std::right << str;
    return oss.str();
}

PhoneBook::PhoneBook()
    : size(0), nextIndex(0)
{}

int PhoneBook::getSize(void)
{
    return size;
}

Contact& PhoneBook::getContact(int index)
{
    return accs[index];
}

void PhoneBook::addContact(Contact c)
{
    accs[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (size < 8)
        size++;
}

void PhoneBook::displayContacts()
{
    std::cout << "|" << formatField("Index")
              << "|" << formatField("First Name")
              << "|" << formatField("Last Name")
              << "|" << formatField("Nickname")
              << "|" << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::ostringstream indexStr;
        indexStr << i;
        std::cout << "|" << formatField(indexStr.str())
                  << "|" << formatField(accs[i].getFirstName())
                  << "|" << formatField(accs[i].getLastName())
                  << "|" << formatField(accs[i].getNickname())
                  << "|" << std::endl;
    }
}