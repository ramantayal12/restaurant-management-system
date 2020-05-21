#include<iostream>
#include<vector>
using namespace std;

vector<int> option3(vector<menuItem> &menu){


    cout<<" Please select food-item number "<<endl;
    vector<string> orders;
    int sel = 0, total_price = 0,time = 0;
    string flag;
    while( flag != "n" ){
        
        cin>>sel;
        if( sel >= 42 ){
            cout<<"Sorry Food-item number don't exists"<<endl;
            continue;
        }
        orders.push_back(menu[sel-1].itemName);
            
        total_price += menu[sel-1].cost;
        time = menu[sel-1].time;
        
        cout<<"    Order till now :- "<<endl;
        for(int i=0;i<orders.size();i++){
            cout<<i+1<<". "<<orders[i]<<endl;
        }
        cout<<" Want to Order More "<<endl;
        cout<<" y / n "<<endl;
        cin>>flag;
    }


    cout<<"Thanks for Ordering with Us "<<endl;
    vector<int> v;
    v.push_back(total_price);
    v.push_back(time);
    return v;
    
}