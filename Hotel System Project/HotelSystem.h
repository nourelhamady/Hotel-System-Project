#pragma once
#include<list>
#include<queue>
#include<map>
#include "Customer.h"
#include"Room.h"
class HotelSystem
{
private:
    list<Room> rooms;
    map<int,queue<Customer>> waitingList;
public:
    HotelSystem();
    void addRoom(Room r);
    void addToWaitingList(Customer c,int room_number);
    void showRooms();
    void ShowBookedRooms();
    void showWaitingList();
    list<Room>& getRooms();
};
