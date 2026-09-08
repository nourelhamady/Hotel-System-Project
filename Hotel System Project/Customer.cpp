#include "Customer.h"
#include "HotelSystem.h"
#include <iostream>

using namespace std;

void Customer::bookRoom(Room& r, HotelSystem& h)
{
    if (r.book())
    {
        cout << "\n";
        cout << "==================================================" << endl;
        cout << "                 ROOM BOOKING                    " << endl;
        cout << "==================================================" << endl;

        cout << "Room Number : " << r.getrnumber() << endl;
        cout << "Price       : $" << r.getPrice() << endl;

        mybookings.push_back(r);

        cout << "--------------------------------------------------" << endl;
        cout << "          Room booked successfully!              " << endl;
        cout << "==================================================" << endl;
    }
    else
    {
        cout << "\n";
        cout << "--------------------------------------------------" << endl;
        cout << "              Room is not available.             " << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "\nWould you like to join the waiting list? (Y/N): ";

        char ans;
        cin >> ans;

        if (ans == 'Y' || ans == 'y')
        {
            h.addToWaitingList(*this, r.getrnumber());

            cout << "\n--------------------------------------------------" << endl;
            cout << "     You have been added to the waiting list!    " << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
}

void Customer::cancelRoom(Room& r)
{
    if (mybookings.empty())
    {
        cout << "\n--------------------------------------------------" << endl;
        cout << "       There are no booked rooms to cancel.       " << endl;
        cout << "--------------------------------------------------" << endl;

        return;
    }

    for (auto it = mybookings.begin(); it != mybookings.end(); ++it)
    {
        if (it->getrnumber() == r.getrnumber())
        {
            r.cancel();
            mybookings.erase(it);

            cout << "\n==================================================" << endl;
            cout << "                ROOM CANCELLATION                " << endl;
            cout << "==================================================" << endl;

            cout << "Room Number : " << r.getrnumber() << endl;

            cout << "--------------------------------------------------" << endl;
            cout << "          Room booking cancelled!               " << endl;
            cout << "==================================================" << endl;

            return;
        }
    }

    cout << "\n--------------------------------------------------" << endl;
    cout << "     You can't cancel a room you haven't booked. " << endl;
    cout << "--------------------------------------------------" << endl;
}

bool Customer::showMyBookings()
{
    if (mybookings.empty())
    {
        cout << "\n--------------------------------------------------" << endl;
        cout << "             You haven't booked yet.             " << endl;
        cout << "--------------------------------------------------" << endl;

        return false;
    }
    else
    {
        cout << "\n";
        cout << "==================================================" << endl;
        cout << "                  MY BOOKINGS                    " << endl;
        cout << "==================================================" << endl;

        for (Room& b : mybookings)
        {
            b.showRoom();
            cout << endl;
        }

        cout << "==================================================" << endl;

        return true;
    }
}