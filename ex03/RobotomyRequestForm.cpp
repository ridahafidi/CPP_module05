#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

const char* RobotomyRequestForm::SigningExceptionHighGrade::what() const throw()
{
    return ("Robotomy Failed : Your Grade is Too High To Sign The RobotomyRequestForm\n");
}

const char* RobotomyRequestForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("Robotomy Failed : Your Grade is Too High To Execute The RobotomyRequestForm\n");
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &N) : AForm(N, 72, 45)
{
    std::cout << "RobotomyRequestForm Parametrized Constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called\n";
}

void RobotomyRequestForm::DoExecution(Bureaucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > getSignGrade())
        throw (SigningExceptionHighGrade());
    if (Grade > getExecuteGrade())
        throw (ExecutingExceptionHighGrade());
    std::cout << "*Noise* : BEEEP BOOOP BEEP BEEP BOOP\n";
    std::srand(std::time(NULL));
    bool trigger = std::rand() % 2;
    if (trigger == true)
        std::cout << "Target : " << getTarget() << " has been robotomized successfully\n";
    else if (trigger == false)
        std::cout << "Target : " << getTarget() << " has failed being robotomized\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "RobotomyRequestForm Copy Constructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm Copy Assignement called\n";
    (void)other;
    return (*this);
}