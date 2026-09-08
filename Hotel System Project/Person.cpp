#include "Person.h"
#include <iostream>
using namespace std;
void Person::setData(string n, int i)
{
	name = n;
	id = i;
}
string Person::getName()
{
	return name;
}
int Person::getID()
{
	return id;
}
void Person::showData()
{
    cout << "\n";
    cout << "---------------- MY INFORMATION ----------------" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
    cout << "-------------------------------------------------" << endl;
}