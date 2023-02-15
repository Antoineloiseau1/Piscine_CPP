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

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Please come back anytime" << std::endl;
}

void	PhoneBook::addContact(void)
{
	this->_entry[0].setFirstName();
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << this->_entry[0].getFirstName() << std::endl;
}

