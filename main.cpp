#include<iostream>
#include<sqlite3.h>
#include<vector>
#include<typeinfo>
#include "menu_header.h"
using namespace std;


vector<menu> order;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){       		// Just Making a duplicate copy of the menuitems in order vector

    menu mn_it;
    for(int i=0; i<argc ; i++){
        cout << azColName[i] << " : " << argv[i] << " "<<endl;
    }
    
    cout<<endl;
    return 0;
}



int main(){


    sqlite3 *db;
    char *zErrMsg = 0;
    int rc = sqlite3_open("items.db",&db);
    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;
    vector<menu> cust_orders;									// To store current order of customer

    while( option != 6 ){
           
        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 2 :- Show Restaurant Menu "<<endl;
        cout<<"Option 3 :- Provide your Order"<<endl;
        cout<<"Option 4 :- Admin Block "<<endl;
        cout<<"Option 5 :- Generate PDF Receit "<<endl;
        cout<<"Option 6 :- Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){

            cout<<"We provide the efficient way of billing in a Restaurant"<<endl;
            continue;

        }
        else if( option == 2 ){
        
            string sql_statement = " SELECT * FROM items;";
            sqlite3_exec(db,sql_statement.c_str(),callback,NULL,NULL);					
            
            continue;

        }
        else if( option == 3 ){

            order.clear(); // clearing old order details 
            string sql_statement = " SELECT * FROM items;";
            sqlite3_exec(db,sql_statement.c_str(),callback,NULL,NULL);
            int total_price = 0, estimated_time = 0;
            cust_orders.clear();                       		//Clearing orders of previous customers
            string flag;

            int i = 1;
            while( flag != "n" ){

                cout<<"Please Enter Food Name : "<<endl;
                string name,price;
                cin>>name>>price;
                menu mnit;
                mnit.id = i++;
                mnit.foodName = name;
                mnit.price = price;
                mnit.time = "15";
                cust_orders.push_back(mnit);

                cout<<" Want to Order More "<<endl;
                cout<<" y / n "<<endl;
                cin>>flag;
            }
            continue;
        }
        else if( option == 4 ){

            char op = 'a';
            cout<<"Please Enter Your Password"<<endl;
            string pass;
            cin>>pass;
            if( pass == "12345" ){
                cout<<" Welcome to Admin Block "<<endl;
                cout<<" Option 1 :- Add item to Menu Press 1 "<<endl;
                cout<<" Option 2 :- Remove item from Menu Press 2"<<endl;
                int sel = 0;
                cin>>sel;
                if( sel == 1 ){

                    string name,price,time;
                    cout<<"Please Enter food Name, Price and Time "<<endl;
                    cin>>name>>price>>time;
                    string sql_statement = "INSERT INTO items (food_name,price,time) values (' ";                  // Creating a SQL statement to make new entry of food item
                    sql_statement += name + "' ,";
                    sql_statement += price + ",";
                    sql_statement += time + ");";
                    

                    rc = sqlite3_exec(db, sql_statement.c_str(), NULL, 0, &zErrMsg);                       // If it executes perfectly ,then only it will return SQLITE_OK
                    if( rc!=SQLITE_OK )
                    {
                        cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";									   //  Printing the error returned
                        sqlite3_free(zErrMsg);
                        break;
                    }

                    while( op != 'n' ){
                        cout<<"Want to ADD more "<<endl;
                        cout<<" y / n "<<endl;
                        cin>>op;
                        if( op == 'n'){
                            break;
                        }

                        cout<<"Please Enter food Name, Price and Time "<<endl;
                        cin>>name>>price>>time;
                        sql_statement = "INSERT INTO items (food_name,price,time) values (' ";            // 'INSERT' Keyword is used to insert new entry
                        sql_statement += name + "' ,";
                        sql_statement += price + ",";
                        sql_statement += time + ");";

                        rc = sqlite3_exec(db, sql_statement.c_str(), NULL, 0, &zErrMsg);
                        if( rc!=SQLITE_OK )
                        {
                            cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
                            sqlite3_free(zErrMsg);
                            break;
                        }
                    }
                }
                else if( sel == 2 ){
                    cout<<"Please Enter Food-ID to Delete "<<endl;
                    string x;
                    cin>>x;

                    string sql_statement = "DELETE FROM items WHERE Food_ID =  ";						//'Delete' Keyword is used to delete entry 
                    sql_statement += x + ";";
                    rc = sqlite3_exec(db, sql_statement.c_str(), NULL, 0, &zErrMsg);
                    if( rc!=SQLITE_OK )
                    {
                        cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
                        sqlite3_free(zErrMsg);
                        break;
                    }
                }
                
            }
            else{

                cout<<"Wrong Password "<<endl;
                
            }
            continue;
            
        }
        else if( option == 5 ){
            int price = 0,time = 0;
            cout<<"Food order :"<<endl;
            for(int i=0;i<cust_orders.size();i++){
                cout<<cust_orders[i].id<<" "<<cust_orders[i].foodName<<endl;
                price = stoi(cust_orders[i].price);
                time += 15;
            }
            cout<<"Your Total Bill is : "<<price<<endl;
            cout<<"Time for Your is : "<<time<<endl;

        }
        else if( option == 6 ){

            cout<<" Thank You "<<endl;
            break;
        }

    }

    sqlite3_close(db);
    return 0;
}
