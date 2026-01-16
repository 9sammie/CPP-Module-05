/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:11:36 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 09:32:41 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequest", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): 
	AForm(other) {}

void RobotomyRequestForm::executeAction() const
{
	std::cout << BLUE << "* OH GOD NO PLEASE NOOOESAFDGDKGEROGGWFZPZONONZZBZZZZZZZZZZZZ * " << STD << std::endl;
	int fiftyFifty = rand() % 2;
	if (fiftyFifty == 0)
		std::cout << GREEN << getTarget() << " has been robotomized successfully (˶ᵔ ᵕ ᵔ˶) " << STD << std::endl;
	else
		std::cout << PINK << "the robotomisation of " << getTarget() << " have sadly failed (╥ ‸╥) " << STD << std::endl;
}
