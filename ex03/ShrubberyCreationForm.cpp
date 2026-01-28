#include "ShrubberyCreationForm.hpp"
#include "Bureucrat.hpp"

const int &ShrubberyCreationForm::getSignGrade() const
{
    return (requiredSignGrade);
}

const int &ShrubberyCreationForm::getExecuteGrade() const
{
    return (requiredExecutionGrade);
}
const char* ShrubberyCreationForm::SigningExceptionHighGrade::what() const throw()
{
    return ("ShruberryCreation Failed : Your Grade is Too High To Sign The ShrubberyCreationForm\n");
}

const char* ShrubberyCreationForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("ShruberryCreation Failed : Your Grade is Too High To Execute The ShrubberyCreationForm\n");
}

ShrubberyCreationForm::ShrubberyCreationForm():requiredSignGrade(145), requiredExecutionGrade(137)
{
    std::cout << "ShruberryCreationForm Constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &N):AForm(N, 145, 137), requiredSignGrade(145), requiredExecutionGrade(137)
{
    std::cout << "ShrubberyCreationForm Parametrized Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShruberryCreationForm Destructor called\n";
}

void ShrubberyCreationForm::DoExecution(Bureucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > requiredSignGrade)
        throw (SigningExceptionHighGrade());
    if (Grade > requiredExecutionGrade)
        throw (ExecutingExceptionHighGrade());
    shrubs(executor.getName());
}

void drawSimpleTree(std::ofstream &out) {
        out << 
"           *\n"
"          ***\n"
"         *****\n"
"        *******\n"
"       *********\n"
"      ***********\n"
"           |\n"
"           |\n"
"\n"
"              *\n"
"            * * *\n"
"          * * * * *\n"
"        * * * * * * *\n"
"      * * * * * * * * *\n"
"             ||\n"
"             ||\n"
"\n"
"        ###########\n"
"     #################\n"
"   #####################\n"
"  #######################\n"
"   #####################\n"
"     #################\n"
"        ###########\n"
"            |||\n"
"            |||\n"
"            |||\n"
"\n"
"              *\n"
"             /***\\\n"
"            /*****\\\n"
"           /*******\\\n"
"          /*********\\\n"
"         /***********\\\n"
"              ||\n"
"              ||\n"
"\n"
"                ^\n"
"               ^^^\n"
"              ^^^^^\n"
"             ^^^^^^^\n"
"            ^^^^^^^^^\n"
"           ^^^^^^^^^^^\n"
"                |\n"
"                |\n"
"                |\n";
}

void shrubs(const std::string &target)
{
    std::ofstream out((target + "_shruberry").c_str());
    drawSimpleTree(out);
}