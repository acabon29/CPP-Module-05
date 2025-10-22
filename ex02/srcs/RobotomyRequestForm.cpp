#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm( "Default", 72, 45 ), target_( "Default" ) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm( target, 72, 45 ), target_( target ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm( other ), target_( other.target_ ) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
		target_ = other.target_;
	return ( *this );
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() == false)
		throw FileNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "BZZZZZZT ! CLANK ! CLANK ! BZZZZZZT !" << std::endl;

	std::srand(std::time(NULL)); // change the seed
	if (std::rand() % 2 == 0) {
		std::cout << target_ << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << target_ << ": robotomy failed..." << std::endl;
	} 
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm) {
	out << "Name of the form: " << RobotomyRequestForm.getName() << ", ";
	if (RobotomyRequestForm.getSigned())
		out	<< "signed: true, ";
	else
		out	<< "signed: false, ";
	out	<< "signing grade: " << RobotomyRequestForm.getGradeToSign() << ", ";
	out	<< "executing grade: " << RobotomyRequestForm.getGradeToExecute();
    return out;
}