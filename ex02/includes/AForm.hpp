#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string name_;
		bool	signed_;
		const	int gradeToSign_;
		const	int gradeToExecute_;

	public:
		AForm( void );
		AForm( const std::string name, const int gradeToSign, const int gradeToExecute );
		AForm( const AForm &other );
		AForm			&operator=( const AForm &other );
		virtual			~AForm( void );
		
		const std::string	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned( const Bureaucrat &bureaucrat );

		virtual void		execute( Bureaucrat const &executor ) const = 0;

		// class imbriquee :
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	FileNotSignedException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

// on aurais pu utiliser le mot clef "friend" mais c'est interdit...
std::ostream				&operator<<( std::ostream &out, const AForm &AForm );