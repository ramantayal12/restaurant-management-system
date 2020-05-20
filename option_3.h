#include<iostream>
#include<vector>
using namespace std;

int option3(vector<menuItem> &menu){

    cout<<"While finished press 50  "<<endl;
    vector<int> orders;
    int sel = 0, total_price = 0;
    while( sel != 50 ){
        cin>>sel;
        total_price += menu[sel-1].cost;
    }
    cout<<"Thanks for Ordering with Us "<<endl;
    return total_price;
    
}