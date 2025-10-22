#include "Bureaucrat.hpp"

int main( void )
{
    std::cout << "---------------------------" << std::endl;
    
    try {
        Bureaucrat bob("bob", 3);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        bob.incrementGrade();
        std::cout << bob << std::endl;
        //error :
        bob.incrementGrade();
        std::cout << "TEST 1 !!!!!!" << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
    
    try {
        Bureaucrat bob("bob", 0);
        std::cout << "TEST 2 !!!!!!" << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
    
    try {
        Bureaucrat bob("bob", 0);
        std::cout << "TEST 3 !!!!!!" << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;

    return ( 0 );
}
