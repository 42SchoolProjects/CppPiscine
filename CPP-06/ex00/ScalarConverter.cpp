#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

static void printValues(std::string charValue, std::string intValue, std::string floatValue, std::string doubleValue)
{
	std::cout << "char : " << charValue << std::endl;
	std::cout << "int : " << intValue << std::endl;
	std::cout << "float : " << floatValue << std::endl;
	std::cout << "double : " << doubleValue << std::endl;
}


// Check if not a digit if the value is . or f
// Bool to know if there was already a point, If yes just return false
static bool isLitteral(std::string value)
{
	bool passedOnPoint = false;

	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '.' && value[i] != 'f' && value[i] != '-')
		{
			return (false);
		}
		if (value[i] == '.' && (passedOnPoint == true || !value[i + 1] || !value[i - 1]))
		{
			return (false);
		}
		else if (value[i] == '.' && passedOnPoint == false)
		{
			passedOnPoint = true;
		}
		if (value[i] == 'f' && (value[i + 1] || value.size() == 1))
		{
			return (false);
		}
		if (value[i] == '-' && (i != 0 || !value[i + 1]))
		{
			return (false);
		}
	}
	return (true);
}

void ScalarConverter::convert(std::string value)
{
	if (value == "nan" || value == "nanf")
	{
		printValues("impossible", "impossible", "nanf", "nan");
		return ;
	}
	else if (value == "+inff" || value == "+inf")
	{
		printValues("impossible", "impossible", "+inff", "+inf");
		return ;
	}
	else if (value == "-inff" || value == "-inf")
	{
		printValues("impossible", "impossible", "-inff", "-inf");
		return ;
	}

	if (!isLitteral(value))
	{
		std::cout << "Please enter a valid representation of litteral in C++ !" << std::endl;
		return ;
	}

	char c;
	int i;
	float f;
	double d;

	if (value[value.size() - 1] == 'f')
	{
		f = atof(value.c_str());
		d = static_cast<double> (f);
		i = static_cast<int> (f);
		c = static_cast<char> (f);
	}
	else if (value.find('.') != std::string::npos)
	{
		d = strtod(value.c_str(), NULL);
		f = static_cast<float> (d);
		i = static_cast<int> (d);
		c = static_cast<char> (d);
	}
	else
	{
		i = atoi(value.c_str());
		f = static_cast<float> (i);
		d = static_cast<double> (i);
		c = static_cast<char> (i);
	}

	std::string charValue;
	std::string intValue;
	std::string floatValue;
	std::string doubleValue;
	std::stringstream stringStream;


	if (isprint(c))
	{
		stringStream << '\'' << c << '\'';
		charValue = stringStream.str();
		stringStream.clear();
		stringStream.str("");
	}
	else
	{
		charValue = "Non displayable";
	}

	stringStream << i;
	stringStream >> intValue;
	stringStream.clear();
	stringStream.str("");

	stringStream << f << 'f';
	stringStream >> floatValue;
	stringStream.clear();
	if (floatValue.find('.') == std::string::npos)
	{
		stringStream << f << ".0" << 'f';
	}
	stringStream >> floatValue;
	stringStream.clear();

	stringStream << d;
	stringStream >> doubleValue;
	stringStream.clear();
	if (doubleValue.find('.') == std::string::npos)
	{
		stringStream << f << ".0";
	}
	stringStream >> doubleValue;
	stringStream.clear();

	printValues(charValue, intValue, floatValue, doubleValue);
}
