#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private :
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public :
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const &other);
        ~AForm();
        AForm &operator=(AForm const &other);
        std::string const getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void CheckExecution(Bureaucrat const & executor) const;
        void beSigned(const Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw()
                {
                    return ("The form can't be signed because the grade is too high");
                }
        };
        class GradeToolowException : public std::exception {
            public :
                virtual const char* what() const throw()
                {
                    return ("The form can't be signed because the grade is too low");
                }
        };
        class FormNotSignedException : public std::exception {
            public :
                virtual const char* what() const throw()
                {
                    return ("The form isn't signed");
                }
        };
        virtual void execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out, AForm const &other);

#endif
