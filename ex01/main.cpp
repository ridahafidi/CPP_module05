#include "Bureucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form F("name", 10, 12);
        try
        {
            Bureucrat Bureucrat;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    
        Bureucrat Bure("named", 9);
        Bure.signForm(F);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}