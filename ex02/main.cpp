#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
int main()
{
   
    try
   {
    ShrubberyCreationForm P;
    Bureucrat lqawad("ahmadabolqhab", 136);
    // P.execute(lqawad);
    
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
}