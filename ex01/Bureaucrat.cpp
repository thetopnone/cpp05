/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 16:00:35 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int _grade, std::string _name)
	:grade(_grade)
	,name(_name)
	{
		try{
			checkGrade();
		}	
		catch (GradeTooHighException& e){
			std::cerr << e.what() << std::endl;
		}
		catch (GradeTooLowException& e){
			std::cerr << e.what() << std::endl;
		}
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat& brc){
	os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
	return os;
}

