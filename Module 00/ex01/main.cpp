/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:02:16 by antoine           #+#    #+#             */
/*   Updated: 2023/02/21 13:59:43 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook	repertory;
	std::string	buffer;
	
	std::cout << "Welcome to your the PhoneBook !" << std::endl;

	do
	{
		std::cout << "What would you like to do ?: [ADD] [SEARCH] [EXIT]: ";
		std::getline(std::cin, buffer);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		if (buffer == "ADD")
			repertory.addContact();
		if (buffer == "SEARCH")
			repertory.displayContacts();
	}while (buffer != "EXIT");
	std::cout << "come back anytime" << std::endl;
	return (0);
}
