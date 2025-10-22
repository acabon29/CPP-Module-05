#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    std::cout << "--------------------------" << std::endl;
    
    try {
        Bureaucrat boss("Boss", 1);  // Grade max
        
        // Shrubbery
        ShrubberyCreationForm shrubbery("home");
        boss.signForm(shrubbery);
        boss.executeForm(shrubbery);
        
        // Robotomy
        RobotomyRequestForm robotomy("Target");
        boss.signForm(robotomy);
        boss.executeForm(robotomy);
        
        // Presidential
        PresidentialPardonForm pardon("Bob");
        boss.signForm(pardon);
        boss.executeForm(pardon);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    // ShrubberyCreationForm - Grade insuffisant
    try {
        Bureaucrat body("body", 140);
        ShrubberyCreationForm shrubbery("garden");
        
        body.signForm(shrubbery);
        // error :
        body.executeForm(shrubbery);
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "--------------------------" << std::endl;

    // RobotomyRequestForm - Formulaire non signe
    try {
        Bureaucrat boblton("boblton", 40);
        RobotomyRequestForm robotomy("Patient");
        
        // error :
        boblton.executeForm(robotomy);
        
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "--------------------------" << std::endl;

    // PresidentialPardonForm - Grade insuffisant
    try {
        Bureaucrat bobacool("bobacool", 50);
        PresidentialPardonForm pardon("Criminal");
        
        // error :
        bobacool.signForm(pardon);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;
    return ( 0 );
}
