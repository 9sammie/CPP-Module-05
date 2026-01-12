/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:24:16 by maballet          #+#    #+#             */
/*   Updated: 2026/01/12 20:44:09 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>

#define STD			"\033[0m"
#define GREYBG		"\033[48;5;237m"

class Bureaucrat {

	private:

	std::string			_name;
	int					_grade;
	
	public:

	Bureaucrat();
	Bureaucrat (std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator = (const Bureaucrat&);
	~Bureaucrat();
	std::string	getname() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

};

class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade too high";
		}
};

class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade too low";
		}
};

#endif