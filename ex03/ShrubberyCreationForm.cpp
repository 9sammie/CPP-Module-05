/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:31:51 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 09:32:29 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreation", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): 
	AForm(other) {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile ((getTarget() + "_shrubbery").c_str());
	outfile
        << "               ,@@@@@@@,\n"
        << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
        << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
        << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
        << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
        << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
        << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
        << "       |o|        | |         | |\n"
        << "       |.|        | |         | |\n"
        << "    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
        << std::endl;
	outfile.close();
}
