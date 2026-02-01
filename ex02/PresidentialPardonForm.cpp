#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

const char* PresidentialPardonForm::SigningExceptionHighGrade::what() const throw()
{
    return ("PresidentialPardonForm Failed : Your Grade is Too High To Sign The PresidentialPardonForm\n");
}

const char* PresidentialPardonForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("PresidentialPardonForm Failed : Your Grade is Too High To Execute The PresidentialPardonForm\n");
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm Constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called\n";
}

void PresidentialPardonForm::DoExecution(Bureaucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > getSignGrade())
        throw (SigningExceptionHighGrade());
    if (Grade > getExecuteGrade())
        throw (ExecutingExceptionHighGrade());
    std::cout << "Target : " << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "PresidentialPardonForm Copy Constructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm Copy Assignement called\n";
    (void)other;
    return (*this);
}