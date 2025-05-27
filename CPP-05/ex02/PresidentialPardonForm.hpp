#pragma once

#include "AForm.hpp"

#include <fstream>

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructor(s)
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		// Destructor(s)
		~PresidentialPardonForm();
		// Overload Operator(s)
		PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
		// Class Function(s)
		void	executeContract() const;
};
