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
    ~ShrubberyCreationForm();
    void DoExecution(Bureucrat const &executor) const;
    class SigningExceptionHighGrade : std::exception
    {
        virtual const char* what() const throw();
    };
    
    class ExecutingExceptionHighGrade : std::exception
    {
        virtual const char* what() const throw();
    };
};
void shrubs(const std::string &target);
void drawSimpleTree(int height, const std::ofstream &out);

const char* ShrubberyCreationForm::SigningExceptionHighGrade::what() const throw()
{
    return ("Your Grade is Too High To Sign The ShrubberyCreationForm\n");
}

const char* ShrubberyCreationForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("Your Grade is Too High To Execute The ShrubberyCreationForm\n");
}

ShrubberyCreationForm::ShrubberyCreationForm():requiredSignGrade(145), requiredExecutionGrade(137)
{
    std::cout << "ShruberryCreationForm Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShruberryCreationForm Destructor called\n";
}

void ShrubberyCreationForm::DoExecution(Bureucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > requiredSignGrade)
        throw (SigningExceptionHighGrade());
    if (Grade > requiredExecutionGrade)
        throw (ExecutingExceptionHighGrade());
    shrubs(executor.getName());
}

void drawSimpleTree(int height, std::ofstream &out) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 0; j < height - i; ++j)
            out << " ";
        for (int j = 0; j < 2 * i - 1; ++j)
            out << "*";
        out << std::endl;
    }
    // Draw the trunk
    for (int j = 0; j < height - 1; ++j)
        out << " ";
    out << "|" << std::endl;
}

void shrubs(const std::string &target)
{
    std::ofstream out(target + "_shruberry");
}
#endif