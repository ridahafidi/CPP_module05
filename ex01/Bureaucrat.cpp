#include "Bureaucrat.hpp"
#include "Form.hpp"

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

const char* Bureaucrat::NoGradeException::what() const throw()
{
    return ("No Grade were provided for the Bureaucrat");
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
    throw(NoGradeException());
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

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what();
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat : Your Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat : Your grade is too low\n";
}