#include "Account.hpp"

static std::string formatDate(time_t *date)
{
    struct tm *tt = localtime(date);
    std::ostringstream os;

    os << "[";
    os << std::setfill('0') << std::setw(4) << 1900 + tt->tm_year;
    os << std::setfill('0') << std::setw(2) << 1 + tt->tm_mon;
    os << std::setfill('0') << std::setw(2) << tt->tm_mday;
    os << "_";
    os << std::setfill('0') << std::setw(2) << tt->tm_hour;
    os << std::setfill('0') << std::setw(2) << tt->tm_min;
    os << std::setfill('0') << std::setw(2) << tt->tm_sec;
    os << "] ";

    return os.str();
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
}

void Account::makeDeposit(int deposit)
{
}

bool Account::makeWithdrawal(int withdrawal)
{
    return true;
}
int Account::checkAmount(void) const
{
    return 0;
}

void Account::displayStatus(void) const
{
    time_t *now = time(NULL);
    std::string dateStr = formatDate(now);
    
    std::ostringstream os;
    os << dateStr;
    os << "index:" << _accountIndex;
    os << ";amount:" << _amount;
    os << ";deposits:" << _nbDeposits;
    os << ";withdrawals:" << _nbWithdrawals;

    std::cout << << std::endl;
}

Account(int initial_deposit) : _amount(initial_deposit),
                               _nbDeposits(0),
                               _nbWithdrawals(0),
                               _accountIndex(_nbAccounts)
{
}
