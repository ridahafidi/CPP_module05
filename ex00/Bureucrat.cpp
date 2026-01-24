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
        try
        {
            GradeTooHigh();
        }
        catch(const std::exception& e)
        {
            std::cerr << "catched : " << e.what() << '\n';
        }
    }
}

void Bureucrat::dec()
{
    grade++;
    if (grade > 150)
    {
        try
        {
            GradeTooLow();
        }
        catch(const std::exception& e)
        {
            std::cerr << "catched : " <<  e.what() << '\n';
        }
    }
}

void Bureucrat::NoGrade()
{
    throw(std::invalid_argument("No Grade were provided for the bureucrat"));
}

void Bureucrat::CheckGrade(const int &grade)
{
    if (grade < 1)
        GradeTooHigh();
    else if (grade > 150)
        GradeTooLow();
}

Bureucrat::Bureucrat(const std::string &n, int g):name(n),grade(g)
{
    std::cout << "Bureucrat Parametrized Constructor called\n";
    try
    {
        CheckGrade(grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catched : " <<  e.what() << std::endl;
    }
}

Bureucrat::Bureucrat():name(""),grade(0)
{
    std::cout << "Bureucrat Constructor called\n";
    try
    {
        NoGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catched : " <<  e.what() << std::endl;
    }
}
void Bureucrat::GradeTooHigh()
{
    throw(std::out_of_range("Your Grade is too high\n"));
}

void Bureucrat::GradeTooLow()
{
    throw(std::out_of_range("Your grade is too low\n"));
}

Bureucrat::~Bureucrat()
{
    std::cout << "Bureucrat Destructor called\n";
}

Bureucrat::Bureucrat(Bureucrat &other)
{
    std::cout << "Copy Constructor called\n";
    grade = other.getGrade();
    try
    {
        CheckGrade(grade);
    }
    catch(const std::exception& e)
    {
        std::cerr <<  "catched : " << e.what() << '\n';
    }
    
}