#pragma once

#include "Contact.hpp"
#include <iomanip>
#include <iostream>

class PhoneBook
{
    private:
        Contact accs[8];
        int size;
    public:
        // Constructor
        PhoneBook()
        {
            size = 0;
        }
        int getSize( void )
        {
            return size;
        }

        void addContact(Contact c)
        {
            if (size == 8)
                size = 0;
            accs[size] = c;
            size++;     
        }
        
        void displayContacts()
        {
            std::cout << std::setw(10) << "Index" 
                    << std::setw(15) << "First Name" 
                    << std::setw(15) << "Last Name" 
                    << std::setw(15) << "Nickname" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;

            for (int i = 0; i < size; ++i)
            {
                std::cout << std::setw(10) << i
                        << std::setw(15) << accs[i].getFirstName()
                        << std::setw(15) << accs[i].getLastName()
                        << std::setw(15) << accs[i].getNickname()
                        << std::endl;
            }
        }

};
