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


//********************************************************************************************************
void UserFunctions:: startUp(string f_name, int type) {

    User *user, current_user;
    user = &current_user;
    while (logged_on){


        if(type ==1) {
            findAccount(f_name, user);
            cout << "f: " << current_user.getFirstname();
            cout << "\nl: " << current_user.getLastname();
            cout << "\nc: " << setprecision(2) << fixed << current_user.isChecking();
            cout << "\ns: " << setprecision(2) << fixed << current_user.isSaving();
            customerMenu(user);

        }
        if(type ==2){
            managerMenu(user);
        }

    }
}
//********************************************************************************************************
void UserFunctions::managerMenu(User *user){
    do {
        int optionmenu;
        cout << "\n***********************************************\n";
        cout << "* 1 - Add Customer     2 - Delete Customer      *\n";
        cout << "* 3 - View Customer     4 - Logout       *\n";
        cout << "*************************************\n\n";
        optionmenu = getUserFChoice();

        switch (optionmenu) {
            case 1:
                addCustomer();
                cin.clear();
                break;
            case 2:
                deposit(user);
                break;
            case 3:
                transfer(user);
                break;
            case 4:
                logout(user);
                logged_on =false;
                break;
            default: {cout << "\nInvalid input\n"; break;}
        }
    }while (logged_on);
    return;
}
//********************************************************************************************************

void UserFunctions::addCustomer(){

}

void UserFunctions::deleteCustomer(){

}

void UserFunctions::viewCustomer(){
    
}

//********************************************************************************************************

void UserFunctions::customerMenu(User *user){

    do {
        int optionmenu;
        cout << "\n******************************************\n";
        cout << "* 1 - Withdraw     2 - Deposit             *\n";
        cout << "* 3 - Transfer     4 - Print Account       *\n";
        cout << "* 5 - Logout                               *\n";
        cout << "********************************************\n\n";
        optionmenu = getUserFChoice();

        switch (optionmenu) {
            case 1:
                withdraw(user);
                cin.clear();
                break;
            case 2:
                deposit(user);
                break;
            case 3:
                transfer(user);
                break;
            case 4:
                cout << "**************************" << endl;
                cout << "* Name: "<<line[0]+" "+line[1]+"*"<< endl;
                cout << "*Checking Account: " <<line[3]+"*"<< endl;
                cout << "*Savings Account: " <<line[5]+" *"<< endl;
                cout << "***************************" << endl;
                break;
            case 5:
                logout(user);
                logged_on =false;
                break;
            default: {cout << "\nInvalid input\n"; break;}
        }
    }while (logged_on);
    return;
}
//********************************************************************************************************

void UserFunctions::withdraw(User *user){

    int option;
    bool withdrawing = true;
    while (withdrawing) {
        cout << "*******************************\n";
        cout << "* 1 - Checkings    2 - Savings*\n";
        cout << "* 3 - Exit                    *\n";
        cout << "*******************************\n";
        option = getUserFChoice();

        switch (option) {
            case 1: {
                double amount;
                cout << "Enter Amount, must be whole number: ";
                cin >> amount;
                user->withdrawCheck(amount, user);
                cin.clear();
                withdrawing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount, must be whole number: ";
                cin >> amount;
                user->withdrawSave(amount, user);
                cin.clear();
                withdrawing=false;
                break;
            }
            case 3: {
                cin.clear();
                withdrawing = false;
                break;
            }
            default: {break;}
        }

    }
    return;
}
//********************************************************************************************************

void UserFunctions::deposit(User *user){
    int option;
    bool depositing = true;
    while (depositing) {
        cout << "*******************************\n";
        cout << "* 1 - Checkings    2 - Savings*\n";
        cout << "* 3 - Exit                    *\n";
        cout << "*******************************\n";
        option = getUserFChoice();

        switch (option) {
            case 1: {
                double amount;
                cout << "Enter Amount to deposit, must be whole number: ";
                cin >> amount;
                user->depositCheck(amount, user);
                cin.clear();
                depositing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount to deposit:  ";
                cin >> amount;
                user->depositSave(amount, user);
                cin.clear();
                depositing=false;
                break;
            }
            case 3: {
                cin.clear();
                depositing = false;
                break;
            }
            default: {break;}
        }

    }
    return;
}
//********************************************************************************************************

void UserFunctions::transfer(User *user){
    int option;
    bool depositing = true;
    while (depositing) {
        cout << "*******************************\n";
        cout << "* 1 - Checkings to Savings    *\n";
        cout << "* 2 - Savings to Checkings    *\n";
        cout << "* 3 - Exit                    *\n";
        cout << "*******************************\n";
        option = getUserFChoice();

        switch (option) {
            case 1: {
                double amount;
                cout << "Enter Amount to transfer:  ";
                cin >> amount;
                user->transferCtoS(amount, user);
                cin.clear();
                depositing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount to transfer:  ";
                cin >> amount;
                user->transferStoC(amount, user);
                cin.clear();
                depositing=false;
                break;
            }
            case 3: {
                cin.clear();
                depositing = false;
                break;
            }
            default: {break;}
        }

    }
    return;
}
//********************************************************************************************************

void UserFunctions:: logout(User *user){

    double check = user->isChecking();
    double save = user->isSaving();
    stringstream Scheck, Ssave;
    Scheck << fixed << setprecision(2) << check;
    string c = Scheck.str();
    Ssave << fixed << setprecision(2) << save;
    string s = Ssave.str();

    string new_line = user->getFirstname() + " " + user->getLastname()
    + " checking " + c + " saving " + s;

    string replace_line = line[0] + " " + line[1] + " " + line[2] + " " + line[3] + " " + line[4] + " " + line[5];

    cout << new_line;

    ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    ofstream Fileout("temporary");

    if(!Filein || !Fileout){
        cout << "Error updating profile due to files missing or files not opening";
        return;
    }

    string line;
    while(!Filein.eof()){
        getline(Filein, line);
        if(replace_line == line){
            Fileout << new_line << endl;
        }
        else{
            Fileout << line << endl;
        }
    }

    Filein.close();
    Fileout.close();

    rewrite();
    return;
}
//********************************************************************************************************

void UserFunctions::rewrite() {
    ofstream Filechange("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    ifstream Filetemp("temporary");

    if(!Filechange || !Filetemp){
        cout << "Error updating profile due to files missing or files not opening";
        return;
    }

    string line_to_change;
    while(!Filechange.eof()) {
        getline(Filetemp, line_to_change);
        Filechange << line_to_change << endl;
        if(line_to_change == ""){
            break;
        }
    }

    Filechange.close();
    Filetemp.close();

    ofstream ofs;
    ofs.open("temporary", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    return;
}
//********************************************************************************************************


void UserFunctions::findAccount(string f_name, User *user) {

    string the_line;
    int i=0;

    ifstream customerFileR;
    customerFileR.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    if (customerFileR.is_open()) {
        cout << "it opened";
        while (!customerFileR.eof()) {

            getline(customerFileR, the_line);

            stringstream ssin(the_line);
            while (ssin.good() && i < 8) {
                ssin >> line[i];
                ++i;
            }
            if (line[0] == f_name){
                        break;
                }
            i=0;
        }

        string check = line[3], save = line[5];
        double checekr = stod(check);
        cout << checekr << "\n";
        double saver = stod(save);
        cout << saver;

        user->setFirstname(f_name);
        user->setLastname(line[1]);
        user->setChecking(checekr);
        user->setSaving(saver);

        customerFileR.close();

    }
    return;

}
//********************************************************************************************************

int UserFunctions::getUserFChoice(){
    int choice =0;
    cin >> choice;
    return choice;
}