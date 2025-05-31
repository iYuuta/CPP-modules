#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _totalAmount += _amount;
    std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
    _nbAccounts++;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year
              << std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ltm->tm_hour
              << std::setw(2) << std::setfill('0') << ltm->tm_min
              << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:"
    << getTotalAmount() << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
    << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:"
    << _nbDeposits << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    if (checkAmount() < withdrawal) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
        << ";withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
    << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
    << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    return true;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
    << _amount << ";deposits:" << _nbDeposits << 
    ";withdrawals:" << _nbWithdrawals << std::endl;
}
