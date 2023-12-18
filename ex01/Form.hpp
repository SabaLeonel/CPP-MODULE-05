#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private :
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public :
        Form();
        ~Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const &other);
        Form &operator=(Form const &other);
        std::string const getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw();
        };
        class GradeToolowException : public std::exception {
            public :
                virtual const char* what() const throw();
        };
};

#endif
