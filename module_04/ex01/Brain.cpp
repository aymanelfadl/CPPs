
#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain has been created" << std::endl; }

Brain::Brain(const Brain& obj) {
    *this = obj;
    std::cout << "Brain has been created" << std::endl;
}

Brain& Brain::operator=(const Brain& obj) {
    if (this == &obj)
        return *this;
    this->setIdeas(obj.ideas);
    return *this;
}

Brain::~Brain() { std::cout << "Brain has been destroyed" << std::endl; }

void Brain::setIdeas(const std::string *ideas) {
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = ideas[i];
}

const std::string* Brain::getIdeas() const {
        return ideas;
}
