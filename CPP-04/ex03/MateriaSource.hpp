/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:48:47 by kave0             #+#    #+#             */
/*   Updated: 2025/02/18 04:58:34 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *blueprint[4];
	public:
		// Constructor(s)
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		// Destructor(s)
		~MateriaSource();
		// Overload Operator(s)
		MateriaSource &operator=(const MateriaSource &assign);
		// MateriaSource Functions
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};
