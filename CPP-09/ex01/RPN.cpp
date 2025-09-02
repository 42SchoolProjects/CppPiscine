#include "RPN.hpp"

const char *RPN::StackTooSmall::what() const throw()
{
	return ("Error: stack contains too few values");
}

const char *RPN::InvalidInput::what() const throw()
{
	return ("Error: invalid expression input");
}

const char *RPN::DivideByZero::what() const throw()
{
	return ("Error: trying to divide by 0");
}

void RPN::Multiply()
{
	if (Stack.size() < 2)
	{
		throw StackTooSmall();
	}

	int a = Stack.top();
	Stack.pop();

	int b = Stack.top();
	Stack.pop();

	Stack.push(a * b);
}

void RPN::Sub()
{
	if (Stack.size() < 2)
	{
		throw StackTooSmall();
	}

	int a = Stack.top();
	Stack.pop();

	int b = Stack.top();
	Stack.pop();

	Stack.push(b - a);
}

void RPN::Add()
{
	if (Stack.size() < 2)
	{
		throw StackTooSmall();
	}

	int a = Stack.top();
	Stack.pop();

	int b = Stack.top();
	Stack.pop();

	Stack.push(a + b);
}

void RPN::Divide()
{
	if (Stack.size() < 2)
	{
		throw StackTooSmall();
	}

	int a = Stack.top();
	Stack.pop();

	if (a == 0)
	{
		throw DivideByZero();
	}

	int b = Stack.top();
	Stack.pop();

	Stack.push(b / a);
}


RPN::RPN(const std::string &Expression)
{
	try
	{
		if (Expression.empty())
		{
			throw InvalidInput();
		}

		std::istringstream iss(Expression);
		std::string token;

		while (iss >> token)
		{
			if (token.length() == 1 && std::isdigit(token[0]))
			{
				Stack.push(std::atoi(token.c_str()));
			}
			else if (token == "+")
			{
				Add();
			}
			else if (token == "-")
			{
				Sub();
			}
			else if (token == "*")
			{
				Multiply();
			}
			else if (token == "/")
			{
				Divide();
			}
			else
			{
				throw InvalidInput();
			}
		}
		if (Stack.empty())
		{
			std::cout << "No result to display." << std::endl;
			return;
		}
		std::cout << Stack.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RPN::~RPN()
{
	while (!Stack.empty())
	{
		Stack.pop();
	}
}

RPN::RPN(const RPN &Other)
{
	Stack = Other.Stack;
}

RPN &RPN::operator=(const RPN &Other)
{
	if (this != &Other)
	{
		Stack = Other.Stack;
	}
	return (*this);
}
