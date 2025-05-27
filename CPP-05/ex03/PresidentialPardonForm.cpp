#include "PresidentialPardonForm.hpp"

// Constructor(s)
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Contract", 25, 5), target("default")
{
	std::cout << "PresidentialPardonForm -> Default constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target)
{
	std::cout << "PresidentialPardonForm -> Copy constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm -> Target constructor has been called" << std::endl;
}

// Destructor(s)
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	this->target = assign.target;
	return (*this);
}

// Class Function(s)
void PresidentialPardonForm::executeContract() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
