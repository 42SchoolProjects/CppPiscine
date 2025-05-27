#include "AForm.hpp"

// Constructor(s)
AForm::AForm() : name("Default AForm"), gradeToSign(50), gradeToExec(75)
{
	isSigned = false;
	std::cout << "AForm -> Default constructor has been called" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	isSigned = false;
	std::cout << "AForm -> Copy constructor has been called" << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
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
	std::cout << "AForm -> Grades and Name constructor has been called" << std::endl;
}

// Destructor(s)
AForm::~AForm()
{
	std::cout << "AForm -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
AForm &AForm::operator=(const AForm &assign)
{
	this->isSigned = assign.isSigned;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	out << "Name -> " << AForm.getName() << '\n'
		<< "isSigned -> " << AForm.getIsSigned() << '\n'
		<< "gradeToSign -> " << AForm.getGradeToSign() << '\n'
		<< "gradeToExec -> " << AForm.getGradeToExec();
	return (out);
}

// Getter(s)
std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->gradeToExec);
}

// Class Function(s)
void AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->gradeToSign)
	{
		this->isSigned = true;
	}
	else
	{
		throw(AForm::GradeTooLowException());
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
	{
		throw(AForm::FormNotSignedException());
	}
	else if (executor.getGrade() <= this->gradeToExec)
	{
		this->executeContract();
	}
	else
	{
		throw(AForm::GradeTooLowException());
	}
}

// Exception(s)
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm -> GradeTooHighException, grade is too high to sign/execute");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm -> GradeTooLowException, grade is too low to sign/execute");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm -> FormNotSignedException, contract must be signed before executed");
}
