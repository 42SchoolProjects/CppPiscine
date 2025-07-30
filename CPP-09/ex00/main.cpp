#include <iostream>
#include "BitcoinExchange.hpp"

int  main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Format -> <data_file>" << std::endl;
		std::exit(1);
	}

	BitcoinExchange Bitcoin(av[1]);
}
