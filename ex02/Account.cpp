/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 07:42:33 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/09 11:04:48 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::getNbAccounts() { return Account::_nbAccounts; }
int Account::getTotalAmount() { return Account::_totalAmount; }
int Account::getNbDeposits() { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals() { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(Account::_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    if (deposit < 0) return;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    this->_amount += deposit;
    this->_nbDeposits += 1;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal < 0) return false;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    if (this->_amount < withdrawal) {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;

    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

    return true;
}

int Account::checkAmount(void) const { return this->_amount; }

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[18];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 18, "[%Y%m%d_%H%M%S]", timeinfo);
    std::cout << buffer << " ";
}

Account::Account(void)
    : _accountIndex(Account::_nbAccounts),
      _amount(0),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    Account::_nbAccounts += 1;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}
