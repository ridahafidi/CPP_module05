#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
class Form;

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

#endif