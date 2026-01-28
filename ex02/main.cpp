#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
   
    try
   {
    ShrubberyCreationForm P;
    Bureucrat lqawad("ahmadabolqhab", 136);
    std::cout << P.getExecuteGrade() << "  " << P.getSignGrade() << std::endl;
    std::cout << lqawad.getGrade() << std::endl;
    P.DoExecution(lqawad);
    P.execute(lqawad);
    
   }
   catch(const std::exception& e)
   {
    std::cerr << "Catched : " << e.what() << '\n';
   }
}