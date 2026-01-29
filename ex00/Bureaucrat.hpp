#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    const std::string name;
    int               grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string &n, int g);
    Bureaucrat(Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    const std::string &getName() const;
    void inc();
    void dec();
    const int &getGrade()const;
    ~Bureaucrat();
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class NoGradeException : public std::exception {
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
std::ostream &operator<<(std::ostream &other, const Bureaucrat &Bureaucrat);


#endif