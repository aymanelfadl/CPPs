#pragma once

#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal &obj);
  Animal &operator=(const Animal &obj);
  ~Animal();

  void makeSound();

protected:
  std::string type;
};
