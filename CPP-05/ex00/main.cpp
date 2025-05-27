#include "Bureaucrat.hpp"

int main (void)
{
	std::cout << '\n';
	std::cout << "*************************" << '\n';
	std::cout << "| TRY WITH CONSTRUCTORS |" << '\n';
	std::cout << "*************************" << '\n';
	std::cout << '\n';

	try
	{
		Bureaucrat test("Michel", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat test("Michel", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat test("Michel", 43);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n';
	std::cout << "**********************" << '\n';
	std::cout << "| TRY WITH MIN LIMIT |" << '\n';
	std::cout << "**********************" << '\n';
	std::cout << '\n';

	Bureaucrat test("Jamie", 150);
	try
	{
		test.demote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n';
	std::cout << "**********************" << '\n';
	std::cout << "| TRY WITH MAX LIMIT |" << '\n';
	std::cout << "**********************" << '\n';
	std::cout << '\n';

	Bureaucrat test1("Claude", 1);
	try
	{
		test1.promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n';
	std::cout << "**********************" << '\n';
	std::cout << "| GO CRAZYYYYYYYYYYY |" << '\n';
	std::cout << "**********************" << '\n';
	std::cout << '\n';

	Bureaucrat albillie("albillie", 43);
	albillie.demote();
	albillie.demote();
	albillie.demote();
	albillie.demote();
	std::cout << albillie << std::endl;

	Bureaucrat albillie1("albillie1", 43);
	albillie1.promote();
	albillie1.promote();
	albillie1.promote();
	albillie1.promote();
	std::cout << albillie1 << std::endl;

	std::cout << '\n';
	std::cout << "***************" << '\n';
	std::cout << "| DESTRUCTORS |" << '\n';
	std::cout << "***************" << '\n';
	std::cout << '\n';
}
