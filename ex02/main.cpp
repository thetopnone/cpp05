/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 18:11:57 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/19 13:55:11 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void){
	Bureaucrat almightyBrc(1, "Gandalf");
	Bureaucrat weakBrc(150, "Leaf");
	Bureaucrat averageBrc(25, "Joe Biden");

	PresidentialPardonForm f1("Dana White");
	ShrubberyCreationForm f2("Stadium");
	RobotomyRequestForm f3("Joe");
	
	std::cout << "\nTESTING ALMIGHTY BRC FORM EXECUTION\n";
	{
		almightyBrc.executeForm(f1);
		almightyBrc.signForm(f1);
		almightyBrc.executeForm(f1);
	}
	{
		almightyBrc.executeForm(f2);
		almightyBrc.signForm(f2);
		almightyBrc.executeForm(f2);
	}
	{
		almightyBrc.executeForm(f3);
		almightyBrc.signForm(f3);
		almightyBrc.executeForm(f3);
	}

	std::cout << "\nTESTING WEAK BRC FORM EXECUTION\n";

	{
		weakBrc.executeForm(f1);
		weakBrc.signForm(f1);
		weakBrc.executeForm(f1);
	}
	{
		weakBrc.executeForm(f2);
		weakBrc.signForm(f2);
		weakBrc.executeForm(f2);
	}
	{
		weakBrc.executeForm(f3);
		weakBrc.signForm(f3);
		weakBrc.executeForm(f3);
	}

	std::cout << "\nTESTING AVERAGE BRC FORM EXECUTION\n";

	{
		averageBrc.executeForm(f1);
		averageBrc.signForm(f1);
		averageBrc.executeForm(f1);
	}
	{
		averageBrc.executeForm(f2);
		averageBrc.signForm(f2);
		averageBrc.executeForm(f2);
	}
	{
		averageBrc.executeForm(f3);
		averageBrc.signForm(f3);
		averageBrc.executeForm(f3);
	}

	std::cout << "\nEND OF TESTING\n";
	return 0;
}
