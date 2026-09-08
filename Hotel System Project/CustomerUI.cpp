#include "Customer.h"
#include "HotelSystem.h"
#include "CashPayment.h"
#include "CardPayment.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

list<Customer> customers;

void customerUI(HotelSystem& hotel)
{
    int choice;

    do
    {
        cout << "\n";
        cout << "==================================================" << endl;
        cout << "                 CUSTOMER MENU                   " << endl;
        cout << "==================================================" << endl;
        cout << "   1.  Register" << endl;
        cout << "   2.  Login" << endl;
        cout << "   0.  Back" << endl;
        cout << "==================================================" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 1:
        {
            string name;
            int id;

            cout << "==================================================" << endl;
            cout << "              CUSTOMER REGISTRATION               " << endl;
            cout << "==================================================" << endl;

            cout << "\nEnter your name : ";
            cin >> name;

            cout << "Enter your ID   : ";
            cin >> id;

            Customer customer;
            customer.setData(name, id);
            customers.push_back(customer);

            cout << "\n--------------------------------------------------" << endl;
            cout << "           Registration successful!              " << endl;
            cout << "--------------------------------------------------" << endl;

            break;
        }

        case 2:
        {
            string name;
            int id;
            bool flag = false;

            cout << "==================================================" << endl;
            cout << "                 CUSTOMER LOGIN                  " << endl;
            cout << "==================================================" << endl;

            cout << "\nEnter your name : ";
            cin >> name;

            cout << "Enter your ID   : ";
            cin >> id;

            Customer customer;

            for (Customer& c : customers)
            {
                if (c.getID() == id && c.getName() == name)
                {
                    customer = c;
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                cout << "\n--------------------------------------------------" << endl;
                cout << "              Login successful!                 " << endl;
                cout << "              Welcome, " << name << "!             " << endl;
                cout << "--------------------------------------------------" << endl;
            }
            else
            {
                cout << "\n--------------------------------------------------" << endl;
                cout << "              Wrong Name or ID!                  " << endl;
                cout << "              Please try again!                  " << endl;
                cout << "--------------------------------------------------" << endl;

                break;
            }

            int customerChoice;
            int room_number;

            do
            {
                cout << "\n";
                cout << endl;
                cout << "                CUSTOMER ACCOUNT                 " << endl;
                cout <<endl;
                cout << "   1.  View Rooms" << endl;
                cout << "   2.  Book Room" << endl;
                cout << "   3.  My Bookings" << endl;
                cout << "   4.  Cancel Room" << endl;
                cout << "   5.  My Information" << endl;
                cout << "   6.  Payment" << endl;
                cout << "   0.  Logout" << endl;
                cout << "--------------------------------------------------" << endl;

                cout << "Enter your choice : ";
                cin >> customerChoice;

                cout << endl;

                switch (customerChoice)
                {
                case 1:
                {
                    cout << "------------------- ALL ROOMS -------------------" << endl;

                    hotel.showRooms();

                    break;
                }

                case 2:
                {
                    cout << "------------------- BOOK ROOM --------------------" << endl;

                    hotel.showRooms();

                    cout << "\nEnter room number : ";
                    cin >> room_number;

                    bool found = false;

                    for (Room& room : hotel.getRooms())
                    {
                        if (room.getrnumber() == room_number)
                        {
                            found = true;
                            customer.bookRoom(room, hotel);
                        }
                    }

                    if (!found)
                    {
                        cout << "\n--------------------------------------------------" << endl;
                        cout << "                 Room not found.                 " << endl;
                        cout << "--------------------------------------------------" << endl;
                    }

                    break;
                }

                case 3:
                {
                    customer.showMyBookings();
                    break;
                }

                case 4:
                {
                    bool found = false;

                    if (customer.showMyBookings())
                    {
                        cout << "\nEnter the room number you want to cancel : ";
                        cin >> room_number;

                        for (Room& room : hotel.getRooms())
                        {
                            if (room.getrnumber() == room_number)
                            {
                                found = true;
                                customer.cancelRoom(room);
                            }
                        }

                        if (!found)
                        {
                            cout << "\n--------------------------------------------------" << endl;
                            cout << "                 Room not found.                 " << endl;
                            cout << "--------------------------------------------------" << endl;
                        }
                    }

                    break;
                }

                case 5:
                {
                    customer.showData();
                    break;
                }

                case 6:
                {
                    int paymentChoice;

                    cout << "==================================================" << endl;
                    cout << "                    PAYMENT                       " << endl;
                    cout << "==================================================" << endl;
                    cout << "   1.  Cash" << endl;
                    cout << "   2.  Card" << endl;
                    cout << "   0.  Cancel" << endl;
                    cout << "==================================================" << endl;

                    cout << "Enter your choice : ";
                    cin >> paymentChoice;

                    cout << endl;

                    Payment* P;
                    double room_price;
                    bool found = false;

                    if (customer.showMyBookings())
                    {
                        cout << "\nEnter the room number you want to Pay : ";
                        cin >> room_number;

                        for (Room& room : hotel.getRooms())
                        {
                            if (room.getrnumber() == room_number)
                            {
                                found = true;
                                room_price = room.getPrice();
                            }
                        }

                        if (!found)
                        {
                            cout << "\n--------------------------------------------------" << endl;
                            cout << "                 Room not found.                 " << endl;
                            cout << "--------------------------------------------------" << endl;
                        }

                        if (paymentChoice == 1)
                        {
                            P = new CashPayment();
                            P->pay(room_price);
                        }
                        else if (paymentChoice == 2)
                        {
                            P = new CardPayment();
                            P->pay(room_price);
                        }
                        else if (paymentChoice == 0)
                        {
                            cout << "Payment cancelled." << endl;
                        }
                        else
                        {
                            cout << "Invalid choice." << endl;
                        }
                    }

                    break;
                }

                case 0:
                {
                    cout << "\n==================================================" << endl;
                    cout << "                 Logging out...                  " << endl;
                    cout << "==================================================" << endl;

                    break;
                }

                default:
                {
                    cout << "\n--------------------------------------------------" << endl;
                    cout << "            Invalid choice! Try again.            " << endl;
                    cout << "--------------------------------------------------" << endl;

                    break;
                }
                }

            } while (customerChoice != 0);

            break;
        }

        case 0:
        {
            cout << "\n==================================================" << endl;
            cout << "            Returning to main menu...             " << endl;
            cout << "==================================================" << endl;

            break;
        }

        default:
        {
            cout << "\n--------------------------------------------------" << endl;
            cout << "            Invalid choice! Try again.            " << endl;
            cout << "--------------------------------------------------" << endl;

            break;
        }
        }

    } while (choice != 0);
}