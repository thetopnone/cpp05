/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:52:55 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/06 19:43:01 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: sign_grade(150)
	, exec_grade(150)
	, name("null_form")
	, is_signed(false)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

Form::Form(int _sign_grade, int _exec_grade, std::string _name)
	: sign_grade(_sign_grade)
	, exec_grade(_exec_grade)
	, name(_name)
	, is_signed(false)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

Form::Form(const Form& other)
	: sign_grade(other.sign_grade)
	, exec_grade(other.exec_grade)
	, name(other.name)
	, is_signed(other.is_signed)
	{
		checkGrade(sign_grade);
		checkGrade(exec_grade);
	}

Form& Form::operator=(const Form& other){
	(void)other;
	return (*this);
}

Form::~Form(){};

const int& Form::getSignGrade() const{
	return (sign_grade);
}

const int& Form::getExecGrade() const{
	return (exec_grade);
}

const std::string& Form::getName() const{
	return (name);
}

bool& Form::getIsSigned(){
	return (is_signed);
}

void	Form::beSigned(const Bureaucrat& brc){
	if (brc.getGrade() > sign_grade)
		throw Form::GradeTooLowException(brc.getGrade());
	is_signed = true;
}

void	Form::checkGrade(int grade) const{
	if (grade < 1)
			throw GradeTooHighException(grade);
	if (grade > 150)
			throw GradeTooLowException(grade);
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << form.getName() << ", with sign grade " << form.getSignGrade() << " and exec grade "\
	<< form.getExecGrade() << " ";
	return os;
}
