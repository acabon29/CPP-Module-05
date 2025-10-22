#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target_;

	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm  &operator=( const PresidentialPardonForm& other );
		virtual                 ~PresidentialPardonForm();

		virtual void		    execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm );