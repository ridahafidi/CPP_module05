#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
   
    try
   {
    ShrubberyCreationForm P;
    Bureaucrat l("ss1", 136);
    Bureaucrat l2("ss2", 5);
    Bureaucrat lwld("ss3", 140);
    std::cout << P.getExecuteGrade() << "  " << P.getSignGrade() << std::endl;
    std::cout << l.getGrade() << std::endl;
    P.DoExecution(l);
    P.execute(l);
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