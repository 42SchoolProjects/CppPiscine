#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Constructor(s)
Intern::Intern()
{
	std::cout << "Intern -> Default constructor has been called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "Intern -> Copy constructor has been called" << std::endl;
}

// Destructor(s)
Intern::~Intern()
{
	std::cout << "Intern -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
Intern &Intern::operator=(const Intern &assign)
{
	(void) assign;
	return (*this);
}

// Class Function(s)
AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[3] = {"Shrubbery", "Robotomy", "Presidential"};

	int i;
	for (i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			break;
		}
	}
	if (i == 3)
	{
		std::cout << "Intern couldn't create -> " << formName << std::endl;
		return (NULL);
	}
	switch (i)
	{
		case 0:
		{
			std::cout << "Intern create " << "ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		case 1:
		{
			std::cout << "Intern create " << "RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:
		{
			std::cout << "Intern create " << "PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		default:
		{
			return (NULL);
		}
	}
}
