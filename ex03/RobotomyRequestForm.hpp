#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    int requiredSignGrade;
    int requiredExecutionGrade;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &N);
    ~RobotomyRequestForm();
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