# CPPs - C++ Learning Journey 🚀

Welcome to my C++ learning repository! This project contains a comprehensive collection of C++ exercises organized into modules that progressively teach fundamental to advanced C++ concepts.

## 📖 About This Repository

This repository is structured as a learning path through C++ programming, covering essential concepts from basic syntax to advanced object-oriented programming principles. Each module focuses on specific aspects of C++ and builds upon previous knowledge.

## 🎯 Learning Objectives

By working through these modules, you'll master:

- **Basic C++ Syntax**: Variables, functions, I/O operations
- **Object-Oriented Programming**: Classes, objects, encapsulation
- **Memory Management**: Stack vs heap, dynamic allocation
- **Advanced OOP**: Inheritance, polymorphism, virtual functions
- **Operator Overloading**: Custom operators for user-defined types
- **C++ Best Practices**: Orthodox Canonical Form, RAII principles

## 📚 Module Overview

### Module 00: C++ Fundamentals
**Focus**: Basic C++ syntax, namespaces, classes, and member functions

- **ex00 - Megaphone**: String manipulation and command-line arguments
- **ex01 - My Awesome PhoneBook**: Introduction to classes and basic OOP
- **ex02 - The Job Of Your Dreams**: Advanced class design with static members

**Key Concepts**: 
- C++ I/O streams (`std::cout`, `std::cin`)
- String manipulation with `std::string`
- Basic class design and member functions
- Static class members and methods

### Module 01: Memory Management & References
**Focus**: Memory allocation, references vs pointers, and resource management

- **ex00 - BraiiiiiiinnnzzzZ**: Constructor/destructor lifecycle
- **ex01 - Moar Brainz!**: Dynamic memory allocation with arrays
- **ex02 - HI THIS IS BRAIN**: References vs pointers demonstration
- **ex03 - Unnecessary Violence**: References in practice
- **ex04 - Sed is for Losers**: File manipulation and string replacement
- **ex05 - Harl 2.0**: Function pointers and member function pointers
- **ex06 - Harl Filter**: Switch statements and program flow control

**Key Concepts**:
- Dynamic memory allocation (`new`/`delete`)
- References vs pointers
- Object lifecycle (RAII - Resource Acquisition Is Initialization)
- Function pointers and callbacks

### Module 02: Orthodox Canonical Form & Operator Overloading
**Focus**: Copy semantics, assignment operators, and operator overloading

- **ex00 - My First Class in Orthodox Canonical Form**: Rule of Three implementation
- **ex01 - Towards a More Useful Fixed-Point Number Class**: Constructor overloading
- **ex02 - Now We're Talking**: Comprehensive operator overloading
- **ex03 - BSP**: Practical application with geometric calculations

**Key Concepts**:
- Orthodox Canonical Form (Rule of Three)
- Copy constructor and assignment operator
- Operator overloading (arithmetic, comparison, increment/decrement)
- Fixed-point arithmetic implementation

### Module 03: Inheritance & Polymorphism
**Focus**: Class inheritance, virtual functions, and polymorphic behavior

- **ex00 - Aaaaand... OPEN!**: Base class design (ClapTrap)
- **ex01 - Serena, my Love!**: Single inheritance (ScavTrap)
- **ex02 - Repetitive Work**: Multiple inheritance concepts

**Key Concepts**:
- Class inheritance and derived classes
- Virtual functions and polymorphism
- Access specifiers (`public`, `protected`, `private`)
- Constructor/destructor chaining in inheritance

## 🛠️ Getting Started

### Prerequisites

- C++ compiler supporting C++98 standard (g++, clang++)
- Make utility
- Basic understanding of programming concepts

### Compilation Instructions

Each exercise contains its own Makefile. To compile any exercise:

```bash
# Navigate to specific exercise directory
cd module_XX/exXX

# Compile using Make
make

# Run the executable (name varies by exercise)
./executable_name
```

### General Compilation Flags

All exercises use these compiler flags for strict C++98 compliance:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## 🏗️ Project Structure

```
CPPs/
├── module_00/           # C++ Fundamentals
│   ├── ex00/           # Megaphone
│   ├── ex01/           # PhoneBook
│   └── ex02/           # Account Class
├── module_01/           # Memory & References
│   ├── ex00-ex06/      # Various exercises
├── module_02/           # Orthodox Form & Operators
│   ├── ex00-ex03/      # Fixed-point arithmetic
└── module_03/           # Inheritance
    ├── ex00-ex02/      # ClapTrap family
```

## 📝 Key C++ Concepts Demonstrated

### 1. **RAII (Resource Acquisition Is Initialization)**
Automatic resource management through constructors and destructors.

### 2. **Orthodox Canonical Form**
Essential components every C++ class should have:
- Default constructor
- Copy constructor  
- Assignment operator
- Destructor

### 3. **Memory Management**
- Stack vs heap allocation
- Smart resource handling
- Avoiding memory leaks

### 4. **Object-Oriented Design**
- Encapsulation and data hiding
- Inheritance hierarchies
- Polymorphic behavior

## 🎓 Learning Tips

1. **Start with Module 00**: Build a solid foundation before advancing
2. **Read the Code**: Study existing implementations to understand patterns
3. **Experiment**: Modify exercises to test your understanding
4. **Debug Actively**: Use debugging tools to understand program flow
5. **Practice Regularly**: Consistent practice builds muscle memory

## 📋 Coding Standards

This project follows strict C++98 standards:
- No STL containers beyond basic ones
- No external libraries
- Emphasis on manual memory management
- Orthodox Canonical Form for all classes

## 🤝 Contributing

This is a personal learning repository, but feedback and suggestions are welcome! Feel free to open issues for:
- Code improvements
- Documentation enhancements
- Additional learning resources

## 📄 License

This project is for educational purposes. Feel free to use it as a reference for your own C++ learning journey.

---

**Happy Coding!** 🎉

*Remember: The best way to learn C++ is by writing code. Start with the basics and gradually work your way through each module.*