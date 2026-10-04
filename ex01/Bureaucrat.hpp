/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:05 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 18:55:43 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat{
	private:
		int	grade;
		std::string const name;
	public:
		Bureaucrat(int _grade, std::string _name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		int const& getGrade() const;
		std::string const& getName() const;

		void upGrade();
		void downGrade();
		void checkGrade() const;

		void signForm(Form& form);

		class GradeTooHighException : public std::exception{
			private:
				int value;
			public:
				GradeTooHighException(int val) : value(val) {}
				const char* what() const throw(){
					return "Bureaucrat::GradeTooHighException\n";
				}
				int getValue(){
					return value;
				}
		};

		class GradeTooLowException : public std::exception{
			private:
				int value;
			public:
				GradeTooLowException(int val) : value(val) {}
				const char* what() const throw(){
					return "Bureaucrat::GradeTooLowException\n";
				}
				int getValue(){
					return value;
				}
		};

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& brc);
#endif
