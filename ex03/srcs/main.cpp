#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main( void )
{
    std::cout << "--------------------------" << std::endl;

    // "shrubbery creation",
    // "robotomy request",
    // "presidential pardon"
    
    try {
        Bureaucrat boss("Boss", 1);
        Intern intern;
        
        // ShrubberyCreationForm
        AForm* form1 = intern.makeForm("shrubbery creation", "garden");
        if (form1) {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        
        std::cout << "--------------------------" << std::endl;

        // RobotomyRequestForm
        AForm* form2 = intern.makeForm("robotomy request", "target");
        if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        
        std::cout << "--------------------------" << std::endl;

        // PresidentialPardonForm
        AForm* form3 = intern.makeForm("presidential pardon", "criminal");
        if (form3) {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
        
        std::cout << "--------------------------" << std::endl;

        // Formulaire inconnu
        AForm* form4 = intern.makeForm("unknown form", "test");
        if (form4) {
            std::cout << "Erreur: formulaire cree" << std::endl;
            delete form4;
        } else {
            std::cout << "Formulaire inconnu" << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;
    return ( 0 );
}
