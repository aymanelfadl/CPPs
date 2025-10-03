#pragma once

#include <string>
#include <iostream>

class Animal {
public:
  Animal();
  Animal(const Animal &obj);
  Animal &operator=(const Animal &obj);
  ~Animal();

  std::string getType() const;
  
  void makeSound() const;

protected:
  std::string type;
};
