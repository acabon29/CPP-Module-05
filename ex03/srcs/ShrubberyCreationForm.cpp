#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "Default", 145, 137 ), target_( "Default" ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( target, 145, 137 ), target_( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm( other ), target_( other.target_ ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other)
		target_ = other.target_;
	return ( *this );
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (this->getSigned() == false)
		throw FileNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = target_ + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: cannot create file." << std::endl;
		return ;
	}

	file << "            .        +          .      .          ."
		<< "     .            _        .                    ."
		<< "  ,              /;-._,-.____        ,-----.__"
		<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,"
		<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /"
		<< "                      ,    `./  \\:. `.   )==-'  ."
		<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ."
		<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o"
		<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ."
		<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7"
		<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/"
		<< "              \\:  `  X` _| _,\\/'   .-'"
		<< ".               \":._:`\\____  /:'  /      .           ."
		<< "                    \\::.  :\\/:'  /              +"
		<< "   .                 `.:.  /:'  }      ."
		<< "           .           ):_(:;   \\           ."
		<< "                      /:. _/ ,  |"
		<< "                   . (|::.     ,`                  ."
		<< "     .                |::.    {\\"
		<< "                      |::.\\  \\ `."
		<< "                      |:::(\\    |"
		<< "              O       |:::/{ }  |                  (o"
		<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`"
		<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~"
		<< "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~"
		 << std::endl;

	file.close();
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm) {
	out << "Name of the form: " << ShrubberyCreationForm.getName() << ", ";
	if (ShrubberyCreationForm.getSigned())
		out	<< "signed: true, ";
	else
		out	<< "signed: false, ";
	out	<< "signing grade: " << ShrubberyCreationForm.getGradeToSign() << ", ";
	out	<< "executing grade: " << ShrubberyCreationForm.getGradeToExecute();
    return out;
}