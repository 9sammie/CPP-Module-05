/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:40:46 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 08:38:38 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): 
	AForm(other) {}

void PresidentialPardonForm::executeAction() const
{
	std::cout << PINK << getTarget() << " has been pardoned by Zaphod Beeblebrox the great! " << STD << std::endl;
}
