#include "Manager.h"
#include "HotelSystem.h"
#include<list>
void Manager::showRooms(HotelSystem& h)
{
    for (Room& r : h.getRooms())
    {
        r.showRoom();
    }
}
void Manager::ShowBookedRooms(HotelSystem& h)//bonus
{
    h.ShowBookedRooms();
}
void Manager::addRoom(HotelSystem& h)//bonus
{
    int Roomnumber;
    double Price;
    cout << "Enter Room Number: ";
    cin >> Roomnumber;
    list<Room> v=h.getRooms();
    for (Room& x : v)
    {
        if (x.getrnumber() == Roomnumber)
        {
            cout << "Sorry, the room is already there." << endl;
            return;
        }
    }
    cout << "Enter Room Price: ";
    cin >> Price;
    Room newRoom(Roomnumber, Price);
    h.addRoom(newRoom);
    cout << "Room added successfully!" << endl;
}
void Manager::showWaitingList(HotelSystem& h)
{
    h.showWaitingList();
}