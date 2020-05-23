#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include "option_1.h"
#include "option_2.h"
#include "option_3.h"
using namespace std;


int main(){


    //ifstream fin;
    //ofstream fout;
    //fout.open("menu.txt");
    //fin.open("menu.txt");
    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;
    vector<menuItem> menu;


    while( option != 5 ){

           
        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 2 :- Show Restaurant Menu "<<endl;
        cout<<"Option 3 :- Provide your Order"<<endl;
        cout<<"Option 4 :- Admin Block "<<endl;
        cout<<"Option 5 :- Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){
            
            option1();
            continue;

        }
        else if( option == 2 ){
            
            string item;
            //fin.open("menu.txt");
            menu = option2();
            /*
            while( fin ){
                getline(cin,line);
                cout<<line<<endl;
            }
            */
            continue;

        }
        else if( option == 3 ){

            if( menu.size() == 0 ){
                menu = option2();
            }
            vector<int> aa = option3(menu);
            int price = aa[0], time = aa[1];
            cout<<"Your Total Bill is "<<price<<endl;
            cout<<"Estimated time to your order is : "<<time<<endl;
            continue;

        }
        else if( option == 4 ){
            cout<<"Please Enter Your Password"<<endl;
            string pass;
            cin>>pass;
            if( pass == "12345" ){
                cout<<" Welcome to Admin Block "<<endl;
                cout<<" Option 1 :- Add item to Menu "<<endl;
                cout<<" Option 2 :- Remove item from Menu "<<endl;
                int sel = 0;
                cin>>sel;
                if( sel == 1 ){
                    cout<<"Please Enter Food-Item to Add "<<endl;
                    string name; cin>>name;
                    int price, time;
                    cout<<"Please Enter food item name "<<endl;
                    cin>>price;
                    cout<<"Please Enter Price and time "<<endl;
                    cin>>time;
                    //fout<<name<<" "<<price<<" "<<time<<endl;
                    
                }
                else if( sel == 2 ){
                    cout<<"Please Enter Food-Item Number to Delete "<<endl;
                    int x, i = 0;
                    cin>>x;
                    
                }
                else{
                    
                }
                
            }
            else{
                cout<<"Wrong Password "<<endl;
                
            }
            
            
        }
        else if( option == 5 ){

            cout<<" Thank You "<<endl;
            break;
        }
        
    }
    cout<<"Please rate our Services "<<endl;
    cout<<" 1 :- Very Bad "<<endl;
    cout<<" 2 :- Bad "<<endl;
    cout<<" 3 :- Average "<<endl;
    cout<<" 4 :- Good "<<endl;
    cout<<" 5 :- Excellent "<<endl;
    int feedback = 0;
    cin>>feedback;
    cout<<"Thanks for Your Feedback"<<endl;
    return 0;
}