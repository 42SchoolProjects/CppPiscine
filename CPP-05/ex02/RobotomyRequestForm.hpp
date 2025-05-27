#pragma once

#include "AForm.hpp"

#include <fstream>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructor(s)
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);
		// Destructor(s)
		~RobotomyRequestForm();
		// Overload Operator(s)
		RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);
		// Class Function(s)
		void	executeContract() const;
};
