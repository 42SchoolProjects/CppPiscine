#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &Filename)
{
	std::ifstream File(Filename.c_str());
	if (!File.is_open())
	{
			std::cerr << "Failed to open the input File !" << std::endl;
			std::exit(1);
	}

	bool IsFirstLine = true;
	std::string	Line;

	while (std::getline(File, Line))
	{
		if (IsFirstLine)
		{
			IsFirstLine = false;
			continue;
		}

		size_t PipePos = Line.find(" | ");
		if (PipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << Line << std::endl;
			continue;
		}

		std::string Date = Line.substr(0, PipePos);
		std::string ValueString = Line.substr(PipePos + 3); // " | "

		std::stringstream Converter(ValueString);

		float Value;
		if (!(Converter >> Value))
		{
			std::cerr << "Error: invalid value => " << ValueString << std::endl;
			continue;
		}
	}

	File.close();
}
