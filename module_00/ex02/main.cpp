#include "Account.hpp"

int main()
{
    Account c(100);
    Account c1(200);
    c.displayStatus();
    c1.displayStatus();
    Account::displayAccountsInfos();
    c.makeDeposit(50);
    c.makeDeposit(50);
    c.makeWithdrawal(1);
    c.displayStatus();
    c1.makeWithdrawal(1000);
    Account::getTotalAmount();
    Account::displayAccountsInfos();
    return 0;
    // time_t now = time(NULL);

    // struct tm *tt = localtime(&now);
    // std::ostringstream os;
    // os << "[";
    // os << std::setfill('0') << std::setw(4) << 1900 + tt->tm_year;
    // os << std::setfill('0') << std::setw(2) << 1 + tt->tm_mon;
    // os << std::setfill('0') << std::setw(2) << tt->tm_mday;
    // os << "_";
    // os << std::setfill('0') << std::setw(2) << tt->tm_hour;
    // os << std::setfill('0') << std::setw(2) << tt->tm_min;
    // os << std::setfill('0') << std::setw(2) << tt->tm_sec;
    // os << "]";

    // std::cout << os.str() << std::endl;
}