#include "Bureucrat.hpp"
#include "Form.hpp"

int main()
{
    Form l;
    Form f("sdasd", 13, 14);

    std::cout << f;
    Bureucrat B("zba7MM", 4);
    f.signForm();
    l.signForm();
    B.signForm();
    Bureucrat *x1;
    x1 = &f;
    x1->signForm();
}