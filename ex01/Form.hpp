#ifndef FORM_HPP
#define FORM_HPP

#include "Bureucrat.hpp"

class Form
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
    void beSigned(Bureucrat &Bureucrat);
    void beSignedCheck(const int &BureucratGrade, const int &requiredGrade);
    ~Form();
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };
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
    beSignedCheck(Bureucrat.getGrade(), signGrade);
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
        throw(GradeTooHighException());
    else if (sG > 150 || eG > 150)
        throw(GradeTooLowException());
}

Form::~Form()
{
    std::cout << "Form Destructor called\n";
}



#endif