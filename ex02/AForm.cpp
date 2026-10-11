/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:52:55 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/11 18:38:43 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: sign_grade(150)
	, exec_grade(150)
	, name("null_form")
	, target("none")
	, is_signed(false)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

AForm::AForm(int _sign_grade, int _exec_grade, std::string _name, std::string _target)
	: sign_grade(_sign_grade)
	, exec_grade(_exec_grade)
	, name(_name)
	, target(_target)
	, is_signed(false)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

AForm::AForm(const AForm& other)
	: sign_grade(other.sign_grade)
	, exec_grade(other.exec_grade)
	, name(other.name)
	, target(other.target)
	, is_signed(other.is_signed)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

AForm& AForm::operator=(const AForm& other){
	(void)other;
	return (*this);
}

AForm::~AForm(){};

const int& AForm::getSignGrade() const{
	return (sign_grade);
}

const int& AForm::getExecGrade() const{
	return (exec_grade);
}

const std::string& AForm::getName() const{
	return (name);
}

const std::string&	AForm::getTarget() const{
	return(target);
}

bool AForm::getIsSigned() const{
	return (is_signed);
}

void	AForm::beSigned(const Bureaucrat& brc){
	if (brc.getGrade() > sign_grade)
		throw AForm::GradeTooLowException(brc.getGrade());
	is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const{
	this->canExecute(executor);
	this->beExecuted();
}

void	AForm::canSign(const Bureaucrat&brc){
	if (brc.getGrade() > sign_grade)
		throw AForm::GradeTooLowException(brc.getGrade());
}

void	AForm::canExecute(const Bureaucrat& brc) const{
	if (brc.getGrade() > exec_grade)
		throw AForm::GradeTooLowException(brc.getGrade());
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException(this->getIsSigned());
}


void	AForm::checkGrade(int grade) const{
	if (grade < 1)
			throw GradeTooHighException(grade);
	if (grade > 150)
			throw GradeTooLowException(grade);
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << form.getName() << ", with sign grade " << form.getSignGrade() << " and exec grade "\
	<< form.getExecGrade() << " ";
	return os;
}
