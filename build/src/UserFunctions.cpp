//
// Created by Owner on 2016-10-21.
//

#include "UserFunctions.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "User.h"

UserFunctions::UserFunctions() {}

void UserFunctions:: startUp(string f_name, int type) {

    User *user, current_user;
    user = &current_user;
    while (logged_on){


        if(type ==1) {
            findAccount(f_name, user);
            cout << "third\n";
            cout << "f: " << current_user.getFirstname();
            cout << "\nl: " << current_user.getLastname();
            cout << "\nc: " << setprecision(2) << fixed << current_user.isChecking();
            cout << "\ns: " << setprecision(2) << fixed << current_user.isSaving();
            customerMenu(user);

        }
        if(type ==2){

        }

    }
}

void UserFunctions::customerMenu(User *user){
    while (logged_on) {
        int option;
        cout << "\n*************************************\n";
        cout << "* 1 - Withdraw     2 - Deposit      *\n";
        cout << "* 3 - Transfer     4 - Logout       *\n";
        cout << "*************************************\n\n";
        cin >> option;

        switch (option) {
            case 1:
                cout << "testing withdraw";
                withdraw(user);
                break;
            case 2:
                cout << "testing deposit";
                deposit(user);
                break;
            case 3:
                cout << "testing transfer";
                transfer(user);
            case 4:
                cout << "testing logging out";
                logout();
                logged_on =false;
        }
    }
    return;
}

void UserFunctions::withdraw(User *user){

    int option; bool withdrawing = true;
    while (withdrawing) {
        cout << "*******************************\n";
        cout << "* 1 - Checkings    2 - Savings*\n";
        cout << "* 3 - Exit                    *\n";
        cout << "*******************************\n";
        cin >> option;

        switch (option) {
            case 1:
                int amount;
                cout <<"Enter Amount:  ";
                cin >> amount;
                user->depositCheck(amount, user);
                break;
            case 2:
                break;
            case 3:
                withdrawing = false;
                break;
        }

    }
    return;
}

void UserFunctions::deposit(User *user){

}

void UserFunctions::transfer(User *user){

}

void UserFunctions:: logout(){

}

void UserFunctions::findAccount(string f_name, User *user) {

    string line[100], the_line;


    ifstream customerFileR;
    customerFileR.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    if (customerFileR.is_open()) {
        cout << "it opened";
        while (!customerFileR.eof()) {

            getline(customerFileR, the_line);

            stringstream ssin(the_line);
            for (int i; ssin.good() && i < 7; i++) {
                ssin >> line[i];
            }
            if (line[1] == f_name){
                        break;
                }

        }

        string check = line[4], save = line[6];
        double checekr = stod(check);
        cout << checekr << "\n";
        double saver = stod(save);
        cout << saver;

        user->setFirstname(f_name);
        user->setLastname(line[2]);
        user->setChecking(checekr);
        user->setSaving(saver);

        customerFileR.close();

    }
    return;

}