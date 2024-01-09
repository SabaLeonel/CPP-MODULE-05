#include "AForm.hpp"

AForm::AForm() : _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Default form constructor called" << std::endl;
}


AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    std::cout << "Default Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeToolowException();
}


AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "Default Form copy constructor called" << std::endl;
}

AForm::~AForm(){
    std::cout << "Default Form destructor called" << std::endl;
}

void AForm::CheckExecution(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeToolowException();
}

AForm &AForm::operator=(AForm const &other){
    this->_signed = other._signed;
    std::cout << "Only sign is copied" << std::endl;
    std::cout << "One Form assignation operator called" << std::endl;
    return (*this);
}

std::string const AForm::getName() const{
    return (_name);
}

bool AForm::getSigned() const{
    return (_signed);
}

int AForm::getGradeToSign() const{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const{
    return (_gradeToExecute);
}

void AForm::execute(Bureaucrat const & executor) const{
    this->CheckExecution(executor);
}

void AForm::beSigned(Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw AForm::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &out, AForm const &other){
    out << other.getName() << ", form grade to sign " << other.getGradeToSign() << ", form grade to execute " << other.getGradeToExecute() << ", form signed " << other.getSigned() << std::endl;
    return (out);
}
