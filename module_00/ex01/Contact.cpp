#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string& first,
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

void Contact::setFirstName(const std::string& first) {
    firstName = first;
}

void Contact::setLastName(const std::string& last) {
    lastName = last;
}

void Contact::setNickname(const std::string& nick) {
    nickname = nick;
}

void Contact::setPhoneName(const std::string& phone) {
    phoneName = phone;
}

void Contact::setDarkestSecret(const std::string& secret) {
    darkestSecret = secret;
}

// Getters

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneName() const {
    return phoneName;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
