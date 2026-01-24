#include "Bureucrat.hpp"


int main()
{
    Bureucrat sadio("sadiomane", 10);
    std::cout << sadio << '\n';
    Bureucrat x;

    std::cout << "we still going\n";

    Bureucrat x1("x1", 160);
    Bureucrat x2("x2", 0);
    std::cout << x1;
    std::cout << x2;
    Bureucrat l("l", 1);
    for(int i = 0;i < 150;i++)
    {
        l.dec();
    }
    Bureucrat w("w", 1);
    w.inc();
    Bureucrat x11(w);
}