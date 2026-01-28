#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
class Bureucrat
{
private:
    const std::string name;
    int               grade;
public:
    Bureucrat();
    Bureucrat(const std::string &n, int g);
    Bureucrat(Bureucrat &other);
    const std::string &getName() const;
    void inc();
    void dec();
    const int &getGrade()const;
    void NoGrade();
    ~Bureucrat();
    void executeForm(AForm const & form) const;
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &other, const Bureucrat &Bureucrat);


#endif