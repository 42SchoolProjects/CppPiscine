#include "RPN.hpp"

const char *RPN::InvalidInput::what() const throw()
{
	return ("Error: invalid expression input");
}

const char *RPN::DivideByZero::what() const throw()
{
	return ("Error: trying to divide by 0");
}

RPN::RPN(const std::string &Expression)
{
	try
	{
		if (Expression.empty())
		{
			throw InvalidInput();
		}

		





	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RPN::~RPN()
{

}
