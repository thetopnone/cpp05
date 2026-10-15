/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:13:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/15 18:07:40 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target)
	: AForm::AForm(25, 5, "Presidential Pardon", _target)
	{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm::AForm(other)
	{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
	{
		(void) other;
		return *this;
	}
PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential Pardon Form has been shredded\n" << std::endl;
}

void PresidentialPardonForm::beExecuted() const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}


