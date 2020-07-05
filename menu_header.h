#include<string.h>
#include<iostream>
using namespace std;

class menu{
public:
	string foodName,id;
	string price,time;
	menu( string id,string name, string price, string time ){
		this->id = id;
		this->foodName = name;
		this->price = price;
		this->time = time;
	}
};

