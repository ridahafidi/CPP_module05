#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

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
    void NoGrade();
    ~Bureucrat();
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };
    void signForm(Form& form);
};
std::ostream &operator<<(std::ostream &other, Bureucrat &Bureucrat);

void Bureucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

#endif