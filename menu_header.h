#include<string.h>
#include<iostream>
using namespace std;

class menuItem{
public:
	string itemName;
	int cost;
	menuItem( string a, int b ){
		itemName = a;
		cost = b;
	}
};

