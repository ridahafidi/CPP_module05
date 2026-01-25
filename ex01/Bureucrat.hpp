#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureucrat
{
private:
    const std::string name;
    int               grade;
public:
    Bureucrat();
    Bureucrat(const std::string &n, int g);
    Bureucrat(Bureucrat &other);
    const std::string &getName();
    void inc();
    void dec();
    const int &getGrade();
    virtual void GradeTooHighException();
    virtual void GradeTooLowException();
    void CheckGrade(const int &grade);
    virtual void NoGrade();
    virtual ~Bureucrat();
    void signForm();
    virtual void beSigned(Bureucrat &Bureucrat);
};
std::ostream &operator<<(std::ostream &other, Bureucrat &Bureucrat);



#endif