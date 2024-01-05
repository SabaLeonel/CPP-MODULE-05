#include "Intern.hpp"


Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other) {
    (void)other;
    return (*this);
}

static AForm *makeShrubberyCreationForm(std::string const &target) {
    return (new ShrubberyCreationForm(target));
}

static AForm *makePresidentialPardonForm(std::string const &target) {
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm(std::string const &target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string const formName, std::string target)
{
    t_form forms[] = {
        {"ShrubberyCreationForm", makeShrubberyCreationForm},
        {"PresidentialPardonForm", makePresidentialPardonForm},
        {"RobotomyRequestForm", makeRobotomyRequestForm},
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].f(target));
        }
    }


    std::cout << "Intern cannot create " << formName << std::endl;

    return (NULL);
}