/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:24:02 by maballet          #+#    #+#             */
/*   Updated: 2026/01/13 00:26:17 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name(NULL), _signed(false),  _signGrade(0), _execGrade(0) {}

Form::Form(std::string name, int signGrade, int execGrade):
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	if (+signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other): 
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),	
	_execGrade(other._execGrade) {}

Form::~Form() {}

std::string Form::getName() const { return(this->_name); }

bool Form::getSigned() const { return(this->_signed); }

int Form::getSignGrade() const { return(this->_signGrade); }

int Form::getExecGrade() const { return(this->_execGrade); }

void Form::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}