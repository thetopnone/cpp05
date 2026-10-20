/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 16:20:07 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/20 16:44:35 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <exception>
# include <string>

class AForm;

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);

		class FormNameNotFoundException : public std::exception{
			private:
				int val;
			public:
				FormNameNotFoundException(int _val) : val(_val){}
				const char* what() const throw(){
					return "Intern::FormNameNotFoundException";
				}
				int getValue() {return val;}
		};
};

#endif
