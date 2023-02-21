/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:07:02 by antoine           #+#    #+#             */
/*   Updated: 2023/02/21 17:22:58 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout 
	<< "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount
    << ";deposit:" << deposit;
    this->_amount += deposit;
    std::cout 
	<< ";amount:" << this->_amount
    << ";nb_deposits:" << ++this->_nbDeposits 
	<< std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout 
	<< "index:" << this->_accountIndex
    << ";p_amount:" << this->_amount;
    if (this->_amount - withdrawal < 0)
	{
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    } 
	else 
	{
        std::cout << ";withdrawal:" << withdrawal;
        this->_amount -= withdrawal;
        std::cout << ";amount:" << this->_amount
            << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        return (true);
    }
}

void	Account::_displayTimestamp(void)
{
	time_t tt = time(NULL);
	struct std::tm *time = std::localtime(&tt);
	std::cout << "[" << std::put_time(time, "%Y%m%d_%H%M%S] ");
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 
	<< "accounts:" << Account::getNbAccounts() 
	<< ";total:" << Account::getTotalAmount() 
	<< ";deposits:" << Account::getNbDeposits() 
	<< ";withdrawals:" << Account::getNbWithdrawals() 
	<< std::endl;	
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 
	<< "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount 
	<< ";deposits:" << this->_nbDeposits 
	<< ";withdrawals:" << this->_nbWithdrawals 
	<< std::endl;
}

int	Account::checkAmount( void ) const 
{
    return (this->_amount);
}

