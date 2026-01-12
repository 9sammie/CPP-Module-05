/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:16:53 by maballet          #+#    #+#             */
/*   Updated: 2026/01/13 00:24:10 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

	const std::string			_name;
	bool						_signed;
	const int					_signGrade;
	const int					_execGrade;
	
	public:

	Form();
	Form (std::string name, int sGrade, int eGrade);
	Form(const Form&);
	Form& operator = (const Form&);
	~Form();
	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void		beSigned(const Bureaucrat& b);

};

class FormGradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade too high";
		}
};

class FormGradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form grade too low";
		}
};

inline std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() << ": [signed: " << f.getSigned()
	<< ", sign grade: " << f.getSignGrade() << ", exec grade: "
	<< f.getExecGrade() << "]";
	return os;
}

#endif