#include "Form.h"

int main()
{
    std::cout << "\n=== FORM TESTS ===" << std::endl;

    {
        std::cout << "\n--- Form Test 1: Valid Form Creation ---" << std::endl;
        try
        {
            Form form1("Tax Form", 50, 25);
            Form form2("Application", MAXGRADE, MINGRADE);
            Form form3; 

            std::cout << form1 << std::endl;
            std::cout << form2 << std::endl;
            std::cout << form3 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 2: Form Grade Too High Exception ---" << std::endl;
        try
        {
            Form invalidForm("Invalid", 0, 50); 
            std::cout << invalidForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 3: Form Grade Too Low Exception ---" << std::endl;
        try
        {
            Form invalidForm("Invalid", 50, 200); 
            std::cout << invalidForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 4: Successful Form Signing ---" << std::endl;
        try
        {
            Bureaucrat alice("Alice", 1);
            Form taxForm("Tax Declaration", 50, 25);

            std::cout << "Before signing:" << std::endl;
            std::cout << alice << std::endl;
            std::cout << taxForm << std::endl;

            alice.signForm(taxForm);

            std::cout << "After signing:" << std::endl;
            std::cout << taxForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 5: Form Signing Failure (Grade Too Low) ---" << std::endl;
        try
        {
            Bureaucrat bob("Bob", 100);
            Form importantForm("VIP Form", 50, 25);

            std::cout << "Before signing attempt:" << std::endl;
            std::cout << bob << std::endl;
            std::cout << importantForm << std::endl;

            bob.signForm(importantForm);

            std::cout << "After signing attempt:" << std::endl;
            std::cout << importantForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 6: Already Signed Form ---" << std::endl;
        try
        {
            Bureaucrat charlie("Charlie", 10);
            Bureaucrat dave("Dave", 5);
            Form contract("Contract", 20, 15);

            std::cout << "Initial state:" << std::endl;
            std::cout << contract << std::endl;

         
            charlie.signForm(contract);
            std::cout << "After first signing:" << std::endl;
            std::cout << contract << std::endl;

           
            dave.signForm(contract);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 7: Form Copy Constructor ---" << std::endl;
        try
        {
            Form original("Original Form", 75, 50);
            Bureaucrat signer("Signer", 50);
            
            signer.signForm(original);
            
            Form copy(original);
            
            std::cout << "Original: " << original << std::endl;
            std::cout << "Copy: " << copy << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n--- Form Test 8: Form Assignment Operator ---" << std::endl;
        try
        {
            Form form1("Form1", 80, 60);
            Form form2("Form2", 120, 100);
            Bureaucrat signer("Signer", 70);
            
            std::cout << "Before assignment:" << std::endl;
            std::cout << "Form1: " << form1 << std::endl;
            std::cout << "Form2: " << form2 << std::endl;
            

            signer.signForm(form1);
            
            form2 = form1;
            
            std::cout << "After assignment:" << std::endl;
            std::cout << "Form1: " << form1 << std::endl;
            std::cout << "Form2: " << form2 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
    
    return 0;
}