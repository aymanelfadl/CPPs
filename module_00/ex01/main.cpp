#include "PhoneBook.hpp"

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
        return Contact();
    
    Contact c(first, last, nick, phone, secret);
    return c;
}

std::string getChoice()
{
    std::string choice;
    std::cout << "\n* Welcome To Your Awesome PhoneBook *" << std::endl;
    std::cout << "  ** What Do YOU need: **\n   -> ADD\n   -> SEARCH\n   -> EXIT" << std::endl;
    std::getline(std::cin, choice);
    return choice;
}

void displayContactDetails(PhoneBook& phoneBook)
{
    if (phoneBook.getSize() == 0)
    {
        std::cout << "No contacts available.\n";
        return;
    }

    std::cout << "Enter index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    int index = std::atoi(input.c_str());

    if (input.empty() || index < 0 || index >= phoneBook.getSize())
    {
        std::cout << "Invalid index.\n";
        return;
    }

    Contact& c = phoneBook.getContact(index);
    std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickname() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneName() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
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
            std::cout << "Error: All fields must be filled. Contact creation failed.\n";
        return 1;
    }
    else if (userChoice == "SEARCH")
    {
        std::cout << "\033[2J\033[1;1H";
        myPhoneBook.displayContacts();
        displayContactDetails(myPhoneBook);
        return 1;
    }
    else if (userChoice == "EXIT")
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "THANKS FOR YOUR VISIT <3" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Invalid choice. Please try again.\n";
        return 1;
    }
}

int main(void)
{
    PhoneBook myPhoneBook;

    std::string userChoice = getChoice();
    while (validateChoice(userChoice, myPhoneBook) != 0)
        userChoice = getChoice();
    return 0;
}
