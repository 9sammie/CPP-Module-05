/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 16:22:24 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void tryCreateBureaucrat(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << GREEN << b << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Error: " << e.what() << STD << std::endl;
	}
}

void tryIncrement(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << GREEN << b << STD << std::endl;
		b.incrementGrade();
		std::cout << GREEN << "After increment: " << b << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Error: " << e.what() << STD << std::endl;
	}
}

void tryDecrement(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << GREEN << b << STD << std::endl;
		b.decrementGrade();
		std::cout << GREEN << "After decrement: " << b << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Error: " << e.what() << STD << std::endl;
	}
}

void tryCopyAssign()
{
	try
	{
		Bureaucrat original("Sciel", 10);
		Bureaucrat copy(original);
		Bureaucrat assigned("Lune", 50);

		std::cout << BLUE << "Before assignment: " << assigned << STD << std::endl;
		assigned = original;

		std::cout << GREEN << "Copy: " << copy << STD << std::endl;
		std::cout << BLUE << "Assigned: " << assigned << STD << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << PINK << "Error: " << e.what() << STD << std::endl;
	}
}

int main()
{
	std::cout << GREYBG << "=== Valide ===" << STD << "\n\n";
	tryCreateBureaucrat("Gustave", 42);

	std::cout << "\n\n" << GREYBG << "=== Grade trop haut (0) ===" << STD << "\n\n";
	tryCreateBureaucrat("Maelle", 0);

	std::cout << "\n\n" << GREYBG << "=== Grade trop bas (151) ===" << STD << "\n\n";
	tryCreateBureaucrat("Aline", 151);

	std::cout << "\n\n" << GREYBG << "=== Incrémenter depuis 1 ===" << STD << "\n\n";
	tryIncrement("Verso", 1);

	std::cout << "\n\n" << GREYBG << "=== Décrémenter depuis 150 ===" << STD << "\n\n";
	tryDecrement("Esquie", 150);

	std::cout << "\n\n" << GREYBG << "=== Copie et affectation ===" << STD << "\n\n";
	tryCopyAssign();

	return 0;
}
