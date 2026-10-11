/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:13:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/11 18:34:44 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm::AForm(25, 5, "Presidential Pardon", target)
	{}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential Pardon Form has been shredded\n" << std::endl;
}

void PresidentialPardonForm::beExecuted() const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}


