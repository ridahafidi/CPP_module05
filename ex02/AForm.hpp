#ifndef A_FORM_HPP
#define A_FORM_HPP



#include <iostream>
#include <string>
#include <exception>
#include "Bureucrat.hpp"

class AForm
{
private:
    const std::string N;
    bool sign;
    const int signGrade;
    const int executeGrade;
public:
    AForm();
    virtual ~AForm();
    virtual void DoExecution(Bureucrat const &executor)const = 0;
    class AFormNoGradeException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    void execute(Bureucrat const &executor) const;
    bool issigned() const;
    const int &getSignGrade() const;
    const int &getExecuteGrade() const;
    class AFormNotSignedException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class AFormGradeTooLow : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
};

const char* AForm::AFormNotSignedException::what() const throw()
{
    return ("The Form is not signed\n");
}

const char* AForm::AFormGradeTooLow::what() const throw()
{
    return ("The Target Grade is Too Low\n");
}

bool AForm::issigned()const
{
    return (sign);
}


const int &AForm::getExecuteGrade() const
{
    return (executeGrade);
}

const int &AForm::getSignGrade() const
{
    return(signGrade);
}

void AForm::execute(Bureucrat const &executor) const
{
    int Grade = executor.getGrade();
    const int &FormExGrade = getExecuteGrade();
    const int &FormsignGrade = getSignGrade();
    if (issigned() == false)
        throw(AFormNotSignedException());
    if(Grade > FormExGrade)
        throw(AFormGradeTooLow());
    DoExecution(executor);
}

const char* AForm::AFormNoGradeException::what() const throw()
{
    return ("You haven't provided any data member value of AForm\n");
}
AForm::AForm():N(""), sign(true), signGrade(0), executeGrade(0)
{
    std::cout << "AForm Constructor called\n";
    // throw (AFormNoGradeException());
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called\n";
}



#endif