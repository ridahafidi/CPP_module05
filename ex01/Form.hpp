#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureucrat;

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
    const std::string &getName() const;
    const int &getSignGrade() const;
    const int &getExecuteSign() const;
    void beSigned(Bureucrat &b);
    void beSignedCheck(const int &BureucratGrade, const int &requiredGrade);
    ~Form();
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
std::ostream &operator<< (std::ostream &os, const Form &in);

#endif