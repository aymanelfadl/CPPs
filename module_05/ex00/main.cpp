#include "Bureaucrat.h"

int main()
{
    std::cout << "=== Bureaucrat ===" << std::endl;

    {
        std::cout << "\n--- Test 1: Valid Creation ---" << std::endl;
        try
        {
            Bureaucrat valid1("Alice", 1);    
            Bureaucrat valid2("Bob", 75);     
            Bureaucrat valid3("Charlie", 150);

            std::cout << valid1 << std::endl;
            std::cout << valid2 << std::endl;
            std::cout << valid3 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 2: Grade Too High Exception ---" << std::endl;
        try
        {
            Bureaucrat notValid("Alice", 0); 
            std::cout << notValid << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 3: Grade Too Low Exception ---" << std::endl;
        try
        {
            Bureaucrat notValid("Alice", 160); 
            std::cout << notValid << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 4: Grade Increment ---" << std::endl;
        try
        {
            Bureaucrat valid("Alice", 2);
            std::cout << valid << std::endl;
            valid.increment();
            std::cout << valid << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 5: Grade Decrement ---" << std::endl;
        try
        {
            Bureaucrat valid("Alice", 3);
            std::cout << valid << std::endl;
            valid.decrement();
            std::cout << valid << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n--- Test 6: Grade Increment Error ---" << std::endl;
        try
        {
            Bureaucrat original("Original", 1);
            
            std::cout << original << std::endl;
            original.increment();

            std::cout << original << std::endl;
            
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 7: Grade Decrement Error ---" << std::endl;
        try
        {
            Bureaucrat original("Original", 150);
            
            std::cout << original << std::endl;
            original.decrement();

            std::cout << original << std::endl;
            
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n--- Test 8: Copy Constructor ---" << std::endl;
        try
        {
            Bureaucrat original("Original", 6);
            Bureaucrat copy(original);

            std::cout << original << std::endl;
            std::cout << copy << std::endl;

            original.increment();
            copy.decrement();

            std::cout << original << std::endl;
            std::cout << copy << std::endl;
            
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Test 9: Assignment Operator ---" << std::endl;
        try
        {
            Bureaucrat original("Original", 6);
            Bureaucrat copy;

            copy = original;

            std::cout << original << std::endl;
            std::cout << copy << std::endl;


            original.increment();
            copy.decrement();

            std::cout << original << std::endl;
            std::cout << copy << std::endl;
            
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }


    return 0;
}