#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::AFormGradeTooLow::what() const throw()
{
    return ("The Target Grade is Too Low\n");
}

bool AForm::issigned() const
{
    return (sign);
}

const int &AForm::getExecuteGrade() const
{
    return (executeGrade);
}

const int &AForm::getSignGrade() const
{
    return (signGrade);
}

void AForm::beSigned()
{
    sign = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    int Grade = executor.getGrade();
    const int &FormExGrade = getExecuteGrade();
    if (Grade > FormExGrade)
        throw(AFormGradeTooLow());
    DoExecution(executor);
}

AForm::AForm():N(""), sign(false), signGrade(0), executeGrade(0)
{
    std::cout << "AForm Constructor called\n";
}

AForm::AForm(const std::string &name, int sG, int eG):N(name), sign(false), signGrade(sG), executeGrade(eG)
{
    std::cout << "AForm Parametrized Constructor called\n";
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called\n";
}
