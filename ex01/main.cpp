/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:25:06 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/05 19:36:23 by akonstan         ###   ########.fr       */
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
	return 0;
}
