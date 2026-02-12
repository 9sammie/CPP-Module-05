/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 22:18:28 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main()
{
	srand(time(NULL));

	std::cout << std::endl << std::endl << GREYBG << "=== CREATING BUREAUCRATS ===" << STD << std::endl << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat intern("Intern", 150);

	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	
	std::cout << std::endl << std::endl << GREYBG << "=== CREATING FORMS ===" << STD << std::endl << std::endl;

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;


	std::cout << std::endl << std::endl << GREYBG << "=== EXECUTE WITHOUT SIGNING ===" << STD << std::endl << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== SIGN FORMS WITH INSUFFICIENT GRADE ===" << STD << std::endl << std::endl;

	intern.signForm(shrub);
	intern.signForm(robot);
	intern.signForm(pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== SIGN FORMS WITH PROPER GRADES ===" << STD << std::endl << std::endl;

	manager.signForm(shrub);
	manager.signForm(robot);
	boss.signForm(pardon);

	std::cout << std::endl << std::endl << GREYBG << "=== EXECUTE WITH INSUFFICIENT GRADE ===" << STD << std::endl << std::endl;

	manager.executeForm(pardon);
	intern.executeForm(shrub);
	intern.executeForm(robot);
	
	std::cout << std::endl << std::endl << GREYBG << "=== EXECUTE WITH PROPER GRADES ===" << STD << std::endl << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== MULTIPLE ROBOTOMY TESTS ===" << STD << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		boss.executeForm(robot);
		std::cout << std::endl;
	}
	return 0;
}
