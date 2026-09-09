#include "Person.h"
#include <iostream>
using namespace std;
void Person::setData(string n, int i)
{
	name = n;
	id = i;
}
string Person::getName()//bonus
{
	return name;
}
int Person::getID()//bonus
{
	return id;
}
void Person::showData()//bonus ui only
{
    cout << "\n";
    cout << "---------------- MY INFORMATION ----------------" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
    cout << "-------------------------------------------------" << endl;
}