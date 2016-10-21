//
// Created by Owner on 2016-10-21.
//

#include "UserFunctions.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "User.h"

UserFunctions::UserFunctions() {}

void UserFunctions:: startUp(string f_name, int type) {

    
    while (logged_on){


        if(type ==1) {
            User current_user = findAccount(f_name);
            cout << "third\n";
            cout << "f: \n" << current_user.getFirstname();
            cout << "l: \n" << current_user.getLastname();
            cout << "c: \n" << current_user.isChecking();
            cout << "s: \n" << current_user.isSaving();
        }
        if(type ==2){

        }
        logged_on=false;
    }
}

User UserFunctions::findAccount(string f_name) {

    string line[100], the_line;
    User customer;

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
            if (line[0] == f_name){
                        break;
                }
        }

        customer.setFirstname(f_name);
        customer.setLastname(line[1]);
        customer.setChecking(stod(line[3]));
        customer.setSaving(stod(line[5]));

    }

    return customer;
}