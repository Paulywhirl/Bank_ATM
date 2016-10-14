#include <iostream>
#include <string.h>
#include <fstream>
#include "User.h"
using namespace std;

int main() {


    bool user = false, user_type = false;
    int type;
    User new_user;

    cout << "Welcome to your ATM machine!" << endl;

    do
    {
        cout << endl << "Please indicate your user-type:" << endl;
        cout << "1 - Customer\n2 - Manager\n" << endl;
        cin >> type;

        if(type == 1 || type == 2){
            new_user.SetUserType(type);
            user_type = true;
        }
        else{
            cout << "Error: Not a User Type!" << endl;
        }

    }while(!user_type);

    cout<<"Please enter User credentials"<<endl;

    while(!user){

        if(type == 1){

        }
        else{

        }

        cout << "Username: ";
        cin >> new_user.username;
        cout << "\nPassword: ";
        cin >> new_user.password;


    }

    return 0;
}