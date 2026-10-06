/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/06 19:43:53 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(int _grade, std::string _name)
	:grade(_grade)
	,name(_name)
	{
		checkGrade();
	}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:grade(other.grade)
	,name(other.name)
	{
		checkGrade();
	}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	(void) other;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

void	Bureaucrat::checkGrade() const{
	if (this->grade < 1)
			throw GradeTooHighException(grade);
	if (this->grade > 150)
			throw GradeTooLowException(grade);
}

int const& Bureaucrat::getGrade() const{
	return (this->grade);
}

std::string const& Bureaucrat::getName() const{
	return(name);
}

void Bureaucrat::upGrade(){
		grade--;
		checkGrade();
		std::cout << this->getName() << ", got their grade increased\n";
}

void Bureaucrat::downGrade(){
		grade++;
		checkGrade();
		std::cout << this->getName() << ", got their grade decreased\n";
}

void Bureaucrat::signForm(Form& form){
	try{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const Form::GradeTooLowException& e){
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& brc){
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return os;
}

