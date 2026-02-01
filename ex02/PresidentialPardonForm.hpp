#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    void DoExecution(Bureaucrat const &executor) const;
class SigningExceptionHighGrade : public std::exception
    {
        public:
            const char* what() const throw();
    };
    
    class ExecutingExceptionHighGrade : public std::exception
    {
        public:
            const char* what() const throw();
    };
};





#endif