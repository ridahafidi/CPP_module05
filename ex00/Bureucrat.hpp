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
    void GradeTooHigh();
    void GradeTooLow();
    void CheckGrade(const int &grade);
    void NoGrade();
    ~Bureucrat();
};
std::ostream &operator<<(std::ostream &other, Bureucrat &Bureucrat);


#endif