#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

private std::string formatDate(t_time *date)
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
    os << "]";

    std::cout << os.str() << std::endl;
}


static int	getNbAccounts( void )
{
    return _nbAccounts;
}

static int	getTotalAmount( void )
{
    return _totalAmount;
}

static int	getNbDeposits( void )
{
    return _totalNbDeposit;
}

static int	getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

static void	displayAccountsInfos( void )
{

}


void	makeDeposit( int deposit )
{

}

bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const
{

}


Account( int initial_deposit ): _amount(initial_deposit)
{
}

