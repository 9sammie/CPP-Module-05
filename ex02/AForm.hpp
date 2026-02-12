/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:16:53 by maballet          #+#    #+#             */
/*   Updated: 2026/02/12 21:52:08 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define STD			"\033[0m"
#define BLUE		"\033[38;5;44m\033[48;5;159m"
#define GREEN		"\033[38;5;34m\033[48;5;193m"
#define PINK		"\033[38;5;199m\033[48;5;225m"
#define YELLOW		"\033[38;5;208m\033[48;5;229m"
#define GREYBGBOLD	"\033[48;5;237m\033[1m"

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {

	private:

	const std::string			_name;
	const std::string			_target;
	bool						_signed;
	const int					_signGrade;
	const int					_execGrade;
	
	protected:

	virtual void executeAction() const = 0;
	
	public:

	AForm();
	AForm (std::string name, std::string target, int sGrade, int eGrade);
	AForm(const AForm&);
	virtual ~AForm();
	std::string	getName() const;
	std::string	getTarget() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	virtual void		beSigned(const Bureaucrat& b);
	virtual void		execute(Bureaucrat const & executor) const;

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
	
	class NotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "AForm not signed ";
			}
	};
};

inline std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << YELLOW << "AForm " << f.getName() << ": [signed: " << f.getSigned()
	<< ", sign grade: " << f.getSignGrade() << ", exec grade: "
	<< f.getExecGrade() << "] " << STD;
	return os;
}

#endif