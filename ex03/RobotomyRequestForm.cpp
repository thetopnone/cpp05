/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:13:07 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/15 18:21:07 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target)
	: AForm::AForm(72, 45, "Robotomy Request", _target)
	{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm::AForm(other)
	{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	(void) other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy Request form has been shredded" << std::endl;
}

void	RobotomyRequestForm::beExecuted() const{
	int	rval;

	srand(time(NULL));
	rval = rand() % 2;
	
	if (rval == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->getTarget() << " has failed miserably" << std::endl;
}
