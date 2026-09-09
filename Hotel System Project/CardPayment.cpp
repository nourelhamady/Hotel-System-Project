#include "CardPayment.h"
#include <iostream>

using namespace std;

void CardPayment::pay(double price)//bonus ui + adding price or amount
{
    cout << "\n";
    cout << "==================================================" << endl;
    cout << "                  CARD PAYMENT                   " << endl;
    cout << "==================================================" << endl;

    cout << "Your Bill : $" << price << endl;
    cout << "Payment   : Card" << endl;

    cout << "--------------------------------------------------" << endl;
    cout << "           Payment completed successfully!       " << endl;
    cout << "==================================================" << endl;
}