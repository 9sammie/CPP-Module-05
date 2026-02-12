/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:24:02 by maballet          #+#    #+#             */
/*   Updated: 2026/01/15 18:49:26 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name(NULL), _signed(false),  _signGrade(0), _execGrade(0) {}

AForm::AForm(std::string name, std::string target, int signGrade, int execGrade):
	_name(name), _target(target), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other): 
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),	
	_execGrade(other._execGrade) {}

AForm::~AForm() {}

std::string AForm::getName() const { return(this->_name); }

std::string AForm::getTarget() const { return(this->_target); }

bool AForm::getSigned() const { return(this->_signed); }

int AForm::getSignGrade() const { return(this->_signGrade); }

int AForm::getExecGrade() const { return(this->_execGrade); }

void AForm::beSigned(const Bureaucrat& b) 
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (_signed == 0)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	executeAction();
}