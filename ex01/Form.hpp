#ifndef FORM_HPP
#define FORM_HPP

#include "Bureucrat.hpp"

class Form : public Bureucrat
{
private:
    const std::string N;
    bool sign;
    const int signGrade;
    const int executeGrade;
public:
    Form();
    Form(const std::string &n, const int &sG, const int &eG);
    const std::string &getName();
    const int &getSignGrade();
    const int &getExecuteSign();
    void GradeTooHighException();
    void GradeTooLowException();
    void NoGrade();
    void CheckGrade(const int &sG, const int &sE);
    void beSigned(Bureucrat &Bureucrat);
    void beSignedCheck(const int &BureucratGrade, const int &requiredGrade);
    ~Form();
};
std::ostream &operator<< (std::ostream &os, const Form &in);

const int &Form::getExecuteSign()
{
    return (executeGrade);
}

const int &Form::getSignGrade()
{
    return(signGrade);
}
const std::string &Form::getName()
{
    return (N);
}
std::ostream &operator<< (std::ostream &os, Form &in){
    std::cout << "Form name is : " << in.getName() << " my required Grade for Signing is : " << in.getSignGrade()
    << " and my execute Grade is : " << in.getExecuteSign() << std::endl;
    return (os);
}

void    Form::beSignedCheck(const int &BureucratGrade, const int &requiredGrade)
{
    if (BureucratGrade > signGrade)
        throw (std::out_of_range("BureucratGrade is too lower to be signed\n"));
    if (BureucratGrade < 1)
        throw (std::out_of_range("BureucratGrade is too High\n"));
    else
        sign = true;
}

void    Form::beSigned(Bureucrat &Bureucrat)
{
    try
    {
        beSignedCheck(Bureucrat.getGrade(), signGrade);
        throw(N);
    }
    catch(const std::exception& e)
    {
        std::cerr << "beSigned catched : " << e.what() << '\n';
    }
}

void Form::NoGrade()
{
    throw(std::invalid_argument("No Grade were provided for the Form"));
}

void Form::CheckGrade(const int &sG, const int &sE)
{
    if (sG < 1 || sE < 1)
        GradeTooHighException();
    else if (sG > 150 || sE > 150)
        GradeTooLowException();
}

void Form::GradeTooHighException()
{
    throw(std::out_of_range("Form : Your Grade is too high\n"));
}

void Form::GradeTooLowException()
{
    throw(std::out_of_range("Form : Your grade is too low\n"));
}

Form::Form():N(""),sign(false),signGrade(0),executeGrade(0)
{
    std::cout << "Form Constructor called\n";
    try
    {
        NoGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "catched : " << e.what() << '\n';
    }
    
}

Form::Form(const std::string &n, const int &sG, const int &eG):N(n), sign(false) , signGrade(sG), executeGrade(eG)
{
    std::cout << "Form Parametrized Constructor called\n";
    try
    {
        CheckGrade(sG, eG);
    }
    catch(const std::exception& e)
    {
        std::cerr << "catched" << e.what() << '\n';
    }
    
}

Form::~Form()
{
    std::cout << "Form Destructor called\n";
}



#endif