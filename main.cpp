#include<iostream>
#include "sqlite3.h"
#include<vector>
#include "option_1.h"
using namespace std;

class menu{
public:
	string foodName,id;
	string price,time;
	menu(){
	}
	menu( string id,string name, string price, string time ){
		this->id = id;
		this->foodName = name;
		this->price = price;
		this->time = time;
	}
};


vector<menu> order;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){       		// Just Making a duplicate copy of the menuitems in order vector

    menu mn_it;
    for(int i=0; i<argc ; i++){
        cout << azColName[i] << " : " << argv[i] << endl;
        if( argc == 0 ){
            mn_it.id = argv[i];
        }
        else if( argc == 1 ){
            mn_it.foodName = argv[i];
        }
        else if( argc == 2 ){
            mn_it.price = argv[i];
        }
        else if( argc == 3 ){
            mn_it.time = argv[i];
        }
    }
    order.push_back(mn_it);
    cout << endl;
    return 0;
}



int main(){


    sqlite3 *db;
    char *zErrMsg = 0;
    int rc = sqlite3_open("items.db",&db);
    cout<<"Welcome to Restaurant Billing System "<<endl;
    int option = 0;
    vector<int> cus_orders;											// To store current order of customer

    while( option != 6 ){
           
        cout<<"Option 1 :- About US "<<endl;
        cout<<"Option 2 :- Show Restaurant Menu "<<endl;
        cout<<"Option 3 :- Provide your Order"<<endl;
        cout<<"Option 4 :- Admin Block "<<endl;
        cout<<"Option 5 :- Generate Receit "<<endl;
        cout<<"Option 5 :- Exit the Application "<<endl;
        cin>>option;

        if( option == 1 ){

            option1();
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
            cus_orders.clear();                       		//Clearing orders of previous customers
            string id_number,flag;
            while( flag != "n" ){
                
                int index = -1;
                cin>>id_number;
                bool flag = false;						   // Finding the index of food item to be ordered
                for(int i=0;i<order.size();i++){
                    if( id_number == order[i].id){
                        index = i;
                        flag = true;
                    }
                }
                if( !flag ){
                    cout<<"Sorry this Food-ID don't exist ";
                    cout<<"Please reEnter the Food-Id";
                    continue;
                }

                cus_orders.push_back(index);              // Adding that index of food item to customer order
                
                cout<<" Want to Order More "<<endl;
                cout<<" y / n "<<endl;
                cin>>flag;
            }

            cout<<endl;
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
                    char op = 'a';

                    while( op != 'n' ){
                        cout<<"Want to ADD more "<<endl;
                        cout<<" y / n "<<endl;
                        cin>>op;

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
                    cout<<"Please Enter Food-ID Name to Delete "<<endl;
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
            // this function is yet to implement
            // with implementaion of this we can even print the receit genrated
        }
        else if( option == 6 ){

            cout<<" Thank You "<<endl;
            break;
        }

    }
    

    sqlite3_close(db);
    return 0;
}
