#include "Bureaucrat.hpp"

// Constructor(s)
Bureaucrat::Bureaucrat() : name("kaveO"), grade(150)
{
	std::cout << "Bureaucrat -> Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat -> Copy constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
	{
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (grade < 1)
	{
		throw(Bureaucrat::GradeTooHighException());
	}
	std::cout << "Bureaucrat -> Grade and Name constructor has been called" << std::endl;
}

// Destructor(s)
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat -> Destructor has been called" << std::endl;
}

// Getter(s)
std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

// Class Function(s)
void Bureaucrat::promote()
{
	if ((this->grade - 1) < 1)
	{
		return (throw(Bureaucrat::GradeTooHighException()));
	}
	grade--;
}

void Bureaucrat::demote()
{
	if ((this->grade + 1) > 150)
	{
		return (throw(Bureaucrat::GradeTooLowException()));
	}
	this->grade++;
}

void Bureaucrat::signForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->name << " signed " << AForm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t sign " << AForm.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Overload Operator(s)
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->grade = assign.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (out);
}

// Exception(s)
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat -> GradeTooHighException, max grade is 1 !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat -> GradeTooLowException, min grade is 150 !");
}
