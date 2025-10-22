#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name_( "Default" ), grade_( 150 ) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name_( name ), grade_( grade ) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : name_( other.name_ ), grade_( other.grade_ ) {}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	if (this != &other) {
		this->grade_ = other.grade_;
		std::cerr << "Error : constant name." << std::endl;
	}
	return ( *this );
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	// out est une ref a std::ostream = flux de sortie
	// ca permet de faire std::cout << bureaucrat
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

const std::string &Bureaucrat::getName() const { return( name_ ); }
int Bureaucrat::getGrade() const { return( grade_ ); };


void Bureaucrat::incrementGrade() {
	if(grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	grade_--;
}

void Bureaucrat::decrementGrade() {
	if(grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	grade_++;
}



const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ( "Grade is too high!" );
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ( "Grade is too low!" );
}