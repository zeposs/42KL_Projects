#include "account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


// Static Variables //
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


// _displayTimestamp Helper //
void Account::_displayTimestamp()
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year
		<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << ltm->tm_hour
		<< std::setw(2) << std::setfill('0') << ltm->tm_min
		<< std::setw(2) << std::setfill('0') << ltm->tm_sec
		<< "] ";
}


// Constructor and Destructor //
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0){

	_totalAmount += _amount;

	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ":amount:" << _amount
				<< ";closed" << std::endl;
}

// makeDeposit () //
void  Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout	<< ";deposit:" << deposit
				<< ";amount;" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}


// makeWithdrawal () //
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;

	if (withdrawal > _amount){
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

//****** CheckAmout + displayStatus ******//
int Account::checkAmount()
const {

		return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}


int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}