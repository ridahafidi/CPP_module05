#ifndef A_FORM_HPP
#define A_FORM_HPP



#include <iostream>
#include <string>
#include <exception>
class Bureaucrat;

class AForm
{
private:
    const std::string N;
    bool sign;
    const int signGrade;
    const int executeGrade;
public:
    AForm();
    AForm(const std::string &name);
    AForm(const std::string &name, int sG, int eG);
    virtual ~AForm();
    virtual void DoExecution(Bureaucrat const &executor)const = 0;
    void execute(Bureaucrat const &executor) const;
    bool issigned() const;
    void beSigned();
    virtual const int &getSignGrade() const;
    virtual const int &getExecuteGrade() const;
    const std::string &getTarget() const { return N; }
    class AFormGradeTooLow : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
};
#endif