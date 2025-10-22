
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target_;
		
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string& target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm   &operator=( const ShrubberyCreationForm& other );
		virtual                 ~ShrubberyCreationForm();

		virtual void		    execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const ShrubberyCreationForm& ShrubberyCreationForm );
