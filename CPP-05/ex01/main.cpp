#include "Bureaucrat.h"

int main()
{
	Bureaucrat	MiniKlar("Loris", 140);
	Bureaucrat	kaveO("Alban", 1);
	Bureaucrat	Kai("Alois", 139);
	Form		ZywooContract("ZywooContract", 139, 14);

	std::cout << '\n';
	std::cout << ZywooContract << std::endl;

	std::cout << '\n';
	std::cout << "**********************************" << '\n';
	std::cout << "| CAN'T SIGN CAUSE GRADE TOO LOW |" << '\n';
	std::cout << "**********************************" << '\n';
	std::cout << '\n';

	MiniKlar.signForm(ZywooContract);

	std::cout << '\n';
	std::cout << "*********************************" << '\n';
	std::cout << "| CAN SIGN CAUSE GRADE IS EQUAL |" << '\n';
	std::cout << "*********************************" << '\n';
	std::cout << '\n';

	Kai.signForm(ZywooContract);

	std::cout << '\n';
	std::cout << "**********************************" << '\n';
	std::cout << "| CAN SIGN CAUSE GRADE IS BIGGER |" << '\n';
	std::cout << "**********************************" << '\n';
	std::cout << '\n';

	kaveO.signForm(ZywooContract);

	std::cout << '\n';
	std::cout << "***************" << '\n';
	std::cout << "| DESTRUCTORS |" << '\n';
	std::cout << "***************" << '\n';
	std::cout << '\n';
}
