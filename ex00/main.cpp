#include "Bureucrat.hpp"


int main()
{
   
    try
   {
    Bureucrat P;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
    
   
   try
   {
    Bureucrat P ("b2", 0);
    Bureucrat x ("b1", 151);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
   
   try
   {
    Bureucrat x ("b1", 151);
    Bureucrat P ("b2", 0);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }

   try
   {
    Bureucrat x ("b1", 10);
    std::cout << x;
    x.inc();
    std::cout << x;
    for (int i = 0;i< 10 ;i++)
        x.inc();
    std::cout << x;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
}