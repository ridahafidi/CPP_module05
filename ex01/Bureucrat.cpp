#include "Bureucrat.hpp"

std::ostream &operator<<(std::ostream &other, Bureucrat &Bureucrat)
{
    std::cout << Bureucrat.getName() << ", bureucrat grade " << Bureucrat.getGrade() << std::endl;
    return (other);
}

const std::string &Bureucrat::getName()
{
    return (name);
}

const int &Bureucrat::getGrade()
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