#pragma once

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    Contact(const std::string& first,
            const std::string& last,
            const std::string& nick,
            const std::string& phone,
            const std::string& secret);

    // Setters
    void setFirstName(const std::string& first);
    void setLastName(const std::string& last);
    void setNickname(const std::string& nick);
    void setphoneNumber(const std::string& phone);
    void setDarkestSecret(const std::string& secret);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getphoneNumber() const;
    std::string getDarkestSecret() const;
};
