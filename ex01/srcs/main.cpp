#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    std::cout << "---------------------------" << std::endl;
    
    try {
        Bureaucrat bob("bob", 3);
        std::cout << bob << std::endl;

        Form form1("form1", 100, 100);
        Form form2("form2", 2, 1);
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        bob.signForm(form1);
        //error :
        bob.signForm(form2);      
          
        std::cout << "---------------------------" << std::endl;

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Form::GradeTooHighException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << "Error for bob: " << e.what() << std::endl;
    }

    std::cout << "---------------------------" << std::endl;

    return ( 0 );
}
