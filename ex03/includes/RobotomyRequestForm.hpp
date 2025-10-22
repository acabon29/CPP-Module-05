#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target_;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm& other );
		virtual             ~RobotomyRequestForm();

		virtual void		execute( Bureaucrat const & executor ) const;
};

std::ostream	&operator<<( std::ostream& out, const RobotomyRequestForm& RobotomyRequestForm );