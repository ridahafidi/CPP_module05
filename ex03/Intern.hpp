#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class Intern
{
public:
    Intern();
    ~Intern();
    AForm *makeForm(const std::string &FormName, const std::string &TargetName);
};





#endif
