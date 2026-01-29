#include "Bureaucrat.hpp"


int main()
{
   
    try
   {
    Bureaucrat P;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
    
   
   try
   {
    Bureaucrat P ("b2", 0);
    Bureaucrat x ("b1", 151);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   
   
   try
   {
    Bureaucrat x ("b1", 151);
    Bureaucrat P ("b2", 0);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }

   try
   {
    Bureaucrat x ("b1", 10);
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