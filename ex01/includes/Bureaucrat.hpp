#pragma once

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const		std::string name_;
		int			grade_;
		
		public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat			&operator=( const Bureaucrat &other );
		virtual				~Bureaucrat( void );
		
		const std::string	&getName() const;
		int					getGrade() const;
		
		void				incrementGrade();
		void				decrementGrade();
		void				signForm( Form &form ) const;

		// class imbriquee :
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

// on aurais pu utiliser le mot clef "friend" mais c'est interdit...
std::ostream				&operator<<( std::ostream &out, const Bureaucrat &bureaucrat );