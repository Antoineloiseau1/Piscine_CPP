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
	std::cin >> buffer;
	this->_firstName = buffer;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}
