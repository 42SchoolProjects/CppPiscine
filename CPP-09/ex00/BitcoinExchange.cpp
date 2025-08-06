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

		size_t CommaPos = Line.find(",");
		if (CommaPos == std::string::npos)
		{
			continue;
		}

		std::string Date = Line.substr(0, CommaPos);
		std::string ValueString = Line.substr(CommaPos + 1); // " | "

		std::stringstream Converter(ValueString);

		float Value;
		if (!(Converter >> Value))
		{
			std::cerr << "Error: invalid value => " << ValueString << std::endl;
			continue;
		}

		Data[Date] = Value;
	}
	File.close();
}

static bool IsValidDate(const std::string &Date)
{
    if (Date.length() != 10 || Date[4] != '-' || Date[7] != '-')
	{
        return false;
	}

    int Year, Month, Day;
    std::istringstream IssYear(Date.substr(0, 4));
    std::istringstream IssMonth(Date.substr(5, 2));
    std::istringstream IssDay(Date.substr(8, 2));
    if (!(IssYear >> Year) || !(IssMonth >> Month) || !(IssDay >> Day))
	{
        return false;
	}

    if (Month < 1 || Month > 12)
	{
		return false;
	}

    int DaysInMonth[] = {31, (Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0)) ? 29 : 28,
                         31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (Day < 1 || Day > DaysInMonth[Month - 1])
	{
        return false;
	}

    return true;
}

void BitcoinExchange::ReadAndPrintInput(const std::string &Filename) const
{
    std::ifstream InputFile(Filename.c_str());
    if (!InputFile.is_open())
    {
        std::cerr << "Failed to open " << Filename << " file !" << std::endl;
        std::exit(1);
    }

    std::string Line;
    bool IsFirstLine = true;

    while (std::getline(InputFile, Line))
    {
		if (Line.empty())
		{
			continue;
		}

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
		if (!IsValidDate(Date))
		{
			std::cerr << "Error: invalid date => " << Date << std::endl;
			continue;
		}

		std::string ValueString = Line.substr(PipePos + 3); // " | "
		std::stringstream Converter(ValueString);

		float Value;
		if (!(Converter >> Value))
		{
			std::cerr << "Error: invalid value => " << ValueString << std::endl;
			continue;
		}

		if (Value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (Value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

        std::map<std::string, float>::const_iterator it = Data.find(Date);
        if (it != Data.end())
        {
            std::cout << Date << " => " << Value << " = " << (it->second * Value) << std::endl;
        }
        else
        {
			// Find previous date
            std::map<std::string, float>::const_iterator lb = Data.lower_bound(Date);
            if (lb != Data.begin())
            {
                --lb;
                std::cout << Date << " => " << Value << " = " << (lb->second * Value) << std::endl;
            }
            else
            {
                std::cout << Date << " => " << "No previous date available" << std::endl;
            }
        }
    }
    InputFile.close();
}
