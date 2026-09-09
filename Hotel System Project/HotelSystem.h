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
    map<int,queue<Customer>> waitingList;//bonus using map 
public:
    HotelSystem();//rooms
    void addRoom(Room r);
    void addToWaitingList(Customer c,int room_number);//bonus adding number of room also 
    void showRooms();
    void ShowBookedRooms();//bonus
    void showWaitingList();
    list<Room>& getRooms();
};
