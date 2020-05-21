#include<string.h>
#include<iostream>
using namespace std;

class menuItem{
public:
	string itemName;
	int cost,time;
	menuItem( string name, int cost, int time ){
		this->itemName = name;
		this->cost = cost;
		this->time = time;
	}
};

