#include "HotelSystem.h"
#include <iostream>

using namespace std;

void mainUI(HotelSystem& hotel);

int main()
{
    HotelSystem hotel;

    cout << "\n";
    cout << "==================================================" << endl;
    cout << "                                                  " << endl;
    cout << "              WELCOME TO OUR HOTEL               " << endl;
    cout << "                                                  " << endl;
    cout << "==================================================" << endl;

    cout << "\n        Your Comfort, Our Priority!" << endl;
    cout << "\n        Press Enter to enter the system...";

    cin.ignore();
    cin.get();

    mainUI(hotel);

    return 0;
}