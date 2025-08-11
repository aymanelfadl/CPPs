#include "PhoneBook.hpp"

std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";

    int padding = 10 - (int)str.length();
    std::string result(padding, ' ');
    result += str;

    return result;
}

PhoneBook::PhoneBook() : size(0), index(0)
{
}

int PhoneBook::getSize(void) const
{
    return size;
}

Contact &PhoneBook::getContact(int index)
{
    return accs[index];
}

void PhoneBook::addContact(Contact c)
{
    accs[index] = c;
    index = (index + 1) % 8;
    if (size < MAX_SIZE)
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