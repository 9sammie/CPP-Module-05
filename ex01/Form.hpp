/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:16:53 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 19:42:43 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define STD			"\033[0m"
#define BLUE		"\033[38;5;44m\033[48;5;159m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define PINK		"\033[38;5;199m\033[48;5;225m"
#define YELLOW		"\033[38;5;208m\033[48;5;229m"
#define GREYBGBOLD	"\033[48;5;237m\033[1m"

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:

	const std::string			_name;
	bool						_signed;
	const int					_signGrade;
	const int					_execGrade;
	
	public:

	Form();
	Form (std::string name, int sGrade, int eGrade);
	Form(const Form&);
	~Form();
	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void		beSigned(const Bureaucrat& b);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form grade too high";
			}
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Form grade too low";
			}
	};
};

inline std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << ": [signed: " << f.getSigned()
	<< ", sign grade: " << f.getSignGrade() << ", exec grade: "
	<< f.getExecGrade() << "]";
	return os;
}

#endif