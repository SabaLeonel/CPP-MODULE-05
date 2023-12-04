#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 150);
    std::cout << *bureaucrat << std::endl;
    try{
        bureaucrat->decrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << *bureaucrat << std::endl;

    Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 1);
    std::cout << *bureaucrat2 << std::endl;
    try{
        bureaucrat2->incrementGrade();
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    std::cout << *bureaucrat2 << std::endl;

 
    delete bureaucrat;
    delete bureaucrat2;
    
    return (0);

}
