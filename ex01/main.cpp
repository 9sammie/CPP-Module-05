/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 18:28:25 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryCreateBureaucrat(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << GREEN << b << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Exception: " << e.what() << STD << std::endl;
	}
}

void tryCreateForm(const std::string& name, int sign, int exec)
{
	try
	{
		Form f(name, sign, exec);
		std::cout << GREEN << f << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Exception: " << e.what() << STD << std::endl;
	}
}

void trySign(Bureaucrat& b, Form& f)
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
	std::cout << GREYBG << "=== VALID BUREAUCRAT ===" << STD << "\n\n";
	
	tryCreateBureaucrat("Aline", 1);
	tryCreateBureaucrat("Maelle", 150);

	std::cout << "\n\n" << GREYBG << "=== INVALID BUREAUCRAT ===" << STD << "\n\n";

	tryCreateBureaucrat("Renoir", 151);
	tryCreateBureaucrat("Monoco", 0);

	std::cout << "\n\n" << GREYBG << "=== VALID FORMS ===" << STD << "\n\n";

	tryCreateForm("Contract", 50, 25);
	tryCreateForm("Secret", 1, 1);

	std::cout << "\n\n" << GREYBG << "=== INVALID FORMS ===" << STD << "\n\n";
	
	tryCreateForm("BadForm", 0, 200);

	std::cout << "\n\n" << GREYBG << "=== SUCCESSFUL SIGNATURE ===" << STD << "\n\n";
	{
		Bureaucrat boss("Boss", 10);
		Form report("Report", 20, 10);

		std::cout << GREEN << report << STD << std::endl;
		boss.signForm(report);
		std::cout << GREEN << report << STD << std::endl;
	}

	std::cout << "\n\n" << GREYBG << "=== FAILED SIGNATURE ===" << STD << "\n\n";
	{
		Bureaucrat intern("Intern", 150);
		Form topSecret("TopSecret", 50, 10);

		std::cout << GREEN << topSecret << STD << std::endl;
		intern.signForm(topSecret);
		std::cout << GREEN << topSecret << STD << std::endl;
	}

	std::cout << "\n\n" << GREYBG << "=== DOUBLE SIGNATURE ===" << STD << "\n\n";
	{
		Bureaucrat chief("Chief", 1);
		Form order("Order66", 1, 1);

		chief.signForm(order);

		std::cout << GREEN << order << STD << std::endl;
	}

	return 0;
}
