#pragma once
#include <iostream>
using namespace std;
class Room
{
private:
    int roomnumber;
    double price;
    bool booked;

public:
    Room(int num, double p);
    bool book();
    void cancel();
    bool isAvailable();
    double getPrice();
    int getrnumber();
    void showRoom();
};
