#include "CashPayment.h"
#include <iostream>

using namespace std;

void CashPayment::pay(double price)
{
    cout << "\n";
    cout << "==================================================" << endl;
    cout << "                  CASH PAYMENT                   " << endl;
    cout << "==================================================" << endl;

    cout << "Your Bill : $" << price << endl;
    cout << "Payment   : Cash" << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "           Payment completed successfully!       " << endl;
    cout << "==================================================" << endl;
}