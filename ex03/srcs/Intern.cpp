#include "Intern.hpp"


static AForm *(Intern::*functions[])(const std::string &target) = {
    &Intern::makeShrubberyCreationForm,
    &Intern::makeRobotomyRequestForm,
    &Intern::makePresidentialPardonForm
};

static std::string	names[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::Intern() {}

Intern::Intern( const Intern& other ) {
    (void)other;
}

Intern::~Intern() {}

Intern	&Intern::operator=( const Intern& other ) {
	(void)other;
	return *this;
}

AForm*	Intern::makeShrubberyCreationForm( const std::string &target ) { return ( new ShrubberyCreationForm(target) ); }
AForm*	Intern::makeRobotomyRequestForm( const std::string &target ) { return ( new RobotomyRequestForm(target) ); }
AForm*	Intern::makePresidentialPardonForm( const std::string &target ) { return ( new PresidentialPardonForm(target) ); }

AForm*	Intern::makeForm( const std::string &name, const std::string &target ) 
{
	AForm*	newForm = NULL;

	for (int i = 0; i < 3; i++) {
		if (names[i] == name)
			newForm = (this->*functions[i])(target);
	}

	if (newForm != NULL)
		std::cout << "Interne creates " << name << std::endl;
	else
		std::cout << "Error: intern cannot create " << name << " because it does not exist." << std::endl;
	return newForm;
}