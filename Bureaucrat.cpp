/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 13:18:26 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int _grade, std::string _name)
	:grade(_grade)
	,name(_name)
	{
		try
			checkGrade();
		catch (GradeTooHighException& e)
			std::cerr << e.what() << std::endl;
		catch (GradeTooLowException& e)
			std::cerr << e.what() << std::endl;
	};

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:grade(other.grade)
	,name(other.name)
	{
		try
			checkGrade();
		catch (GradeTooHighException& e)
			std::cerr << e.what() << std::endl;
		catch (GradeTooLowException& e)
			std::cerr << e.what() << std::endl;
	};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	void(other);
	return (*this);
}

Bureaucrat::~Bureaucrat(){};

void	Bureaucrat::checkGrade() const{
	if (this->grade < 1)
			throw GradeTooHighException(grade);
	if (this->grade > 150)
			throw GradeTooLowException(grade);
}

