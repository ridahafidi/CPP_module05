#ifndef SHRUBERRYY_CREATION_FORM_HPP
#define SHRUBERRYY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    int requiredSignGrade;
    int requiredExecutionGrade;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &N);
    ~ShrubberyCreationForm();
    const int &getSignGrade() const;
    const int &getExecuteGrade() const;
    void DoExecution(Bureaucrat const &executor) const;
    class SigningExceptionHighGrade : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    
    class ExecutingExceptionHighGrade : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};
void shrubs(const std::string &target);
void drawSimpleTree(const std::ofstream &out);
#endif