#pragma once
#include "Person.h"
#include "Room.h"
#include<vector>
class HotelSystem;
class Customer : public Person
{

    vector<Room> mybookings;
public:
    void bookRoom(Room& r, HotelSystem& h);
    void cancelRoom(Room& r);
    bool showMyBookings();
};