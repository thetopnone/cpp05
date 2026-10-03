/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:10 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/03 19:52:02 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int _grade, std::string _name)
	:grade(_grade)
	,name(_name)
	{};

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:grade(other.grade)
	,name(other.name)
	{};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	void(other);
	return (*this);
}


