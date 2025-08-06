#pragma once

#include <iostream>
#include <cstdlib>
#include <stack>

class RPN
{
	private:
		std::stack<int> Stack;

		// RPN(const RPN &Other);
		// RPN &operator=(const RPN &Other);
	public:
		RPN(const std::string &Expression);
		~RPN();

		void Multiply();
		void Sub();
		void Add();
		void Divide();

		class DivideByZero : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidInput : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
