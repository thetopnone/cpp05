/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:11:57 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/11 18:39:28 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	Bureaucrat almightyBrc(1, "Gandalf");
	PresidentialPardonForm f1("Dana White");

	almightyBrc.executeForm(f1);
	almightyBrc.signForm(f1);
	almightyBrc.executeForm(f1);
	return 0;
}
