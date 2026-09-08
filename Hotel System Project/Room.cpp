#include "Room.h"
using namespace std;
Room::Room(int num, double p)
{
    roomnumber = num;
    price = p;
    booked = false;
}

bool Room::book()
{
    if (!booked)
    {
        booked = true;
        return true;
    }

    return false;
}

void Room::cancel()
{
    booked = false;
}

bool Room::isAvailable()
{
    return !booked;
}

double Room::getPrice()
{
    return price;
}
int Room::getrnumber()
{
    return roomnumber;
}
void Room::showRoom()
{
    cout << "+------------------------------------------------+" << endl;

    cout << "|  Room Number : " << roomnumber << endl;
    cout << "|  Price       : $" << price << endl;

    cout << "|  Status      : ";

    if (booked)
    {
        cout << "Booked" << endl;
    }
    else
    {
        cout << "Available" << endl;
    }

    cout << "+------------------------------------------------+" << endl;
}