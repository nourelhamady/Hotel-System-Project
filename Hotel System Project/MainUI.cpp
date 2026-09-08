#include "HotelSystem.h"
#include <iostream>

using namespace std;

void customerUI(HotelSystem& hotel);
void managerUI(HotelSystem& hotel);

void mainUI(HotelSystem& hotel)
{
    int choice;

    do
    {
        cout << "\n";
        cout << "==================================================" << endl;
        cout << "                 HOTEL SYSTEM                    " << endl;
        cout << "==================================================" << endl;
        cout << "   1.  Customer" << endl;
        cout << "   2.  Manager" << endl;
        cout << "   0.  Exit" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 1:
          customerUI(hotel);
            break;

        case 2:
           managerUI(hotel);
            break;

        case 0:
            cout << "==================================================" << endl;
            cout << "        Thank you for using our hotel!           " << endl;
            cout << "                  Goodbye!                       " << endl;
            cout << "==================================================" << endl;

            break;

        default:
            cout << "--------------------------------------------------" << endl;
            cout << "            Invalid choice! Try again.            " << endl;
            cout << "--------------------------------------------------" << endl;
        }

    } while (choice != 0);
}