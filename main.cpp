#include<iostream>
#include<vector>
#include<cstdlib>
#include "option_1.h"
#include "option_2.h"
#include "option_3.h"
#include <unistd.h>
#include <term.h>
using namespace std;



void cls(){
    cout << string( 100, '\n' );
}


int main(){


    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;
    vector<menuItem> menu;
    


    while( option != 5 ){

        
        
        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 2 :- Show Restaurant Menu "<<endl;
        cout<<"Option 3 :- Provide your Order"<<endl;
        cout<<"Option 5 :- Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){
            
            option1();
            continue;

        }
        else if( option == 2 ){
            
            menu = option2();
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