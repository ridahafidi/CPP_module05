#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
   
    try
   {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf->DoExecution(Bureucrat("lida", 10));
   }
   catch(const std::exception& e)
   {
    std::cerr << "Catched : " << e.what() << '\n';
   }
}