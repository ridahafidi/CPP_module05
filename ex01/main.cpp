#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form F("name", 10, 12);
        try
        {
            Bureaucrat Bureaucrat;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        Bureaucrat Bure("named", 9);
        Bure.signForm(F);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}