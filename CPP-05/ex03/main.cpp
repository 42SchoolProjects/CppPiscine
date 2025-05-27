#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

// SHRUBBERY
int main()
{
	Bureaucrat albillie("albillie", 1);
	Intern miniklar;
	AForm *form;

	std::cout << '\n';
	std::cout << "*****************************" << '\n';
	std::cout << "| CAN'T CREATE INVALID NAME |" << '\n';
	std::cout << "*****************************" << '\n';
	std::cout << '\n';

	form = miniklar.makeForm("eete", "testte");
	if (form)
	{
		albillie.executeForm(*form);
	}
	delete form;

	std::cout << '\n';
	std::cout << "************************" << '\n';
	std::cout << "| CREATE ROBOTOMY FORM |" << '\n';
	std::cout << "************************" << '\n';
	std::cout << '\n';

	form = miniklar.makeForm("Robotomy", "test1");
	if (form)
	{
		albillie.signForm(*form);
		albillie.executeForm(*form);
	}
	delete form;

	std::cout << '\n';
	std::cout << "****************************" << '\n';
	std::cout << "| CREATE PRESIDENTIAL FORM |" << '\n';
	std::cout << "****************************" << '\n';
	std::cout << '\n';

	form = miniklar.makeForm("Presidential", "test1");
	if (form)
	{
		albillie.signForm(*form);
		albillie.executeForm(*form);
	}
	delete form;

	std::cout << '\n';
	std::cout << "*************************" << '\n';
	std::cout << "| CREATE SHRUBBERY FORM |" << '\n';
	std::cout << "*************************" << '\n';
	std::cout << '\n';

	form = miniklar.makeForm("Shrubbery", "test1");
	if (form)
	{
		albillie.signForm(*form);
		albillie.executeForm(*form);
	}
	delete form;

	std::cout << '\n';
	std::cout << "***************" << '\n';
	std::cout << "| DESTRUCTORS |" << '\n';
	std::cout << "***************" << '\n';
	std::cout << '\n';
}
