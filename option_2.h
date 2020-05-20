#include<iostream>
#include<vector>
#include "menu_header.h"
using namespace std;

vector<menuItem> option2(){
    vector<menuItem> menu;
    menu.push_back(menuItem("Aloo Parantha" , 20,5));
    menu.push_back(menuItem("Mix Parantha", 35,5));
    menu.push_back(menuItem("Onion Parantha", 30,5));
    menu.push_back(menuItem("Paneer Parantha",45,5));
    menu.push_back(menuItem( "Aloo Zeera Rajma" ,60,10));
    menu.push_back(menuItem("Yellow Dal", 70,12));	
    menu.push_back(menuItem(" Dal Tadka" , 70,12));
    menu.push_back(menuItem("Dal Makhni",80,15));
    menu.push_back(menuItem("Mix Veg",80,10));
    menu.push_back(menuItem("Channa Masala",80,15));
    menu.push_back(menuItem("Malai Kofta",130,15));
    menu.push_back(menuItem("Kadhai Paneer",140,15));
    menu.push_back(menuItem("Shahi Paneer",140,15));
    menu.push_back(menuItem("Cheese Tomato",140,15));
    menu.push_back(menuItem("Paneer Tikka Masala",160,15));
    menu.push_back(menuItem("Paneer Butter Masala",140,15));
    menu.push_back(menuItem("Palak Paneer", 140,10));
    menu.push_back(menuItem("Paneer Bhurji",160,10));
    menu.push_back(menuItem("Mutter Paneer",140,10));
    menu.push_back(menuItem("Mutter Mushroom",140,10));
    menu.push_back(menuItem("Fried Rice",90,7));
    menu.push_back(menuItem("VegNoodles",70,5));
    menu.push_back(menuItem("Cheese Noodles",90,7));
    menu.push_back(menuItem("Manchurian",90,10));
    menu.push_back(menuItem("Cheese Chilly",140,10));
    menu.push_back(menuItem("Honey Gobhi",99,7));
    menu.push_back(menuItem("Honey Chilli Potato",99,7));
    menu.push_back(menuItem("Veg Sandwich",50,10));
    menu.push_back(menuItem("Cheese Sandwich",70,10));
    menu.push_back(menuItem("Corn Sandwich",70,10));
    menu.push_back(menuItem("Aloo Tikki burger",30,12));
    menu.push_back(menuItem("Veg Tikki Burger",40,12));
    menu.push_back(menuItem("Cheese Burger",50,12));
    menu.push_back(menuItem("Pine Apple Burger",70,12));
    menu.push_back(menuItem("Tea",10,5));
    menu.push_back(menuItem("Hot Coffee",35,5));
    menu.push_back(menuItem("Cold Coffee",50,5));
    menu.push_back(menuItem("Tawa Roti",5,2));
    menu.push_back(menuItem("Tandoori Roti",5,2));
    menu.push_back(menuItem("Cheese Naan",60,10));
    menu.push_back(menuItem("Green Salad",45,5));

    cout<<"Menu"<<endl;
	for(int i=0;i<menu.size();i++){
	    cout<<i+1<<"."<<'\t'<<menu[i].itemName<<'\t'<<menu[i].cost<<'\t'<<menu[i].time<<"min"<<endl;
	}
	cout<<endl;

    return menu;
}