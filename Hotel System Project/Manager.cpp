#include "Manager.h"
#include "HotelSystem.h"
void Manager::showRooms(HotelSystem& h)
{
    for (Room& r : h.getRooms())
    {
        r.showRoom();
    }
}
void Manager::ShowBookedRooms(HotelSystem& h)
{
    h.ShowBookedRooms();
}
void Manager::showWaitingList(HotelSystem& h)
{
    h.showWaitingList();
}