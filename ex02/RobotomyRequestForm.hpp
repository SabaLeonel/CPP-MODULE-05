#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        std::string const getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif