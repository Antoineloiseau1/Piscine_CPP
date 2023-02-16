/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:10 by antoine           #+#    #+#             */
/*   Updated: 2023/02/15 17:28:59 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setFirstName(void)
{
	std::string buffer;
	
	std::cout << "Enter First Name: ";
	std::getline(std::cin, buffer);
	this->_firstName = buffer;
}

void	Contact::setLastName(void)
{
	std::string buffer;
	
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, buffer);
	this->_lastName = buffer;
}

void	Contact::setNickName(void)
{
	std::string buffer;
	
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, buffer);
	this->_nickName = buffer;
}

void	Contact::setPhoneNumber(void)
{
	std::string buffer;
	
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, buffer);
	this->_phoneNumber = buffer;
}

void	Contact::setDarkestSecret(void)
{
	std::string buffer;
	
	std::cout << "What is your darkest secret ?: ";
	std::getline(std::cin, buffer);
	this->_darkestSecret = buffer;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickName(void) const
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

