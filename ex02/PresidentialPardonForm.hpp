#ifndef  PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm : public virtual AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &other);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        
        void execute(Bureaucrat const &executor) const;
    private:
        void _action() const;
};

#endif
