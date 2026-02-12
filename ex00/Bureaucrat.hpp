/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:24:16 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 18:13:47 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#define STD			"\033[0m"
#define BLUE		"\033[38;5;44m\033[48;5;159m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define PINK		"\033[38;5;199m\033[48;5;225m"
#define YELLOW		"\033[38;5;208m\033[48;5;229m"
#define GREYBGBOLD	"\033[48;5;237m\033[1m"

#include <iostream>

#define STD			"\033[0m"
#define GREYBG		"\033[48;5;237m"

class Bureaucrat
{
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
	os << b.getName() << ": grade " << b.getGrade();
	return os;
}

#endif