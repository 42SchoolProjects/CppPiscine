#pragma once

#include "Bureaucrat.h"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		// Constructor(s)
		Form();
		Form(const Form &copy);
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		// Destructor(s)
		~Form();
		// Overload Operator(s)
		Form &operator=(const Form &assign);
		// Getter(s)
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		// Class Function(s)
		void		beSigned(Bureaucrat &Bureaucrat);
	// Exception(s)
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &Form);
