/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:45:34 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 14:42:04 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	private:

	AForm *createShrubbery(std::string target);
	AForm *createRobotomy(std::string target);
	AForm *createPresidential(std::string target);
	
	public:

	Intern();
	Intern(const Intern&);
	Intern& operator = (const Intern&);
	~Intern();

	AForm *makeForm(std::string name, std::string target);
};

#endif