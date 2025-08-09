#pragma once

#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneName;
        std::string darkestSecret;

    public:
        // Constructors
        Contact() {}

        Contact(const std::string& first,
                const std::string& last,
                const std::string& nick,
                const std::string& phone,
                const std::string& secret)
        {
            firstName = first;
            lastName = last;
            nickname = nick;
            phoneName = phone;
            darkestSecret = secret;
        }

        // Setters
        void setFirstName(std::string& first) {
            firstName = first;
        }

        void setLastName(std::string& last) {
            lastName = last;
        }

        void setNickname(std::string& nick) {
            nickname = nick;
        }

        void setPhoneName(std::string& phone) {
            phoneName = phone;
        }

        void setDarkestSecret(std::string& secret) {
            darkestSecret = secret;
        }

        // Getters
        std::string getFirstName(){
            return firstName;
        }

        std::string getLastName(){
            return lastName;
        }

        std::string getNickname(){
            return nickname;
        }

        std::string getPhoneName(){
            return phoneName;
        }

        std::string getDarkestSecret(){
            return darkestSecret;
        }
};
