#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &assign);
	public:
		~ScalarConverter();
		static void convert(std::string value);
};
