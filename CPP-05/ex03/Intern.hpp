#pragma once

#include "AForm.hpp"

class Intern
{
	public:
		// Constructor(s)
		Intern();
		Intern(const Intern &copy);
		// Destructor(s)
		~Intern();
		// Overload Operator(s)
		Intern &operator=(const Intern &assign);
		// Class Functions
		AForm *makeForm(std::string formName, std::string formTarget);
};
