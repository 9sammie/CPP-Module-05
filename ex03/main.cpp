/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 15:59:21 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

void tryExecute(Bureaucrat& b, AForm& f)
{
	try
	{
		b.executeForm(f);
		std::cout << GREEN << b.getName() << " executed " << f.getName() << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << b.getName() << " couldn't execute " << f.getName()
				<< " because " << e.what() << " (ó﹏ò｡)" << STD << std::endl;
	}
}

void trySign(Bureaucrat& b, AForm& f)
{
	try
	{
		b.signForm(f);
		std::cout << YELLOW << b.getName() << " signed " << f.getName() << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << b.getName() << " couldn't sign " << f.getName()
				<< " because " << e.what() << " (ó﹏ò｡)" << STD << std::endl;
	}
}

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

	tryExecute(boss, shrub);
	tryExecute(boss, robot);
	tryExecute(boss, pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== SIGN FORMS WITH INSUFFICIENT GRADE ===" << STD << std::endl << std::endl;

	trySign(intern, shrub);
	trySign(intern, robot);
	trySign(intern, pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== SIGN FORMS WITH PROPER GRADES ===" << STD << std::endl << std::endl;

	trySign(manager, shrub);
	trySign(manager, robot);
	trySign(boss, pardon);

	std::cout << std::endl << std::endl << GREYBG << "=== EXECUTE WITH INSUFFICIENT GRADE ===" << STD << std::endl << std::endl;

	tryExecute(manager, pardon);
	tryExecute(intern, shrub);
	tryExecute(intern, robot);
	
	std::cout << std::endl << std::endl << GREYBG << "=== EXECUTE WITH PROPER GRADES ===" << STD << std::endl << std::endl;

	tryExecute(boss, shrub);
	tryExecute(boss, robot);
	tryExecute(boss, pardon);
	
	std::cout << std::endl << std::endl << GREYBG << "=== MULTIPLE ROBOTOMY TESTS ===" << STD << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
	{
		tryExecute(boss, robot);
		std::cout << std::endl;
	}

	std::cout << std::endl << GREYBG << "=== INTERN CREATES FORMS ===" << STD << std::endl << std::endl;

	Intern someRandomIntern;
	AForm* f1;
	AForm* f2;
	AForm* f3;
	AForm* f4;

	f1 = someRandomIntern.makeForm("shrubbery creation", "garden");
	f2 = someRandomIntern.makeForm("robotomy request", "Marvin");
	f3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	f4 = someRandomIntern.makeForm("coffee request", "42");

	std::cout << std::endl << GREYBG << "=== SIGN & EXECUTE INTERN FORMS ===" << STD << std::endl << std::endl;

	if (f1)
	{
		trySign(boss, *f1);
		tryExecute(boss, *f1);
		std::cout << std::endl;
		delete f1;
	}
	if (f2)
	{
		trySign(boss, *f2);
		tryExecute(boss, *f2);
		std::cout << std::endl;
		delete f2;
	}
	if (f3)
	{
		trySign(boss, *f3);
		tryExecute(boss, *f3);
		std::cout << std::endl;
		delete f3;
	}
	if (f4)
		delete f4;

	return 0;
}
