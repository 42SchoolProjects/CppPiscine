#include "RobotomyRequestForm.hpp"

// Constructor(s)
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Contract", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm -> Default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), target(copy.target)
{
	std::cout << "RobotomyRequestForm -> Copy constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm -> Target constructor has been called" << std::endl;
}

// Destructor(s)
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->target = assign.target;
	return (*this);
}

// Class Function(s)
void RobotomyRequestForm::executeContract() const
{
	std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
}
