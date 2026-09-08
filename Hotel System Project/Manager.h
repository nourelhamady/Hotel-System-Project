#pragma once
#include "Person.h"
#include "Room.h"
#include"HotelSystem.h"
class HotelSystem;
class Manager : public Person
{
public:
    void showRooms(HotelSystem& h);
    void ShowBookedRooms(HotelSystem& h);
    void showWaitingList(HotelSystem& h);
};
