#include "Bureaucrat.h"
#include <iostream>

int main() {
    std::cout << "=== TEST 1: Valid construction ===" << std::endl;
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat b2("Bob", 0);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat b3("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Increment at max (1) ===" << std::endl;
    try {
        Bureaucrat b4("David", 1);
        std::cout << "Before: " << b4 << std::endl;
        b4.increment();  // Should throw
        std::cout << "After: " << b4 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Decrement at min (150) ===" << std::endl;
    try {
        Bureaucrat b5("Eve", 150);
        std::cout << "Before: " << b5 << std::endl;
        b5.decrement();  // Should throw
        std::cout << "After: " << b5 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Multiple increments ===" << std::endl;
    try {
        Bureaucrat b6("Frank", 5);
        std::cout << "Start: " << b6 << std::endl;
        for (int i = 0; i < 5; i++) {
            b6.increment();
            std::cout << "Increment " << i+1 << ": " << b6 << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Copy constructor ===" << std::endl;
    try {
        Bureaucrat b7("Grace", 42);
        Bureaucrat copy(b7);
        std::cout << "Original: " << b7 << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: Assignment operator ===" << std::endl;
    try {
        Bureaucrat b8("Henry", 100);
        Bureaucrat b9("Ivy", 50);
        std::cout << "Before: " << b8 << " | " << b9 << std::endl;
        b8 = b9;  // Only grade copies, name stays "Henry"
        std::cout << "After: " << b8 << " | " << b9 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 9: Self-assignment ===" << std::endl;
    try {
        Bureaucrat b10("Jack", 75);
        b10 = b10;  // Should handle gracefully
        std::cout << b10 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 10: Default constructor ===" << std::endl;
    try {
        Bureaucrat b11;
        std::cout << b11 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}