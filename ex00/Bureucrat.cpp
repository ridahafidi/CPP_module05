#include "Bureucrat.hpp"

std::ostream &operator<<(std::ostream &other, Bureucrat &Bureucrat)
{
    std::cout << Bureucrat.getName() << ", bureucrat grade " << Bureucrat.getGrade() << std::endl;
    return (other);
}

const std::string &Bureucrat::getName() const
{
    return (name);
}

const int &Bureucrat::getGrade()const
{
    return (grade);
}
const char* Bureucrat::NoGradeException::what() const throw()
{
    return ("No Grade were provided for the bureucrat");
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
    throw(NoGradeException());
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
