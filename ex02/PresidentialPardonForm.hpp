#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    int requiredSignGrade;
    int requiredExecutionGrade;
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    const int &getSignGrade() const;
    const int &getExecuteGrade() const;
    void DoExecution(Bureucrat const &executor) const;
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





#endif