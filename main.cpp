#include<iostream>
using namespace std;


void option_1(){

    cout<<"We provide the efficient way of billing in a Restaurant"<<endl;
}


int main(){


    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;


    while( option != 5 ){
        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 5 : Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){
            
            option_1();
            continue;

        }
        else if( option == 5 ){

            cout<<" Thank You "<<endl;
            break;
        }

    }
    return 0;
}