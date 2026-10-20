/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:20:22 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/20 16:45:14 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static int	extractFormID(std::string formName);

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm* Intern::makeForm(std::string formName, std::string target){
	AForm* res = NULL;

	int	formID = extractFormID(formName);
	std::cout << "Intern creates ";
		
	switch (formID){
		case 0:
			std::cout << "Shrubbery Creation Form\n";
			res = new ShrubberyCreationForm(target);
			break;
		case 1:
			std::cout << "Robotomy Request Form\n";
			res = new RobotomyRequestForm(target);
			break;
		case 2:
			std::cout << "Presidential Pardon Form\n";
			res = new PresidentialPardonForm(target);
			break;
	}
	return res;
}

static int	extractFormID(std::string formName){
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++){
		if (formName == formNames[i])
			return i;
	}
	throw Intern::FormNameNotFoundException(-1);
}
