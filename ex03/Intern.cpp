#include "Intern.hpp"


AForm *Intern::makeForm(const std::string &FormName, const std::string &TargetName)
{
    if (FormName == "shruberry creation")
    {
        std::cout << "Intern creates " << FormName;
        return (new ShrubberyCreationForm(TargetName));
    }
    if (FormName == "robotomy request")
    {
        std::cout << "Intern creates " << FormName;
        return (new RobotomyRequestForm(TargetName));
    }
    if (FormName == "presidential pardon")
    {
        std::cout << "Intern creates " << FormName;
        return (new PresidentialPardonForm(TargetName));
    }
    std::cerr << "There is no Form with this name : " << FormName;
    return (0);
}


Intern::Intern()
{
    std::cout << "Intern Constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called\n";
}