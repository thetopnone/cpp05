/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/19 13:48:25 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	try{
		if (grade == 1)
			throw GradeTooHighException(grade);
		grade--;
		std::cout << this->getName() << ", got their grade increased\n";
	}
	catch (const GradeTooHighException& e){
			std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::downGrade(){
	try{
		if (grade == 150)
			throw GradeTooLowException(grade);
		grade++;
		std::cout << this->getName() << ", got their grade decreased\n";
	}
	catch (const GradeTooLowException& e){
			std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const AForm::GradeTooLowException& e){
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const{
	try{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (const AForm::GradeTooLowException& e){
		std::cout << *this << " couldn't execute " << form << " : " << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException& e){
		std::cout << *this << " couldn't execute " << form << " : " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& brc){
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return os;
}

