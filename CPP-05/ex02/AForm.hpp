#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		// Constructor(s)
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		// Destructor(s)
		~AForm();
		// Overload Operator(s)
		AForm &operator=(const AForm &assign);
		// Getter(s)
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		// Class Function(s)
		void		beSigned(Bureaucrat &Bureaucrat);
		void		execute(Bureaucrat const &executor) const;
		virtual void executeContract() const = 0;
	// Exception(s)
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
