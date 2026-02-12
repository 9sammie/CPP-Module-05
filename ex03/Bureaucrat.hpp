/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:24:16 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 19:15:18 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include "AForm.hpp"

#define STD			"\033[0m"
#define GREYBG		"\033[48;5;237m"

class AForm;

class Bureaucrat {

	private:

	const std::string	_name;
	int					_grade;
	
	public:

	Bureaucrat();
	Bureaucrat (std::string name, int grade);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator = (const Bureaucrat&);
	~Bureaucrat();
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(AForm& f);
	void		executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "grade too high";
			}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "grade too low";
		}
	};
};

inline std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << YELLOW << b.getName() << ": grade " << b.getGrade() << " " << STD;
	return os;
}

#endif