#pragma once
#include<string>
using namespace std;
class Person
{
protected:
	string name;
	int id;
public:
	void setData(string n, int i);
	string getName();//bonus
	int getID();//bonus
	void showData();
};

