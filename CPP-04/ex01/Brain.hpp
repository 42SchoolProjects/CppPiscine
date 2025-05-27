/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:53:05 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 17:57:10 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		// Constructor(s)
		Brain();
		Brain(const Brain &Brain);
		// Destructor(s)
		~Brain();
		// Overload Operator(s)
		Brain &operator=(const Brain &Assign);
		// Getter(s)
		std::string getIdea(int index) const;
};

