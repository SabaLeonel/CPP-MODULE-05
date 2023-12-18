#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    std::cout << "Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeToolowException();
}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "Form copy constructor called" << std::endl;
    *this = other;
}

Form &Form::operator=(Form const &other){
    std::cout << "Form assignation operator called" << std::endl;
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

std::string const Form::getName() const{
    return (_name);
}

bool Form::getSigned() const{
    return (_signed);
}

int Form::getGradeToSign() const{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const{
    return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooHighException();
    else
        _signed = true;
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade too high");
}

const char* Form::GradeToolowException::what() const throw(){
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &other){
    out << other.getName() << ", form grade to sign " << other.getGradeToSign() << ", form grade to execute " << other.getGradeToExecute() << ", form signed " << other.getSigned() << std::endl;
    return (out);
}
