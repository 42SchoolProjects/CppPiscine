#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// SHRUBBERY
int main()
{
	Bureaucrat albillie("albillie", 138);
	ShrubberyCreationForm Shrubbery; // 145 to SIGN && 137 to EXEC

	std::cout << '\n';
	std::cout << "**********************************" << std::endl;
	std::cout << "| MUST BE SIGNED BEFORE EXECUTED |" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << '\n';

	albillie.executeForm(Shrubbery);

	std::cout << '\n';
	std::cout << "*****************************" << std::endl;
	std::cout << "| GRADE IS TOO LOW FOR EXEC |" << std::endl;
	std::cout << "*****************************" << std::endl;
	std::cout << '\n';

	albillie.signForm(Shrubbery);
	albillie.executeForm(Shrubbery);

	std::cout << '\n';
	std::cout << "************************" << std::endl;
	std::cout << "| CAN SIGN AND EXECUTE |" << std::endl;
	std::cout << "************************" << std::endl;
	std::cout << '\n';

	albillie.promote();
	albillie.signForm(Shrubbery);
	albillie.executeForm(Shrubbery);

	std::cout << '\n';
	std::cout << "***************" << std::endl;
	std::cout << "| DESTRUCTORS |" << std::endl;
	std::cout << "***************" << std::endl;
	std::cout << '\n';
}

// ROBOTOMY
// int main()
// {
// 	Bureaucrat albillie("albillie", 46);
// 	RobotomyRequestForm Robotomy; // 72 to SIGN && 45 to EXEC

// 	std::cout << '\n';
// 	std::cout << "**********************************" << std::endl;
// 	std::cout << "| MUST BE SIGNED BEFORE EXECUTED |" << std::endl;
// 	std::cout << "**********************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.executeForm(Robotomy);

// 	std::cout << '\n';
// 	std::cout << "*****************************" << std::endl;
// 	std::cout << "| GRADE IS TOO LOW FOR EXEC |" << std::endl;
// 	std::cout << "*****************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.signForm(Robotomy);
// 	albillie.executeForm(Robotomy);

// 	std::cout << '\n';
// 	std::cout << "************************" << std::endl;
// 	std::cout << "| CAN SIGN AND EXECUTE |" << std::endl;
// 	std::cout << "************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.promote();
// 	albillie.signForm(Robotomy);
// 	albillie.executeForm(Robotomy);

// 	std::cout << '\n';
// 	std::cout << "***************" << std::endl;
// 	std::cout << "| DESTRUCTORS |" << std::endl;
// 	std::cout << "***************" << std::endl;
// 	std::cout << '\n';

// }

// PRESIDENTIAL
// int main()
// {
// 	Bureaucrat albillie("albillie", 26);
// 	PresidentialPardonForm Presidential; // 25 to SIGN && 5 to EXEC

// 	std::cout << '\n';
// 	std::cout << "**********************************" << std::endl;
// 	std::cout << "| MUST BE SIGNED BEFORE EXECUTED |" << std::endl;
// 	std::cout << "**********************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.executeForm(Presidential);

// 	std::cout << '\n';
// 	std::cout << "*****************************" << std::endl;
// 	std::cout << "| GRADE IS TOO LOW FOR EXEC |" << std::endl;
// 	std::cout << "*****************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.signForm(Presidential);
// 	albillie.executeForm(Presidential);

// 	std::cout << '\n';
// 	std::cout << "************************" << std::endl;
// 	std::cout << "| CAN SIGN AND EXECUTE |" << std::endl;
// 	std::cout << "************************" << std::endl;
// 	std::cout << '\n';

// 	albillie.promote();
// 	albillie.signForm(Presidential);
// 	albillie.executeForm(Presidential);

// 	std::cout << '\n';
// 	std::cout << "***************" << std::endl;
// 	std::cout << "| DESTRUCTORS |" << std::endl;
// 	std::cout << "***************" << std::endl;
// 	std::cout << '\n';
// }
