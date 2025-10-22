#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const Intern& other );
		~Intern();
		Intern	&operator=( const Intern& other );

		AForm*	makeForm( const std::string &formName, const std::string &target );
		AForm*	makeShrubberyCreationForm( const std::string &target );
		AForm*	makeRobotomyRequestForm( const std::string &target );
		AForm*	makePresidentialPardonForm( const std::string &target );
};