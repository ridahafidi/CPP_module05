#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const char* ShrubberyCreationForm::SigningExceptionHighGrade::what() const throw()
{
    return ("ShruberryCreation Failed : Your Grade is Too High To Sign The ShrubberyCreationForm\n");
}

const char* ShrubberyCreationForm::ExecutingExceptionHighGrade::what() const throw()
{
    return ("ShruberryCreation Failed : Your Grade is Too High To Execute The ShrubberyCreationForm\n");
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShruberryCreationForm Constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &N) : AForm(N, 145, 137)
{
    std::cout << "ShrubberyCreationForm Parametrized Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShruberryCreationForm Destructor called\n";
}

void ShrubberyCreationForm::DoExecution(Bureaucrat const &executor) const
{
    const int &Grade = executor.getGrade();
    if (Grade > getSignGrade())
        throw (SigningExceptionHighGrade());
    if (Grade > getExecuteGrade())
        throw (ExecutingExceptionHighGrade());
    shrubs(getTarget());
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm Copy Constructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm Copy Assignement called\n";
    (void)other;
    return (*this);
}
