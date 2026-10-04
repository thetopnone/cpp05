/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:52:05 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 13:11:22 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat{
	private:
		int	grade;
		std::string const name;
	public:
		Bureaucrat(int _grade, std::string _name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		int& getGrade() const;
		const std::string& getName() const;

		void upGrade() const;
		void downGrade() const;
		void checkGrade() const;

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

#endif
