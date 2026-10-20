/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:21:14 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/20 16:45:08 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void){
	Bureaucrat almightyBrc(1, "Gandalf");
	Intern slave;
	AForm*	form;

	std::cout << "\nTESTING CORRECT FORM NAMES\n";

	try{
		form = slave.makeForm("shrubbery creation", "master");
		almightyBrc.signForm(*form);
		almightyBrc.executeForm(*form);
		delete form;
	}
	catch (const Intern::FormNameNotFoundException& e){
		std::cerr << "Intern couldn't create the form: " << e.what() << std::endl;
	}

	try{
		form = slave.makeForm("robotomy request", "master");
		almightyBrc.signForm(*form);
		almightyBrc.executeForm(*form);
		delete form;
	}
	catch (const Intern::FormNameNotFoundException& e){
		std::cerr << "Intern couldn't create the form: " << e.what() << std::endl;
	}

	try{
		form = slave.makeForm("presidential pardon", "master");
		almightyBrc.signForm(*form);
		almightyBrc.executeForm(*form);
		delete form;
	}
	catch (const Intern::FormNameNotFoundException& e){
		std::cerr << "Intern couldn't create the form: " << e.what() << std::endl;
	}

	std::cout << "\nTESTING INCORRECT FORM NAMES\n";

	try{
		form = slave.makeForm("sin absolution", "master");
		almightyBrc.signForm(*form);
		almightyBrc.executeForm(*form);
		delete form;
	}
	catch (const Intern::FormNameNotFoundException& e){
		std::cerr << "Intern couldn't create the form: " << e.what() << std::endl;
	}

	try{
		form = slave.makeForm("", "master");
		almightyBrc.signForm(*form);
		almightyBrc.executeForm(*form);
		delete form;
	}
	catch (const Intern::FormNameNotFoundException& e){
		std::cerr << "Intern couldn't create the form: " << e.what() << std::endl;
	}
	std::cout << "\nEND OF TESTING" << std::endl;
	return 0;
}


