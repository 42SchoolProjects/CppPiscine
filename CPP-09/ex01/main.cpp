#include "RPN.hpp"

int main(int ac, char **av)
{
	(void) av;
	if (ac != 2)
	{
		std::cerr << "Format -> <expression>" << std::endl;
		std::exit(1);
	}
	RPN ReversePolishNotation(av[1]);
}
