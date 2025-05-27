#include "iter.hpp"

void print(char &c)
{
	std::cout << c << " ";
}

void lowerCase(char &c)
{
	c += 32;
}

void print(int &c)
{
	std::cout << c << " ";
}

void plusTen(int &c)
{
	c += 10;
}

int main()
{
	char array[5];
	array[0] = 'K';
	array[1] = 'A';
	array[2] = 'V';
	array[3] = 'E';
	array[4] = 'O';


	std::cout << "************************" << std::endl;
	std::cout << "| TEST WITH CHAR ARRAY |" << std::endl;
	std::cout << "************************" << std::endl << std::endl;

	iter(array, 5, print);
	std::cout << std::endl;
	iter(array, 5, lowerCase);
	iter(array, 5, print);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "***********************" << std::endl;
	std::cout << "| TEST WITH INT ARRAY |" << std::endl;
	std::cout << "***********************" << std::endl;

	int array1[5] = {1, 2, 3, 4, 5};

	std::cout << std::endl;
	iter(array1, 5, print);
	iter(array1, 5, plusTen);
	std::cout << std::endl;
	iter(array1, 5, print);
	std::cout << std::endl;

	return (0);
}
