#include "Bureucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
   
    try
   {
    ShrubberyCreationForm P;
    Bureucrat l("s1", 136);
    Bureucrat l2("s2", 5);
    Bureucrat lwld("s3", 140);
    std::cout << P.getExecuteGrade() << "  " << P.getSignGrade() << std::endl;
    std::cout << l.getGrade() << std::endl;
    P.DoExecution(l);
    P.execute(l);
    std::cout << P.getExecuteGrade() << "  " << P.getSignGrade() << std::endl;
    std::cout << lwld.getGrade() << std::endl;
    RobotomyRequestForm contrada;
    contrada.DoExecution(l2);
    PresidentialPardonForm con;
    con.DoExecution(l2);
    l2.executeForm(ShrubberyCreationForm());
   }
   catch(const std::exception& e)
   {
    std::cerr << "Catched : " << e.what() << '\n';
   }
}