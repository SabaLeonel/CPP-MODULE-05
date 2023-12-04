#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeToolowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name){
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
    std::cout << "Bureaucrat assignation operator called" << std::endl;
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

std::string const Bureaucrat::getName() const{
    return (_name);
}

int Bureaucrat::getGrade() const{
    return (_grade);
}

void Bureaucrat::incrementGrade(){
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeToolowException();
    else
        _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade too high");
}

const char* Bureaucrat::GradeToolowException::what() const throw(){
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other){
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (out);
}


