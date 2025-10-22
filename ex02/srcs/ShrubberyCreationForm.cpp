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

	file << "            .        +          .      .          ." << std::endl
		<< "     .            _        .                    ." << std::endl
		<< "  ,              /;-._,-.____        ,-----.__" << std::endl
		<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
		<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl
		<< "                      ,    `./  \\:. `.   )==-'  ." << std::endl
		<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl
		<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl
		<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl
		<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl
		<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl
		<< "              \\:  `  X` _| _,\\/'   .-'" << std::endl
		<< ".               \":._:`\\____  /:'  /      .           ." << std::endl
		<< "                    \\::.  :\\/:'  /              +" << std::endl
		<< "   .                 `.:.  /:'  }      ." << std::endl
		<< "           .           ):_(:;   \\           ." << std::endl
		<< "                      /:. _/ ,  |" << std::endl
		<< "                   . (|::.     ,`                  ." << std::endl
		<< "     .                |::.    {\\" << std::endl
		<< "                      |::.\\  \\ `." << std::endl
		<< "                      |:::(\\    |" << std::endl
		<< "              O       |:::/{ }  |                  (o" << std::endl
		<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl
		<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl
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