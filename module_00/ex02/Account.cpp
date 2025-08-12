#include "Account.hpp"

static std::string formatDate()
{
    time_t now = time(NULL);
    struct tm *tt = localtime(&now);

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

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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
    std::ostringstream os;

    os << formatDate();
    os << "accounts:" << getNbAccounts();
    os << ";total:" << getTotalAmount();
    os << ";deposits:" << getNbDeposits();
    os << ";withdrawals:" << getNbWithdrawals();

    std::cout << os.str() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

    std::string dateStr = formatDate();
    std::ostringstream os;
    os << dateStr;
    os << "index:" << _accountIndex;
    os << ";p_amount:" << _amount - deposit;
    os << ";deposit:" << deposit;
    os << ";amount:" << _amount;
    os << ";nb_deposits:" << _nbDeposits;

    std::cout << os.str() << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (_amount < withdrawal)
    {
        std::string dateStr = formatDate();

        std::ostringstream os;
        os << dateStr;
        os << "index:" << _accountIndex;
        os << ";p_amount:" << _amount;
        os << ";withdrawal:refused";

        std::cout << os.str() << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::string dateStr = formatDate();
    std::ostringstream os;
    os << dateStr;
    os << "index:" << _accountIndex;
    os << ";p_amount:" << _amount + withdrawal;
    os << ";withdrawal:" << withdrawal;
    os << ";amount:" << _amount;
    os << ";nb_withdrawals:" << _nbWithdrawals;

    std::cout << os.str() << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    std::string dateStr = formatDate();

    std::ostringstream os;
    os << dateStr;
    os << "index:" << _accountIndex;
    os << ";amount:" << _amount;
    os << ";deposits:" << _nbDeposits;
    os << ";withdrawals:" << _nbWithdrawals;

    std::cout << os.str() << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
                                        _amount(initial_deposit),
                                        _nbDeposits(0),
                                        _nbWithdrawals(0)
{
    std::ostringstream os;

    os << formatDate();
    os << "index:" << _accountIndex;
    os << ";amount:" << _amount;
    os << ";created";
    std::cout << os.str() << std::endl;

    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account()
{
    std::ostringstream os;

    os << formatDate();
    os << "index:" << _accountIndex;
    os << ";amount:" << _amount;
    os << ";closed";


    std::cout << os.str() << std::endl;
}
