/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:31:28 by maballet          #+#    #+#             */
/*   Updated: 2026/01/16 15:39:38 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default") {}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
	_name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::incrementGrade() 
{
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm& f)
{
	f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
}
