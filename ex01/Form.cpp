#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

const int &Form::getExecuteGrade() const
{
    return (executeGrade);
}

const int &Form::getSignGrade() const
{
    return(signGrade);
}
const std::string &Form::getName() const
{
    return (N);
}
std::ostream &operator<< (std::ostream &os, const Form &in){
    std::cout << "Form name is : " << in.getName() << " my required Grade for Signing is : " << in.getSignGrade()
    << " and my execute Grade is : " << in.getExecuteGrade() << std::endl;
    return (os);
}

void    Form::beSignedCheck(const int &BureaucratGrade, const int &requiredGrade)
{
    if (BureaucratGrade > requiredGrade)
        throw (std::out_of_range("BureaucratGrade is too lower to be signed\n"));
    if (BureaucratGrade < 1)
        throw (std::out_of_range("BureaucratGrade is too High\n"));
    else
        sign = true;
}

void    Form::beSigned(Bureaucrat &Bureaucrat)
{
    beSignedCheck(Bureaucrat.getGrade(), signGrade);
}

Form::Form():N(""),sign(false),signGrade(0),executeGrade(0)
{
    std::cout << "Form Constructor called\n";
    throw(std::invalid_argument("No Grade were provided for the Form"));
    
}

Form::Form(const std::string &n, const int &sG, const int &eG):N(n), sign(false) , signGrade(sG), executeGrade(eG)
{
    std::cout << "Form Parametrized Constructor called\n";
    if (sG < 1 || eG < 1)
        throw(Form::GradeTooHighException());
    else if (sG > 150 || eG > 150)
        throw(Form::GradeTooLowException());
}

Form::~Form()
{
    std::cout << "Form Destructor called\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form : Your Grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form : Your grade is too low\n";
}
