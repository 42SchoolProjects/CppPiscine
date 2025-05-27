#include "ShrubberyCreationForm.hpp"

// Constructor(s)
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Contract", 145, 137), target("default")
{
	std::cout << "ShrubberyCreationForm -> Default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target)
{
	std::cout << "ShrubberyCreationForm -> Copy constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm -> Target constructor has been called" << std::endl;
}

// Destructor(s)
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	this->target = assign.target;
	return (*this);
}

// Class Function(s)
void ShrubberyCreationForm::executeContract() const
{
	std::ofstream file((this->target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	if (file.is_open())
	{
		file    << "     ccee88oo"               << std::endl
				<< "  C8O8O8Q8PoOb o8oo"        << std::endl
				<< " dOB69QO8PdUOpugoO9bD"      << std::endl
				<< "CgggbU8OU qOp qOdoUOdcb"    << std::endl
				<< "    6OuU  /p u gcoUodpP"    << std::endl
				<< "      //  /douUP"           << std::endl
				<< "        /// "               << std::endl
				<< "         |||/ "             << std::endl
				<< "         |||/"              << std::endl
				<< "         |||||"             << std::endl
				<< "   .....//||||\\...."       << std::endl;
	}
	else
	{
		std::cerr << "Error, " << "failed to open -> " << this->target + "_shrubbery" << std::endl;
	}
}
