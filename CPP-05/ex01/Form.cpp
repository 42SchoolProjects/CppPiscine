#include "Form.hpp"

// Constructor(s)
Form::Form() : name("Default Form"), gradeToSign(50), gradeToExec(75)
{
	isSigned = false;
	std::cout << "Form -> Default constructor has been called" << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	isSigned = false;
	std::cout << "Form -> Copy constructor has been called" << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (gradeToSign < 1 || gradeToExec < 1)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
	isSigned = false;
	std::cout << "Form -> Grades and Name constructor has been called" << std::endl;
}

// Destructor(s)
Form::~Form()
{
	std::cout << "Form -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
Form &Form::operator=(const Form &assign)
{
	this->isSigned = assign.isSigned;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &Form)
{
	out << "Name -> " << Form.getName() << '\n'
		<< "isSigned -> " << Form.getIsSigned() << '\n'
		<< "gradeToSign -> " << Form.getGradeToSign() << '\n'
		<< "gradeToExec -> " << Form.getGradeToExec();
	return (out);
}

// Getter(s)
std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

// Class Function(s)
void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->gradeToSign)
	{
		this->isSigned = true;
	}
	else
	{
		throw(Form::GradeTooLowException());
	}
}

// Exception(s)
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form -> GradeTooHighException, grade is too high to sign");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form -> GradeTooLowException, grade is too low to sign");
}
