#include<iostream>
#include<vector>
#include "menu.h"
using namespace std;

void option2(){
    vector<menuItem> menu;
    menu.push_back(menuItem("Aloo Parantha" , 20));
    menu.push_back(menuItem("Mix Parantha", 35));
    menu.push_back(menuItem("Onion Parantha", 30));
    menu.push_back(menuItem("Paneer Parantha",45));
    menu.push_back(menuItem( "Aloo Zeera Rajma" ,60));
    menu.push_back(menuItem("Yellow Dal", 70));	
    menu.push_back(menuItem(" Dal Tadka" , 70));
    menu.push_back(menuItem("Dal Makhni",80));
    menu.push_back(menuItem("Mix Veg",80));
    menu.push_back(menuItem("Channa Masala",80));
    menu.push_back(menuItem("Malai Kofta",130));
    menu.push_back(menuItem("Kadhai Paneer",140));
    menu.push_back(menuItem("Shahi Paneer",140));
    menu.push_back(menuItem("Cheese Tomato",140));
    menu.push_back(menuItem("Paneer Tikka Masala",160));
    menu.push_back(menuItem("Paneer Butter Masala",140));
    menu.push_back(menuItem("Palak Paneer", 140));
    menu.push_back(menuItem("Paneer Bhurji",160));
    menu.push_back(menuItem("Mutter Paneer",140));
    menu.push_back(menuItem("Mutter Mushroom",140));
    menu.push_back(menuItem("Fried Rice",90));
    menu.push_back(menuItem("VegNoodles",70));
    menu.push_back(menuItem("Cheese Noodles",90));
    menu.push_back(menuItem("Manchurian",90));
    menu.push_back(menuItem("Cheese Chilly",140));
    menu.push_back(menuItem("Honey Gobhi",99));
    menu.push_back(menuItem("Honey Chilli Potato",99));
    menu.push_back(menuItem("Veg Sandwich",50));
    menu.push_back(menuItem("Cheese Sandwich",70));
    menu.push_back(menuItem("Corn Sandwich",70));
    menu.push_back(menuItem("Aloo Tikki burger",30));
    menu.push_back(menuItem("Veg Tikki Burger",40));
    menu.push_back(menuItem("Cheese Burger",50));
    menu.push_back(menuItem("Pine Apple Burger",70));
    menu.push_back(menuItem("Tea",10));
    menu.push_back(menuItem("Hot Coffee",35));
    menu.push_back(menuItem("Cold Coffee",50));
    menu.push_back(menuItem("Tawa Roti",5));
    menu.push_back(menuItem("Tandoori Roti",5));
    menu.push_back(menuItem("Cheese Naan",60));

    menu.push_back(menuItem("Green Salad",45));
    cout<<"Menu"<<endl;
	for(int i=0;i<menu.size();i++){
	    cout<<i+1<<"."<<menu[i].itemName<<'\t'<<menu[i].cost<<endl;
	}
	cout<<endl;
}