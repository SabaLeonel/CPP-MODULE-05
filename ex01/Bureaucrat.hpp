#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP
 

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Bureaucrat{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        std::string const getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form) const;
    private:
        std::string const _name;
        int _grade;
    class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    class GradeToolowException : public std::exception{
        public:
            virtual const char* what() const throw();
    };
    
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other);

#endif
