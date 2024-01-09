#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    try{
        Intern intern;
        AForm *form;
         // Create a Bureaucrat with a different name and rank

        // Request a different type of form
        form = intern.makeForm("RobotomyRequestForm", "target");
        Bureaucrat bar("bar", 1); 
        bar.signForm(*form);
        bar.executeForm(*form);
        delete form;
    }
    catch(std::exception const &e)
    {
        std::cerr << "error \t" << e.what() << std::endl;
    }

    return (0);
}
