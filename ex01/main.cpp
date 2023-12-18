#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat b1("b1", 1);
    Bureaucrat b2("b2", 150);
    Form f1("f1", 1, 1);
    Form f2("f2", 150, 150);

    b1.signForm(f1);
    b1.signForm(f2);
    b2.signForm(f1);
    b2.signForm(f2);

    return (0);

}
