#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &other, const Bureaucrat &Bureaucrat)
{
    other << Bureaucrat.getName() << ", Bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return other;
}

const std::string &Bureaucrat::getName() const
{
    return (name);
}

const int &Bureaucrat::getGrade()const
{
    return (grade);
}


void Bureaucrat::inc()
{
    grade--;
    if (grade < 1)
    {
        throw(GradeTooHighException());
    }
}

void Bureaucrat::dec()
{
    grade++;
    if (grade > 150)
    {
        throw(GradeTooLowException());
    }
}

void Bureaucrat::NoGrade()
{
    throw(std::invalid_argument("No Grade were provided for the Bureaucrat"));
}

Bureaucrat::Bureaucrat(const std::string &n, int g):name(n),grade(g)
{
    std::cout << "Bureaucrat Parametrized Constructor called\n";
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat():name(""),grade(0)
{
    std::cout << "Bureaucrat Constructor called\n";
    throw(std::invalid_argument("No Grade were provided for the Bureaucrat"));
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
    std::cout << "Copy Constructor called\n";
    grade = other.getGrade();
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat : Your Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat : Your grade is too low\n";
}

void Bureaucrat::executeForm(AForm const & form) const
{
    form.DoExecution(*this);
    const int &signG = form.getSignGrade();
    if (signG == 145)
        std::cout << getName() << " executed ShruberryCreationForm\n";
    if (signG == 72)
        std::cout << getName() << " executed RobotomyRequestForm\n";
    if (signG == 25)
        std::cout << getName() << " executed PresidentialPardonForm\n";
}
