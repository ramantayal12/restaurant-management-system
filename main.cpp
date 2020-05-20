#include<iostream>
#include<vector>
#include "option_1.h"
#include "option_2.h"
using namespace std;


int main(){


    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;


    while( option != 5 ){

        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 2 :- Restaurant Menu "<<endl;
        cout<<"Option 5 :- Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){
            
            option1();
            continue;

        }
        else if( option == 2 ){

            option2();
            continue;

        }
        else if( option == 5 ){

            cout<<" Thank You "<<endl;
            break;
        }

    }
    return 0;
}