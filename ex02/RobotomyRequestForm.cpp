#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default"){
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &other)
        _target = other._target;
    return (*this);
}

std::string const RobotomyRequestForm::getTarget() const{
    return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > _gradeToExecute)
        throw Form::GradeTooHighException();
    else if (!_signed)
        throw Form::FormNotSignedException();
    else{
        std::cout << "* drilling noises *" << std::endl;
        if (rand() % 2 == 0)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << _target << " robotomization failed" << std::endl;
    }
}

