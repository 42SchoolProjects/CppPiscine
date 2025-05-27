#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base have been destroyed !" << std::endl;
}

Base *generate(void)
{
	srand(time(0));
	int random = (rand() % 3) + 1;

	if (random == 1)
	{
		return (new A);
	}
	else if (random == 2)
	{
		return (new B);
	}
	else
	{
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *> (p))
	{
		std::cout << "A class is pointed by p" << std::endl;
	}
	else if (dynamic_cast<B *> (p))
	{
		std::cout << "B class is pointed by p" << std::endl;
	}
	else if (dynamic_cast<C *> (p))
	{
		std::cout << "C class is pointed by p" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A &> (p);
		std::cout << "A class is referenced by p" << std::endl;
	}
	catch(const std::exception& e)
	{
		// Used to avoid std::bad_cast message, it's more clean !
	}
	try
	{
		(void) dynamic_cast<B &> (p);
		std::cout << "B class is referenced by p" << std::endl;
	}
	catch(const std::exception& e)
	{
		// Used to avoid std::bad_cast message, it's more clean !
	}
	try
	{
		(void) dynamic_cast<C &> (p);
		std::cout << "C class is referenced by p" << std::endl;
	}
	catch(const std::exception& e)
	{
		// Used to avoid std::bad_cast message, it's more clean !
	}
}
