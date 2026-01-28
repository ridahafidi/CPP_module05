#include "Bureucrat.hpp"

std::ostream &operator<<(std::ostream &other, const Bureucrat &Bureucrat)
{
    other << Bureucrat.getName() << ", bureucrat grade " << Bureucrat.getGrade() << std::endl;
    return other;
}

const std::string &Bureucrat::getName() const
{
    return (name);
}

const int &Bureucrat::getGrade()const
{
    return (grade);
}


void Bureucrat::inc()
{
    grade--;
    if (grade < 1)
    {
        throw(GradeTooHighException());
    }
}

void Bureucrat::dec()
{
    grade++;
    if (grade > 150)
    {
        throw(GradeTooLowException());
    }
}

void Bureucrat::NoGrade()
{
    throw(std::invalid_argument("No Grade were provided for the bureucrat"));
}

Bureucrat::Bureucrat(const std::string &n, int g):name(n),grade(g)
{
    std::cout << "Bureucrat Parametrized Constructor called\n";
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

Bureucrat::Bureucrat():name(""),grade(0)
{
    std::cout << "Bureucrat Constructor called\n";
    throw(std::invalid_argument("No Grade were provided for the bureucrat"));
}

Bureucrat::~Bureucrat()
{
    std::cout << "Bureucrat Destructor called\n";
}

Bureucrat::Bureucrat(Bureucrat &other)
{
    std::cout << "Copy Constructor called\n";
    grade = other.getGrade();
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
}

const char* Bureucrat::GradeTooHighException::what() const throw()
{
    return "Bureucrat : Your Grade is too high\n";
}

const char* Bureucrat::GradeTooLowException::what() const throw()
{
    return "Bureucrat : Your grade is too low\n";
}

void Bureucrat::executeForm(AForm const & form) const
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
