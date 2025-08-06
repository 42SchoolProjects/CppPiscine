#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> Data;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &Other);
		BitcoinExchange &operator=(const BitcoinExchange &Other);
	public:
		BitcoinExchange(const std::string &Filename);
		void ReadAndPrintInput(const std::string &Filename) const;
};
