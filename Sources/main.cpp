#include "../Headers/Guest.cpp"
#include "../Headers/Ride.cpp"
#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;
int i;

// password for admin entry is @admin

int main(){
    unsigned int uid; 
    int ch;
    int flag = 1 ;
    i = 0 ;
    Guest number[1000] ;  // array of objects
                          // each guest data with be stored in seprate object
    map<unsigned int,Guest>database ;     // map for uid and guest obj

    while (flag)
     {
        cout<<"WELCOME TO AMUSEMENT PARK"<<endl;

        cout<<"1. Admin Login"<<endl;
        cout<<"2. Support Login"<<endl;
        cout<<"3. Rides Login"<<endl;
        cout<<"4. Guest Booking New"<<endl;
        cout<<"5. Guest Login"<<endl ;
        cout<<"6. To exit"<<endl ;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:{
                int id ;
                cout<<"Enter your admin id\t" ;
                cin>>id ;
                admin obj ;
                obj.login(id) ;

                break;
            }

            case 2:{
                cout<<""<<endl;
                break;
            }

            case 3:{
                cout<<""<<endl;
                break;
            }
            
            case 4:{
                int tickets ;
                cout<<"Unsaved data will be lost"<<endl;
                cout<<"How many tickets you want to book\t" ;
                cin>>tickets ;
                ch=0;
                for (int x=0 ; x<tickets ; x++)
                {
                    i++ ;
                    number[i].entry() ;     // entry for guest number i object
                    database.insert(make_pair(i,number[i])) ;
                    cout<<"Your uid is "<<i<<endl ;  
                }
                break;
            }

            case 5:{
                cout<<"Enter your UID"<<endl ;
                cin>>uid ;
                auto itr = database.find(uid) ;
                Guest tmp_obj = itr->second ;        // it is not working have a look
                tmp_obj.bookride() ;
                break ;

            }

            case 6:{
                flag = 0 ;
                break ;
            }

            default:{
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

    } 

    return 0;
}

/* ride names
wonderland, thunder, nitro, deep space. top spin, duck-duck, splash */