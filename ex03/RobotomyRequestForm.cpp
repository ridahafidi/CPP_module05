#include "RobotomyRequestForm.hpp"
#include "Bureucrat.hpp"

const int &RobotomyRequestForm::getSignGrade() const
{
    return (requiredSignGrade);
}

const int &RobotomyRequestForm::getExecuteGrade() const
{
    return (requiredExecutionGrade);
}
const char* RobotomyRequestForm::SigningExceptionHighGrade::what() const throw()
{
    return ("Robotomy Failed : Your Grade is Too High To Sign The RobotomyRequestForm\n");
}

const char* RobotomyRequestForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("Robotomy Failed : Your Grade is Too High To Execute The RobotomyRequestForm\n");
}

RobotomyRequestForm::RobotomyRequestForm():requiredSignGrade(72), requiredExecutionGrade(45)
{
    std::cout << "RobotomyRequestForm Constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &N):AForm(N, 72, 45), requiredSignGrade(72), requiredExecutionGrade(45)
{
    std::cout << "RobotomyRequestForm Parametrized Constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called\n";
}

void RobotomyRequestForm::DoExecution(Bureucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > requiredSignGrade)
        throw (SigningExceptionHighGrade());
    if (Grade > requiredExecutionGrade)
        throw (ExecutingExceptionHighGrade());
    std::cout << "*Noise* : BEEEP BOOOP BEEP BEEP BOOP\n";
    std::cout << "Target : " << executor.getName() << " has been robotomized successfully 50% of the time\n";
}