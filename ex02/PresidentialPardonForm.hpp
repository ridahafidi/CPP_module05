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
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
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





#endif