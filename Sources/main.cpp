#include "../Headers/Guest.cpp"
#include "../Headers/Ride.cpp"
#include "../Headers/Admin.cpp"
#include <iostream>

using namespace std;

int main(){
    int ch;

    do {
        cout<<"WELOCOME TO AMUSEMENT PARK"<<endl;

        cout<<"1. Admin Login"<<endl;
        cout<<"2. Support Login"<<endl;
        cout<<"3. Rides Login"<<endl;
        cout<<"4. Guest Login"<<endl;
        cout<<"5. Exit "<<endl;

        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch){
            case 1:{
                Admin Ad;

                string pass;
                do {
                    cout<<"Enter password (0 to exit) : ";
                    cin>>pass;

                    if (pass == "0"){
                        break;
                    }

                } while(pass!=Ad.pass);

                if (pass == "0" ){
                    break;
                }

                if( pass == Ad.pass ){
                    int a_ch;
                    do {
                        cout<<"1. Search a Guest  "<<endl;
                        cout<<"2. Enter a new Sride  "<<endl;
                        cout<<"3. Delete a ride  "<<endl;
                        cout<<"4. Change password  "<<endl;
                        cout<<"5. Exit  "<<endl;

                        cout<<"Enter your choice : ";
                        cin>>a_ch;

                        switch(a_ch){
                            case 1: {
                                cout<<"Option not available now"<<endl;
                                break;
                            }
                            case 2: {
                                cout<<"Option not available now"<<endl;
                                break;
                            }
                            case 3: {
                                cout<<"Option not available now"<<endl;
                                break;
                            }
                            case 4: {
                                Ad.changePass();
                                break;
                            }
                            case 5: {
                                a_ch=0;
                                break;
                            }
                            default :{
                                cout<<"Invalid choice ! "<<endl;
                                break;
                            }
                        }

                    } while(a_ch);
                }

                break;
            }
            case 2:{
                cout<<"Option not available now"<<endl;




                break;
            }
            case 3:{
                cout<<"Option not available now"<<endl;





                break;
            }
            case 4:{
                cout<<"Option not available now"<<endl;





                break;
            }
            case 5:{
                cout<<"Unsaved data will be lost"<<endl;
                ch=0;
                break;
            }
            default:{
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

    } while(ch);

    return 0;
}