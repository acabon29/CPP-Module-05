#include "Form.hpp"

Form::Form( void ) : name_( "Default" ), signed_( false ), gradeToSign_ ( 150 ), gradeToExecute_ ( 150 ) {}

Form::Form( const std::string name, const int gradeToSign, const int gradeToExecute ) :
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

Form::Form( const Form &other ) :
	name_( other.name_ ),
	signed_( other.signed_ ),
	gradeToSign_ ( other.gradeToSign_ ),
	gradeToExecute_ ( other.gradeToExecute_ )
{}

Form::~Form( void ) {}

Form &Form::operator=( const Form &other ) {
	if (this != &other) {
		this->signed_ = other.signed_;
		std::cerr << "Error : constant name." << std::endl;
		std::cerr << "Error : constant gradeToSign." << std::endl;
		std::cerr << "Error : constant gradeToExecute." << std::endl;
	}
	return ( *this );
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
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

const std::string &Form::getName() const { return( name_ ); }
bool Form::getSigned() const { return( signed_ ); }
int	Form::getGradeToSign() const { return( gradeToSign_ ); }
int	Form::getGradeToExecute() const { return( gradeToExecute_ ); }

void Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	else
		signed_ = true;
}


const char* Form::GradeTooHighException::what() const throw() {
	return ( "Grade is too high!" );
}

const char* Form::GradeTooLowException::what() const throw() {
	return ( "Grade is too low!" );
}