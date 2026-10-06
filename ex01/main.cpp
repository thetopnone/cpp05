/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:25:06 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/06 19:59:23 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	Bureaucrat almightyBrc(1, "Gandalf");
	Bureaucrat weakBrc(150, "Fruit Fly");
	Bureaucrat averageBrc(70, "Jane Doe");

	Form lowForm(150, 150, "Toilet Paper");
	Form highForm(1, 1, "Tavern Order");
	Form midForm (70, 70, "Passport Renewal Form");
	Form f1(90, 20, "Banana Order Form");
	Form f2(10, 1, "Starbucks Job Application");
	
	std::cout << "\nTESTING FORM COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR \n\n";
	{
		Form test1(f1);
		std::cout << "test1: " << test1 << "\nf1: " << f1 << "\n";

		Form test2;
		test2 = f1;
		std::cout << "test2: " << test2 << "\nf1: " << f1 << "\n";
	}

	std::cout << "\nTESTING FORM OUT OF BOUNDS CONSTRUCTION\n\n";
	try{
		Form tooHighSign(0,1,"invalid form");
	}
	catch (const Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form tooHighExec(1,0, "invalid");
	}
	catch (const Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form tooLowSign(200, 150, "invalid");
	}
	catch (const Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form tooLowExec(150, 200, "invalid");
	}
	catch (const Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}

	//Both following test will throw only 1 exception because the program
	//stops execution from the first throw it reaches, until the catch block
	try{
		Form bothTooHigh(-1, -2, "invalid");
	}
	catch(const Form::GradeTooHighException& e){
		std::cout << e.what() << std::endl;
	}

	try{
		Form bothTooLow(200, 300, "invalid");
	}
	catch (const Form::GradeTooLowException& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTESTING BUREAUCRAT SIGNFORM EXCEPTIONS\n\n";
	{
		almightyBrc.signForm(lowForm);
		almightyBrc.signForm(highForm);
		almightyBrc.signForm(midForm);
		almightyBrc.signForm(f1);
		almightyBrc.signForm(f2);

		weakBrc.signForm(lowForm);
		weakBrc.signForm(highForm);
		weakBrc.signForm(midForm);
		weakBrc.signForm(f1);
		weakBrc.signForm(f2);

		averageBrc.signForm(lowForm);
		averageBrc.signForm(highForm);
		averageBrc.signForm(midForm);
		averageBrc.signForm(f1);
		averageBrc.signForm(f2);
	}

	std::cout << "\nEND OF TESTING\n";
	return 0;
}
