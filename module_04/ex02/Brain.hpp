#pragma once

#include <iostream>
#include <string>

class Brain
{

public:
    Brain();
    Brain(const Brain& obj);
    Brain& operator=(const Brain& obj);
    ~Brain();
    
    void setIdeas(const std::string *ideas);
    const std::string *getIdeas(void) const;

private:
    std::string ideas[100];

};
