#pragma once

#include <string>
#include <iostream>

class Animal {
public:
  Animal();
  Animal(const Animal &obj);
  Animal &operator=(const Animal &obj);
  virtual ~Animal();

  std::string getType() const;
  
  virtual void makeSound() const = 0;

protected:
  std::string type;
};
