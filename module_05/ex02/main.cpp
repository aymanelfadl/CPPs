#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main() {
    std::cout << "=== TEST 1: Valid Form creation ===" << std::endl;
    try {
        Form f1("TaxForm", 50, 25);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Form grade too high (0) ===" << std::endl;
    try {
        Form f2("Invalid", 0, 50);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Form grade too low (151) ===" << std::endl;
    try {
        Form f3("Invalid", 50, 151);
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Successful sign ===" << std::endl;
    try {
        Bureaucrat b("Alice", 10);
        Form f("Contract", 50, 25);
        std::cout << "Before: " << f << std::endl;
        b.signForm(f);
        std::cout << "After: " << f << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Failed sign (grade too low) ===" << std::endl;
    try {
        Bureaucrat b("Bob", 51);
        Form f("Secret", 50, 25);
        b.signForm(f);
    } catch (const std::exception& e) {
        std::cout << "Should not catch here - handled in signForm" << std::endl;
    }

    std::cout << "\n=== TEST 6: beSigned directly ===" << std::endl;
    try {
        Bureaucrat b("Charlie", 1);
        Form f("TopSecret", 5, 1);
        f.beSigned(b);
        std::cout << "Signed: " << f << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Already signed form ===" << std::endl;
    try {
        Bureaucrat b1("David", 10);
        Bureaucrat b2("Eve", 20);
        Form f("Paper", 50, 25);
        b1.signForm(f);
        b2.signForm(f);  // Try sign again
    } catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: Copy Form ===" << std::endl;
    try {
        Bureaucrat b("Frank", 10);
        Form f1("Original", 50, 25);
        b.signForm(f1);
        Form f2(f1);
        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Copy: " << f2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}