/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 18:56:06 by akonstan         ###   ########.fr       */
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

void signForm(Form& form){
	form.beSigned();
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& brc){
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return os;
}

