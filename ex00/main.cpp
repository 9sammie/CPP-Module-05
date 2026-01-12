/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:12:13 by maballet          #+#    #+#             */
/*   Updated: 2026/01/12 21:14:14 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << GREYBG <<  "=== Valide ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat a("Gustave", 42);
		std::cout << a.getname() << ": grade " << a.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== Grade trop haut (0) ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat b("Maelle", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== Grade trop bas (151) ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat c("Aline", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== Incrémenter depuis 1 ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat d("Verso", 1);
		std::cout << d.getname() << ": grade " << d.getGrade() << std::endl;
		d.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== Décrémenter depuis 150 ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat e("Esquie", 150);
		std::cout << e.getname() << ": grade " << e.getGrade() << std::endl;
		e.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl << GREYBG << "=== Copie et affectation ===" << STD << std::endl << std::endl;
	try
	{
		Bureaucrat f("Sciel", 10);
		Bureaucrat g(f);
		Bureaucrat h("Lune", 50);

		std::cout << h.getname() << ": grade " << h.getGrade() << std::endl;
		h = f;
		std::cout << g.getname() << ": grade " << g.getGrade() << std::endl;
		std::cout << h.getname() << ": grade " << h.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
