#include "PresidentialPardonForm.hpp"
#include "Bureucrat.hpp"

const int &PresidentialPardonForm::getSignGrade() const
{
    return (requiredSignGrade);
}

const int &PresidentialPardonForm::getExecuteGrade() const
{
    return (requiredExecutionGrade);
}
const char* PresidentialPardonForm::SigningExceptionHighGrade::what() const throw()
{
    return ("PresidentialPardonForm Failed : Your Grade is Too High To Sign The PresidentialPardonForm\n");
}

const char* PresidentialPardonForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("PresidentialPardonForm Failed : Your Grade is Too High To Execute The PresidentialPardonForm\n");
}

PresidentialPardonForm::PresidentialPardonForm():requiredSignGrade(25), requiredExecutionGrade(5)
{
    std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &N):AForm(N, 25, 5), requiredSignGrade(25), requiredExecutionGrade(5)
{
    std::cout << "PresidentialPardonForm Parametrized Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called\n";
}

void PresidentialPardonForm::DoExecution(Bureucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > requiredSignGrade)
        throw (SigningExceptionHighGrade());
    if (Grade > requiredExecutionGrade)
        throw (ExecutingExceptionHighGrade());
    std::cout << "Target : " << executor.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}