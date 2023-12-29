#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default"){
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target){
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this != &other)
        _target = other._target;
    return (*this);
}

std::string const ShrubberyCreationForm::getTarget() const{
    return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (executor.getGrade() > _gradeToExecute)
        throw Form::GradeTooHighException();
    else if (!_signed)
        throw Form::FormNotSignedException();
    else{
        std::ofstream file;
        file.open(_target + "_shrubbery");
        file << "      /\\\n";
        file << "     /\\*\\\n";
        file << "    /\\O\\*\\\n";
        file << "   /*/\\/\\/\\\n";
        file << "  /\\O\\/\\*\\/\\\n";
        file << " /\\*\\/\\*\\/\\/\\\n";
        file << "/\\O\\/\\/*/\\/O/\\\n";
        file << "      ||\n";
        file << "      ||\n";
        file << "      ||\n";
        file << "    \\====/\n";
        file << "     \\__/  hjw\n";
        file.close();
    }
}
