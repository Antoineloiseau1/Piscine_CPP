/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repertory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:02:16 by antoine           #+#    #+#             */
/*   Updated: 2023/02/15 17:46:40 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook	repertory;
	std::string	buffer;
	
	std::cout << "Welcome to your own PhoneBook !" << std::endl;

	do
	{
		std::cout << "What would you like to do ?: [ADD] [SEARCH] [EXIT]: ";
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
			repertory.addContact();
		if (buffer == "SEARCH")
			repertory.displayContacts();
	}while (buffer != "EXIT");
	return (0);
}