#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>
class Form;

class Bureaucrat
{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &n, int g);
    Bureaucrat(Bureaucrat &other);
    const std::string &getName() const;
    void inc();
    void dec();
    const int &getGrade()const;
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &other);
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class NoGradeException : public std::exception {
        const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    void signForm(Form& form);
};

std::ostream &operator<<(std::ostream &other, const Bureaucrat &Bureaucrat);

#endif