#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "Default", 25, 5 ), target_( "Default" ) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm( target, 25, 5 ), target_( target ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm( other ), target_( other.target_ ) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
		target_ = other.target_;
	return ( *this );
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() == false)
		throw FileNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm) {
	out << "Name of the form: " << PresidentialPardonForm.getName() << ", ";
	if (PresidentialPardonForm.getSigned())
		out	<< "signed: true, ";
	else
		out	<< "signed: false, ";
	out	<< "signing grade: " << PresidentialPardonForm.getGradeToSign() << ", ";
	out	<< "executing grade: " << PresidentialPardonForm.getGradeToExecute();
    return out;
}