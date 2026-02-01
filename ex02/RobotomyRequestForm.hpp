#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
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