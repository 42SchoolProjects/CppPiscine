/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:10:55 by albillie          #+#    #+#             */
/*   Updated: 2025/01/31 20:36:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string is     -> " << std::__addressof(string) << std::endl;
	std::cout << "Address of stringPTR is  -> " << std::__addressof(stringPTR) << std::endl;
	std::cout << "Address of stringREF is  -> " << std::__addressof(stringREF) << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string is       -> " << string << std::endl;
	std::cout << "Value of stringPTR is    -> " << *stringPTR << std::endl;
	std::cout << "Value of stringREF is    -> " << stringREF << std::endl;
}
