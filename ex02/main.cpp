#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"

#include <iostream>
// Assuming the necessary headers and class definitions for Bureaucrat and form types are included

int main() {
    // First scenario with a high-ranked bureaucrat
    try {
        Bureaucrat seniorOfficial("Alice", 1);
        ShrubberyCreationForm greenProject("GreenPark");

        seniorOfficial.signForm(greenProject);
        seniorOfficial.executeForm(greenProject);
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Second scenario with a low-ranked bureaucrat
    // try {
    //     Bureaucrat juniorOfficial("Bob", 150);
    //     ShrubberyCreationForm cityProject("CityCenter");

    //     juniorOfficial.signForm(cityProject);
    //     juniorOfficial.executeForm(cityProject);
    // } catch(const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // // Third scenario with an intermediate-ranked bureaucrat
    // try {
    //     Bureaucrat midLevelOfficial("Charlie", 75);
    //     RobotomyRequestForm robotRequest("RoboticsLab");

    //     midLevelOfficial.signForm(robotRequest);
    //     midLevelOfficial.executeForm(robotRequest);
    // } catch(const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // // Fourth scenario with a different form
    // try {
    //     Bureaucrat experiencedOfficial("Diana", 20);
    //     PresidentialPardonForm pardonRequest("JohnDoe");

    //     experiencedOfficial.signForm(pardonRequest);
    //     experiencedOfficial.executeForm(pardonRequest);
    // } catch(const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    // // Fifth scenario with a top-level bureaucrat
    // try {
    //     Bureaucrat topOfficial("Edward", 1);
    //     PresidentialPardonForm highProfileCase("HighProfile");

    //     topOfficial.signForm(highProfileCase);
    //     topOfficial.executeForm(highProfileCase);
    // } catch(const std::exception& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}