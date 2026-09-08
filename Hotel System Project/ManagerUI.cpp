#include "Manager.h"
#include "HotelSystem.h"
#include <iostream>
#include <string>
using namespace std;

void managerUI(HotelSystem& hotel)
{
    int id;
    string password;

    cout << "\n";
    cout << "==================================================" << endl;
    cout << "                  MANAGER LOGIN                   " << endl;
    cout << "==================================================" << endl;

    cout << "\nEnter Manager ID : ";
    cin >> id;

    cout << "Enter Password   : ";
    cin >> password;

    if (id != 1 || password != "admin123")
    {
        cout << "\n--------------------------------------------------" << endl;
        cout << "             Invalid ID or Password!              " << endl;
        cout << "                  Access denied.                  " << endl;
        cout << "--------------------------------------------------" << endl;

        return;
    }

    cout << "\n==================================================" << endl;
    cout << "              Login successful!                  " << endl;
    cout << "              Welcome, Manager!                  " << endl;
    cout << "==================================================" << endl;

    int choice;
    Manager m;

    do
    {
        cout << "\n";
        cout << endl;
        cout << "                  MANAGER MENU                   " << endl;
        cout << endl;
        cout << "   1.  Show All Rooms" << endl;
        cout << "   2.  Show Waiting List" << endl;
        cout << "   3.  Show Booked Rooms" << endl;
        cout << "   0.  Logout" << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        cout << endl;
        switch (choice)
        {
        case 1:
            m.showRooms(hotel);
            break;

        case 2:
            m.showWaitingList(hotel);
            break;

        case 3:
            m.ShowBookedRooms(hotel);
            break;

        case 0:
            cout << "==================================================" << endl;
            cout << "              Logging out...                     " << endl;
            cout << "==================================================" << endl;
            break;

        default:
            cout << "--------------------------------------------------" << endl;
            cout << "            Invalid choice! Try again.            " << endl;
            cout << "--------------------------------------------------" << endl;
        }

    } while (choice != 0);
}