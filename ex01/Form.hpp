/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:52:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/05 19:50:36 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <exception>
# include <string>
# include <iostream>

class Bureaucrat;

class Form{
	private:
		const int sign_grade;
		const int exec_grade;
		const std::string name;
		bool is_signed;
	public:
		Form();
		Form(int _sign_grade, int _exec_grade, std::string _name);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		const int&	getSignGrade() const;
		const int& 	getExecGrade() const;
		const std::string&	getName() const;
		bool&	getIsSigned();

		void	beSigned(const Bureaucrat& brc);
		void	checkGrade(int grade) const;
		
		class GradeTooHighException : public std::exception{
			private:
				int value;
			public:
				GradeTooHighException(int val):value(val){}
				const char *what() const throw(){
					return "Form::GradeTooHighException\n";
				}
		};

		class GradeTooLowException :public std::exception{
			private:
				int value;
			public:
			GradeTooLowException(int val):value(val){}
				const char* what() const throw(){
					return "Form::GradeTooLowException\n";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &frm);
#endif

