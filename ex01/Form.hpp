/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 16:52:51 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/04 18:55:48 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

class Form{
	private:
		const int sign_grade;
		const int exec_grade;
		const std::string name;
		bool is_singed;
	public:
		Form();
		Form(int _signGrade, int _execGrade, std::string name);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		const int&	getSignGrade() const;
		const int& 	getExecGrade() const;
		const std::string&	getName() const;
		const bool	getIsSigned() const;

		void	beSigned(const Bureaucrat& brc);
};

std::ostream &operator<<(std::ostream &os, const Form &frm);
#endif

