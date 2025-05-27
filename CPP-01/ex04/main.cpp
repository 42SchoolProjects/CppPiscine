/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 07:48:46 by albillie          #+#    #+#             */
/*   Updated: 2025/02/01 12:12:11 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>

#define ARGS_ERROR 1
#define IN_ERROR 2
#define OUT_ERROR 3

int	PrintError(int code)
{
	if (code == ARGS_ERROR)
	{
		std::cerr << "Invalid args -> ./replace <filename> <string1> <string2>" << std::endl;
	}
	else if (code == IN_ERROR)
	{
		std::cerr << "Error -> Failed to open infile" << std::endl;
	}
	else if (code == OUT_ERROR)
	{
		std::cerr << "Error -> Failed to open outfile" << std::endl;
	}
	return (code);
}

std::string	ReplaceOperation(std::string buffer, std::string s1, std::string s2)
{
	size_t Position = 0;
	size_t Previous = 0;

	std::string ReturnValue;
	while ((Position = buffer.find(s1, Previous)) != std::string::npos)
	{
		ReturnValue += buffer.substr(Previous, Position - Previous);
		ReturnValue += s2;
		Previous = Position + s1.length();
	}
	ReturnValue += buffer.substr(Previous);
	return (ReturnValue);
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		return (PrintError(ARGS_ERROR));
	}
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		return (PrintError(IN_ERROR));
	}
	std::string ReplaceFileName = std::string(av[1]) + ".replace";
	std::ofstream Replace(ReplaceFileName.c_str());
	if (!Replace.is_open())
	{
		return (PrintError(OUT_ERROR));
	}
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	std::string s1 = av[2];
	std::string s2 = av[3];
	Replace << ReplaceOperation(buffer.str(), s1, s2);

	infile.close();
	Replace.close();
}

