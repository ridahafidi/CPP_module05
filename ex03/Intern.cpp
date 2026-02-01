#include "Intern.hpp"

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &FormName, const std::string &TargetName)
{
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(*formCreators[])(const std::string &) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    int i = 0;
    while (i < 3)
    {
        if (FormName == formNames[i])
        {
            std::cout << "Intern creates " << FormName << std::endl;
            return formCreators[i](TargetName);
        }
        i++;
    }
    std::cerr << "There is no Form with this name: " << FormName << std::endl;
    return NULL;
}


Intern::Intern()
{
    std::cout << "Intern Constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called\n";
}