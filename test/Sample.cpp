/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:49:46 by antoine           #+#    #+#             */
/*   Updated: 2023/02/15 14:53:40 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"
#include <iostream>

Sample::Sample(char c, int i, std::string str) : letter(c), number(i), message(str)
{
	std::cout << "Constructor Called" << std::endl;
	this->aff_string();
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	return;
}

void	Sample::aff_string(void)
{
	std::cout << "this.letter = " << this->letter << std::endl;
	std::cout << "this.number = " << this->number << std::endl;
	std::cout << "this.message = " << this->message << std::endl;
	
	return;
}
