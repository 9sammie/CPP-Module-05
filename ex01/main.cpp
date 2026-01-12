/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/01/13 00:39:09 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << GREYBG << "=== VALID BUREAUCRAT ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat a("Aline", 1);
		Bureaucrat b("Maelle", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== INVALID BUREAUCRAT ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat c("Renoir", 151);
		Bureaucrat e("Monoco", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== VALID FORMS ===" << STD << std::endl << std::endl;
	try
	{
		Form f1("Contract", 50, 25);
		Form f2("Secret", 1, 1);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== INVALID FORMS ===" << STD << std::endl << std::endl;
	try
	{
		Form bad("BadForm", 0, 200);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== SUCCESFULL SIGNATURE ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		Form report("Report", 20, 10);

		std::cout << report << std::endl;
		boss.signForm(report);
		std::cout << report << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== FAILED SIGNATURE ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		Form topSecret("TopSecret", 50, 10);

		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== DOUBLE SIGNATURE ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat chief("Chief", 1);
		Form order("Order66", 1, 1);

		chief.signForm(order);
		chief.signForm(order); // déjà signé
		std::cout << order << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
