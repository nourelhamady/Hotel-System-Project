#include "HotelSystem.h"
#include <iostream>
HotelSystem::HotelSystem()//bonus saved data
{
    rooms.push_back(Room(101, 500));
    rooms.push_back(Room(102, 500));
    rooms.push_back(Room(103, 600));
    rooms.push_back(Room(104, 650));

    rooms.push_back(Room(201, 700));
    rooms.push_back(Room(202, 800));
    rooms.push_back(Room(203, 900));
    rooms.push_back(Room(204, 1000));

    rooms.push_back(Room(301, 1200));
    rooms.push_back(Room(302, 1500));
    rooms.push_back(Room(303, 1800));
    rooms.push_back(Room(304, 2500));
}
void HotelSystem::addRoom(Room r)
{
    rooms.push_back(r);
}
void HotelSystem::addToWaitingList(Customer c,int room_number)
{
    waitingList[room_number].push(c);
}
void HotelSystem::showRooms()//bonus ui only
{
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                 HOTEL ROOMS                      " << endl;
    cout << "==================================================" << endl;

    for (auto it = rooms.begin(); it != rooms.end(); ++it)
    {
        it->showRoom();
    }

    cout << "==================================================" << endl;
}
void HotelSystem::ShowBookedRooms()//bonus
{
    list<Room> x = getRooms();

    cout << endl;
    cout << "==================================================" << endl;
    cout << "                BOOKED ROOMS                     " << endl;
    cout << "==================================================" << endl;

    bool found = false;

    for (Room& r : x)
    {
        if (!r.isAvailable())
        {
            r.showRoom();
            cout << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "              No booked rooms.                   " << endl;
    }

    cout << "==================================================" << endl;
}
void HotelSystem::showWaitingList()//bonus ui only + using map
{
    cout << endl;
    cout << "==================================================" << endl;
    cout << "                 WAITING LIST                     " << endl;
    cout << "==================================================" << endl;

    for (auto& m : waitingList)
    {
        cout << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "|              ROOM NUMBER: " << m.first << "                 |" << endl;
        cout << "+------------------------------------------------+" << endl;

        queue<Customer> q = m.second;

        while (!q.empty())
        {
            Customer c = q.front();

            cout << "| Customer                                      |" << endl;
            cout << "+------------------------------------------------+" << endl;

            c.showData();

            cout << "+------------------------------------------------+" << endl;

            q.pop();

            cout << endl;
        }
    }

    cout << "==================================================" << endl;
}
list<Room>& HotelSystem::getRooms()
{
    return rooms;
}