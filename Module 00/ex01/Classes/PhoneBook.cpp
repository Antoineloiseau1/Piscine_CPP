/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:59:50 by antoine           #+#    #+#             */
/*   Updated: 2023/02/15 17:25:08 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void) : _index(0)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Please come back anytime" << std::endl;
}

void	PhoneBook::addContact(void)
{
	if (this->_index > 7)
		this->_index = 0;
	this->_entry[this->_index].setFirstName();
	this->_entry[this->_index].setLastName();
	this->_entry[this->_index].setNickName();
	this->_entry[this->_index].setPhoneNumber();
	this->_entry[this->_index].setDarkestSecret();
	this->_index++;
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		if ((this->_entry[i].getFirstName().size()) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout << this->_entry[i].getFirstName()[j];
			std::cout << ".|";
		}
		else
		{
			for (int j = 0; j < (10 - (this->_entry[i].getFirstName()).size()); j++)
				std::cout << ' ';
			std::cout << this->_entry[i].getFirstName() << "|";
		}
		if ((this->_entry[i].getLastName().size()) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout << this->_entry[i].getLastName()[j];
			std::cout << ".|";
		}
		else
		{
			for (int j = 0; j < (10 - (this->_entry[i].getLastName()).size()); j++)
				std::cout << ' ';
			std::cout << this->_entry[i].getLastName() << "|";
		}
		if ((this->_entry[i].getNickName().size()) > 10)
		{
			for(int j = 0; j < 9; j++)
				std::cout << this->_entry[i].getNickName()[j];
			std::cout << ".|" << std::endl;
		}
		else
		{
			for (int j = 0; j < (10 - (this->_entry[i].getNickName()).size()); j++)
				std::cout << ' ';
			std::cout << this->_entry[i].getNickName() << "|" << std::endl;
		}
	}
	this->_displayInfos();
}

void	PhoneBook::_displayInfos(void) const
{
	std::string	buffer;
	int		index;		

	do
	{
		std::cout << "Which contact would you like to see ? [1 - 8]: ";
		std::cin >> index;
		std::cout << "index = " << index << std::endl;
		if (index >= 1 && index <= 8)
		{
			std::cout << "First Name: " << this->_entry[index -1].getFirstName() << std::endl;
			std::cout << "Last Name: " << this->_entry[index - 1].getLastName() << std::endl;
			std::cout << "Nick Name: " << this->_entry[index - 1].getNickName() << std::endl;
			std::cout << "Phone Number: " << this->_entry[index - 1].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << this->_entry[index - 1].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Wrong index format" << std::endl;
	}while(!(index >= 1 && index <= 8));
}


