#include "Guest.h"
using namespace std ;

void Guest::entry()
{
    cout<<"To book your entry pass Enter the required data\n" ;
    cout<<"Name :\t" ;
    cin>>name ;
    cout<<"\nAge :\t" ;
    cin>>age ;
    cout<<"\nGender :\t" ;
    cin>>gender ;
    cout<<"\nHeight :\t" ;
    cin>>height ;
    cout<<"\nThe amount to be paid\tRs. 1500\n" ;
    booking_status = true ;

}

void admin::login(int admin_id)
{
    string password = "admin@amusement" ;
    string pass ;
    cout<<"Enter the admin password\n" ;
    cin>>pass ;
    if (password.compare(pass))
    {
        int type ;
        cout<<"Select frorm the list\n" ;
        cout<<"1. You are facilitated to modify rides list\n2. You are facilitated to track record of any guest\n3. You are facilitated to block any rides\n" ;
        cin>>type ;

        switch(type)
        {
            case 1:{
                
                break ;
            }

            case 2:{
                break ;
            }

            case 3:{
                break ;
            }

            default:{
                
            }
        }
    }

}

void Guest::bookride()
{
    // display rides
    // create object for each ride
    // pass age into ride func and check and confirm booking
}