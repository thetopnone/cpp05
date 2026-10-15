/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:12:27 by akonstan          #+#    #+#             */
/*   Updated: 2026/10/15 18:31:50 by akonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target)
	: AForm::AForm(145, 137, "Shrubbery Creation", _target)
	{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm::AForm(other)
	{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubbery Creation form has been shredded" << std::endl;
}

void ShrubberyCreationForm::beExecuted() const{
	std::fstream fs;
	std::string filename;

	filename = this->getTarget() + "_shrubbery";
	fs.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
	fs << "The Worm's Turn\n"
           "\n"
           " \n"
           " \n"
           "              _{\\ _{\\{\\/}/}/}__\n"
           "             {/{/\\}{/{/\\}(\\}{/{/\\} _\n"
           "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
           "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
           "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
           "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
           "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
           "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
           "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
           "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
           "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
           "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
           "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
           "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/} (\\}\n"
           "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_\n"
           "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
           "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
           "              {){/ {\\/}{\\/} \\}\\}\n"
           "              (_)  \\.-'.-/\n"
           "          __...--- |'-.-'| --...__\n"
           "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
           " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
           " .  '-  '    .--'  | '-.'|    .  '  . '\n"
           "          ' ..     |'-_.-|\n"
           "  .  '  .       _.-|-._ -|-._  .  '  .\n"
           "              .'   |'- .-|   '.\n"
           "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
           "   .-' '        '-._______.-'     '  .\n"
           "        .      ~,\n"
           "    .       .   |\\   .    ' '-.\n"
           "    ___________/  \\____________\n"
           "   /  Why is it, when you want \\n"
           "  |  something, it is so damn   |\n"
           "  |    much work to get it?     |\n"
           "   \\___________________________/\n";
}
