#pragma once

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructor(s)
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(std::string target);
		// Destructor(s)
		~ShrubberyCreationForm();
		// Overload Operator(s)
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);
		// Class Function(s)
		void	executeContract() const;
};
