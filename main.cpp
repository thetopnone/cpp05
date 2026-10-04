/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:10:50 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 16:02:13 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat	b1(1, "John");
	Bureaucrat	b2(150, "Bob");

	std::cout << "\nTESTING COPY CONSTRUCTOR AND COPY ASSIGNMENT\n\n";

	Bureaucrat b3(b1);
	Bureaucrat b4(50, "Alice");
	b4 = b1;

	std::cout << "b1: " << b1 << "\nb3: " << b3 << "\nb4: " << b4 << std::endl;

	std::cout << "\nTESTING GRADING FUNCTIONS\n\n";

	try{
		b1.upGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		b1.downGrade();
		b2.downGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		b2.upGrade();
		b4.upGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}

	b4.downGrade();

	std::cout << "\nTESTING CONSTRUCTOR EXCEPTION HANDLING\n\n";

	try{
		Bureaucrat tooHigh(-10, "Lily");
	}
	catch (const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		Bureaucrat tooLow(2000, "Valentine");
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\nEND OF ALL TESTS\n";
	return 0;
}
