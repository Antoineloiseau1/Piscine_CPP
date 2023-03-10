/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:10 by antoine           #+#    #+#             */
/*   Updated: 2023/02/21 13:50:18 by antoine          ###   ########.fr       */
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
	int			start;
	int			end;
	
	do
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, buffer);	
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (buffer.find_first_not_of(" ") == std::string::npos)
			buffer = "";
		else
		{
			start = buffer.find_first_not_of(" ");
			end = buffer.find_last_not_of(" ") - start + 1;
			buffer = buffer.substr(start, end);
		}
	}while (buffer == "");
	this->_firstName = buffer;
}

void	Contact::setLastName(void)
{
	std::string buffer;
	int			start;
	int			end;
	
	do
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, buffer);	
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (buffer.find_first_not_of(" ") == std::string::npos)
			buffer = "";
		else
		{
			start = buffer.find_first_not_of(" ");
			end = buffer.find_last_not_of(" ") - start + 1;
			buffer = buffer.substr(start, end);
		}
	}while (buffer == "");
	this->_lastName = buffer;
}

void	Contact::setNickName(void)
{
	std::string buffer;
	int			start;
	int			end;
	
	do
	{
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, buffer);	
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (buffer.find_first_not_of(" ") == std::string::npos)
			buffer = "";
		else
		{
			start = buffer.find_first_not_of(" ");
			end = buffer.find_last_not_of(" ") - start + 1;
			buffer = buffer.substr(start, end);
		}
	}while (buffer == "");
	this->_nickName = buffer;
}

void	Contact::setPhoneNumber(void)
{
	std::string buffer;
	int			start;
	int			end;
	
	do
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, buffer);	
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (buffer.find_first_not_of(" ") == std::string::npos)
			buffer = "";
		else
		{
			start = buffer.find_first_not_of(" ");
			end = buffer.find_last_not_of(" ") - start + 1;
			buffer = buffer.substr(start, end);
		}
		if (buffer.find_first_not_of("+0123456789") != std::string::npos)
		{
			buffer = "";
			std::cout << "Please enter a valid phone number" << std::endl;
		}
	}while (buffer == "");
	this->_phoneNumber = buffer;
}

void	Contact::setDarkestSecret(void)
{
	std::string buffer;
	int			start;
	int			end;
	
	do
	{
		std::cout << "Enter Your Darkest Secret: ";
		std::getline(std::cin, buffer);	
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit (0);
		}
		if (buffer.find_first_not_of(" ") == std::string::npos)
			buffer = "";
		else
		{
			start = buffer.find_first_not_of(" ");
			end = buffer.find_last_not_of(" ") - start + 1;
			buffer = buffer.substr(start, end);
		}
	}while (buffer == "");
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

