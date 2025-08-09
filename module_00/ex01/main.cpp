#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string getInput(const std::string& prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

Contact getNewContact()
{
    std::string first = getInput("Enter First Name: ");
    std::string last = getInput("Enter Last Name: ");
    std::string nick = getInput("Enter Nickname: ");
    std::string phone = getInput("Enter Phone Number: ");
    std::string secret = getInput("Enter Darkest Secret: ");

    if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty())
    {
        std::cout << "Error: All fields must be filled. Contact not created.\n";
        return Contact();
    }

    Contact c(first, last, nick, phone, secret);
    return c;
}

std::string getChoice()
{
    std::string choice; 

    std::cout << "* Welcome To Your Awesome PhoneBook *" << std::endl;
    std::cout << "  ** What Do YOU need: **\n   -> ADD\n   -> SEARCH\n   -> EXIT" << std::endl;
    std::getline(std::cin, choice);
    return choice;
}

int validateChoice(std::string userChoice, PhoneBook &myPhoneBook)
{
    if (userChoice == "ADD")
    {
        Contact newContact = getNewContact();
        if (!newContact.getFirstName().empty())
        {
            myPhoneBook.addContact(newContact);
            std::cout << "Contact created successfully!\n";
        }
        else
            std::cout << "Contact creation failed.\n";
    }
    else if (userChoice == "SEARCH")
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Search not implemented yet.\n";
    }
    else if (userChoice == "EXIT")
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "THANKS FOR YOUR VISIT <3" << std::endl;
        return 0;
    }
    std::cout << "\033[2J\033[1;1H";
    return 1;
}

int main(int argc, char const *argv[])
{
    PhoneBook myPhoneBook;

    std::string userChoice = getChoice();
    while (validateChoice(userChoice, myPhoneBook) != 0)
        userChoice = getChoice();
    myPhoneBook.displayContacts();
    return 0;
}
