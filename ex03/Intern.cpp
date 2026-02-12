/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:45:31 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 17:31:16 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator = (const Intern&) { return *this; }

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	if (name.empty() || target.empty())
		return (NULL);
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
    AForm* (Intern::*creators[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };
	for (int i =0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << GREEN << "Intern creates " << name << STD << std::endl;
            return (this->*creators[i])(target);
		}
	}
	std::cout << PINK << "Intern couldn't find form named \"" << name << "\"" << STD << std::endl;
	return (NULL);
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

