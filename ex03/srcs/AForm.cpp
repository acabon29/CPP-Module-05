#include "AForm.hpp"

AForm::AForm( void ) : name_( "Default" ), signed_( false ), gradeToSign_ ( 150 ), gradeToExecute_ ( 150 ) {}

AForm::AForm( const std::string name, const int gradeToSign, const int gradeToExecute ) :
		name_( name ),
		signed_( false ),
		gradeToSign_ ( gradeToSign ),
		gradeToExecute_ ( gradeToExecute )
{
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm( const AForm &other ) :
	name_( other.name_ ),
	signed_( other.signed_ ),
	gradeToSign_ ( other.gradeToSign_ ),
	gradeToExecute_ ( other.gradeToExecute_ )
{}

AForm::~AForm( void ) {}

AForm &AForm::operator=( const AForm &other ) {
	if (this != &other) {
		this->signed_ = other.signed_;
		std::cerr << "Error : constant name." << std::endl;
		std::cerr << "Error : constant gradeToSign." << std::endl;
		std::cerr << "Error : constant gradeToExecute." << std::endl;
	}
	return ( *this );
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "Name of the form: " << form.getName() << ", ";
	// (form.getSigned() ? out	<< "signed: true, " : out	<< "signed: false, ");
	if (form.getSigned())
		out	<< "signed: true, ";
	else
		out	<< "signed: false, ";
	out	<< "signing grade: " << form.getGradeToSign() << ", ";
	out	<< "executing grade: " << form.getGradeToExecute();
    return out;
}

const std::string &AForm::getName() const { return( name_ ); }
bool AForm::getSigned() const { return( signed_ ); }
int	AForm::getGradeToSign() const { return( gradeToSign_ ); }
int	AForm::getGradeToExecute() const { return( gradeToExecute_ ); }

void AForm::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	else
		signed_ = true;
}


const char* AForm::GradeTooHighException::what() const throw() {
	return ( "Grade is too high!" );
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ( "Grade is too low!" );
}

const char*	AForm::FileNotSignedException::what() const throw() {
	return ( "file is not signed" );
}