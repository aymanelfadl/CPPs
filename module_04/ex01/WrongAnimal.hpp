#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &obj);
  WrongAnimal &operator=(const WrongAnimal &obj);
  ~WrongAnimal();

  std::string getType() const;
  
  void makeSound() const;

protected:
  std::string type;
};
