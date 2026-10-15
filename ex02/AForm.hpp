/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:52:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/15 18:23:18 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP
# include <exception>
# include <string>
# include <iostream>

class Bureaucrat;

class AForm{
	private:
		const int sign_grade;
		const int exec_grade;
		const std::string name;
		const std::string target;
		bool is_signed;
	public:
		AForm();
		AForm(int _sign_grade, int _exec_grade, std::string _name, std::string _target);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm() = 0;

		const int&	getSignGrade() const;
		const int& 	getExecGrade() const;
		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool	getIsSigned() const;

		void	beSigned(const Bureaucrat& brc);
		virtual void	beExecuted() const = 0;
		void	execute(Bureaucrat const & executor) const;
		void	canSign(const Bureaucrat& brc);
		void	canExecute(const Bureaucrat& brc) const;
		void	checkGrade(int grade) const;
		
		class GradeTooHighException : public std::exception{
			private:
				int value;
			public:
				GradeTooHighException(int val):value(val){}
				const char *what() const throw(){
					return "Form::GradeTooHighException";
				}
				int getValue(){
					return value;
				}
		};

		class GradeTooLowException :public std::exception{
			private:
				int value;
			public:
				GradeTooLowException(int val):value(val){}
				const char* what() const throw(){
					return "Form::GradeTooLowException";
				}
				int getValue(){
					return value;
				}
		};

		class FormNotSignedException: public std::exception{
			private:
				int value;
			public:
				FormNotSignedException(int val): value(val){}
				const char *what() const throw(){
					return "Form::FormNotSignedException";
				}
				int getValue(){
					return value;
				}
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &frm);
#endif

