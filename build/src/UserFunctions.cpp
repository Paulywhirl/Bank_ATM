//
// Created by Owner on 2016-10-21.
//

#include "UserFunctions.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "User.h"
#include "Activity.h"
#include "Account.h"

UserFunctions::UserFunctions() {}

//**********************************************************************************************

void UserFunctions:: startUp(string f_name, int type) {

    User *user, current_user;
    user = &current_user;
    while (logged_on){


        if(type ==1) {
            findAccount(f_name, user);
            customerMenu(user);

        }
        if(type ==2){
            managerMenu(user);
        }
        if(type == 3){
            adminMenu();
        }

    }
}

void UserFunctions::adminMenu(){
    do {
        int optionmenu;
        cout << "\n*************************************\n";
        cout << "* 1 - View Customers Log              *\n";
        cout << "* 2 - View Managers Log               *\n";
        cout << "* 2 - Logout                          *\n";
        cout << "*************************************\n\n";
        cout << "\nOption number: ";
        optionmenu = getUserFChoice();

        switch(optionmenu){
            case 1:
                viewCLog();
                break;
            case 2:
                viewMLog();
                break;
            case 3:
                logged_on = false;
                break;
            default:
                cout << "*Invalid input"<< endl;
        }
    }while(logged_on);
}

void UserFunctions::viewCLog(){

    string line;
    ifstream Log("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\CustomersLog");

    cout<<"*********************************"<<endl;
    while(Log){
        getline(Log, line);
        if(line == ""){
            break;
        }
        cout <<"*"<<line<<endl;
        if(Log.eof()){
            break;
        }
    }
    cout<<"*********************************"<<endl;
    return;
}

void UserFunctions::viewMLog(){

    string line;
    ifstream Log("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\ManagersLog");

    cout<<"*********************************"<<endl;
    while(Log){
        getline(Log, line);
        if(line == ""){
            break;
        }
        cout <<"*"<<line<<endl;
        if(Log.eof()){
            break;
        }
    }
    cout<<"*********************************"<<endl;
    return;
}

//**********************************************************************************************

void UserFunctions::managerMenu(User *user){
    do {
        int optionmenu;
        cout << "\n***********************************************\n";
        cout << "* 1 - Add Customer     2 - Delete Customer      *\n";
        cout << "* 3 - Add Account      4 - Delete Account       *\n";
        cout << "* 5 - View Customer    6 - Logout              *\n";
        cout << "*************************************************\n\n";
        cout << "\nOption number: ";
        optionmenu = getUserFChoice();

        switch (optionmenu) {
            case 1:
                addCustomer();
                cin.clear();
                break;
            case 2:
                deleteCustomer();
                break;
            case 3:
                addAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                viewCustomer();
                break;
            case 6:
                logged_on =false;
                break;
            default: {cout << "\nInvalid input\n"; break;}
        }
    }while (logged_on);
    return;
}


void UserFunctions::addCustomer(){

    bool adding = true;
    string acc_info[6], user_info[4];
    string info, password;


    cout << "******************************************" << endl;
    cout << "*You are about to add a customer, type \"exit\" \nat anytime to quit this process." <<endl;
    cout << "********************************************" <<endl;

    while(adding) {
        cout << "Customer First Name: ";
        cin >> info;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info.length() > 15) {
            cout << endl << "*First name too long" << endl;
        }
        else {
            acc_info[0] = info;
            user_info[2] = info;
            adding = false;
        }
    }
    adding =true;
    while(adding){
        cout << "\nCustomer Last Name: ";
        cin >> info;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info.length() > 23) {
            cout << endl << "\n*Last name too long" << endl;
        }
        else{
            acc_info[1] = info;
            user_info[3] = info;
            adding = false;
        }
    }
    adding=true;
    while(adding){
        cout << "answer yes or no" << endl;
        cout << "Does the Customer having a Checking account: ";
        cin >> info;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info == "yes") {
            acc_info[2] = "checking";
            cout << "\nHow much have they deposited in this account: ";
            cin >> info;
            acc_info[3] = info;
            adding =false;
        }
        if(info == "no"){
            acc_info[2] = "checking";
            acc_info[3] = "no";
            adding = false;
        }
    }
    adding=true;
    while(adding){
        cout << "answer yes or no" << endl;
        cout << "Does the Customer having a Savings account: ";
        cin >> info;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info == "yes") {
            acc_info[4] = "saving";
            cout << "\nHow much have they deposited in this account: ";
            cin >> info;
            acc_info[5] = info;
            adding=false;
        }
        if(info == "no"){
            acc_info[4] = "saving";
            acc_info[5] = "no";
            adding = false;
        }
    }
    adding=true;
    while(adding){
        cout << "\n(Must be unique and equal to 7 in length)";
        cout << "\n*Customer Username: ";
        cin >> info;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info.length() != 7) {
            cout << endl << "*Not valid" << endl;
        }
        else {
            user_info[0] = info;
            adding = false;
        }
    }
    adding=true;
    while(adding){
        cout << "\n*Customer Password: ";
        cin >> info;
        cout << "\nPassword Comfirmation: ";
        cin >> password;
        if (info == "exit") {
            adding = false;
            return;
        }
        if (info != password) {
            cout << endl << "Not the same password" << endl;
        }
        else {
            user_info[1] = info;
            adding = false;
        }
    }

    string user1 = user_info[0] +" "+ user_info[1]+" "+user_info[2]+" "+user_info[3];
    string user = acc_info[0]+" "+acc_info[1]+" "+acc_info[2]+" "+acc_info[3]+" "+acc_info[4]+" "+acc_info[5];

    cout << "********************"<<endl;
    cout << "*Is this information correct"<<endl;
    cout << "First Name: " <<acc_info[0] <<endl;
    cout << "Last Name: "<<acc_info[1]<<endl;
    cout << "Checking: "<<acc_info[3]<<endl;
    cout << "Saving: "<<acc_info[5]<<endl;
    cout << "Username: "<<user_info[0]<<endl;
    cout << "Password: "<<acc_info[1]<<endl;
    cout << "********************"<<endl;

    adding =true;
    do {
        cout << "\n yes or no:";
        cin >> info;
        if (info == "yes") {

            ofstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info", std::ios_base::app | std::ios_base::out);
            Filein << user + "\n";
            Filein.close();

            ofstream Filein1("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers", std::ios_base::app | std::ios_base::out);
            Filein1<< user1 + "\n";
            Filein1.close();
            break;
        }
        if (info == "no") {
            return;
        }
    }while(adding);

return;

}

void UserFunctions::deleteCustomer(){

    string user, uInfo[4], aInfo[6];
    string line;
    bool deleting = true;
    int i=0;

    do{
        cout<<"*********************************"<<endl;
        cout<<"*You are about to delete a customer form our records"<<endl;
        cout<<"*This Customer will no longer be able to use our machines"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"*Remember that the Customer must have no funds in order to be delted"<<endl;
        cout<<"**********************************"<<endl;

        cout<<"* Please enter Customers username: ";
        cin >> user;

        ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
        if (Filein.is_open()) {
            while (Filein) {

                getline(Filein, line);
                if (line == "") {
                    cout << "This username is not in our records" << endl;
                    Filein.close();
                    break;
                }


                stringstream ssin(line);
                while (ssin.good() && i < 4) {
                    ssin >> uInfo[i];
                    ++i;
                }
                i=0;

                if (uInfo[0] == user) {
                    Filein.close();
                    int j=0;
                    string this_line;
                    ifstream AccFile(
                            "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
                    while (AccFile) {

                        getline(AccFile, this_line);
                        stringstream ssin2(this_line);
                        while (ssin2.good() && j < 7) {
                            ssin2 >> aInfo[j];
                            ++j;
                        }
                        j=0;
                        if (aInfo[0] == uInfo[2]) {
                            if(aInfo[3] == "no"|| aInfo[3] == "0.00" || aInfo[3] == "0"){
                                if(aInfo[5] == "no"|| aInfo[5] == "0.00" || aInfo[5] == "0"){
                                    AccFile.close();
                                    confirmDelete(aInfo, uInfo);
                                    deleting =false;
                                }
                            }
                            else{
                                cout<<"The user has money in their accounts!!"<<endl;
                                cout<<"CANNOT DELETE THIS RECORD!"<<endl;
                                AccFile.close();
                                deleting=false;
                                break;
                            }

                        }

                    }
                }
            }
            deleting = false;
            //cout <<"\nCould not find username in records"<<endl;
        }

    }while(deleting);
}

void UserFunctions::confirmDelete(string a[], string b[]){

    string replace_line = a[0]+" "+a[1]+" "+a[2]+" "+a[3]+" "+a[4]+" "+a[5]+"\r";
    string replace_line1 = b[0]+" "+b[1]+" "+b[2]+" "+b[3]+"\r";

    ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    ofstream Fileout("temporary");

    if(!Filein || !Fileout){
        cout << "Error updating profile due to files missing or files not opening";
        return;
    }

    string line;
    while(!Filein.eof()){
        getline(Filein, line);
        if(replace_line != line){
            Fileout << line << endl;
        }
        if(line ==""){
            break;
        }
    }

    Filein.close();
    Fileout.close();
    rewrite(1);

    Filein.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
    Fileout.open("temporary");
    if(!Filein || !Fileout){
        cout << "Error updating profile due to files missing or files not opening";
        return;
    }
    while(!Filein.eof()){
        getline(Filein, line);
        if(replace_line1 != line){
            Fileout << line << endl;
        }
    }

    Filein.close();
    Fileout.close();
    rewrite(2);
    cout <<"\nUser deleted successfully"<<endl;
    return;

}

void UserFunctions::addAccount(){
    string user;
    int account;

    do {
        cout << "************************" << endl;
        cout << "*Please type the username of the account you wish to add." << endl;
        cout << "*Username: ";
        cin >> user;
        cout << "\n*Account to add" << endl;
        cout << " 1 - Checking  2 - Saving" << endl;
        account = getUserFChoice();

        if(account == 1 || account == 2){
            Account *acc = new Account(user, account);
            acc->addAcc();
            break;
        }

    }while(true);

    rewrite(1);
    cout << "\n*Successfully added account"<<endl;
    return;

}

void UserFunctions::deleteAccount(){
    string user;
    int account;

    do {
        cout << "************************" << endl;
        cout << "*Please type the username of the account you wish to close." << endl;
        cout << "*Username: ";
        cin >> user;
        cout << "\n*Account to close" << endl;
        cout << " 1 - Checking  2 - Saving" << endl;
        account = getUserFChoice();

        if(account == 1 || account == 2){
            Account *acc = new Account(user, account);
            acc->deleteAcc();
            break;
        }

    }while(true);

    rewrite(1);
    cout << "\n*Successfully closed account"<<endl;
    return;

}

void UserFunctions::viewCustomer() {

    string user, uInfo[4], aInfo[6];
    int option, i = 0, j = 0;
    bool keep_going = true;
    cout << "*************************************" << endl;
    cout << "* 1 - View one Customer" << endl;
    cout << "* 2 - View all customers" << endl;
    cout << "* 3 - Exit back to menu" << endl;
    cout << "*************************************" << endl;
    cin >> option;

    if (option == 1) {
        cout << "\nEnter the username of the client you wish to view: ";
        cin >> user;
        ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
        if (Filein.is_open()) {
            string line;
            while (keep_going) {

                getline(Filein, line);
                if (line == "") {
                    cout << "This username is not in our records" << endl;
                    break;
                }

                stringstream ssin(line);
                while (ssin.good() && i < 4) {
                    ssin >> uInfo[i];
                    ++i;
                }
                i = 0;

                if(user == uInfo[0]) {
                    int j = 0;
                    string this_line;
                    ifstream AccFile(
                            "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");

                    while (AccFile) {

                        getline(AccFile, this_line);
                        stringstream ssin2(this_line);
                        while (ssin2.good() && j < 7) {
                            ssin2 >> aInfo[j];
                            ++j;
                        }
                        j = 0;
                        if (aInfo[0] == uInfo[2]) {
                            AccFile.close();
                            cout << "************************" << endl;
                            cout << "First Name: " << aInfo[0] << endl;
                            cout << "Last Name: " << aInfo[1] << endl;
                            cout << "Checking: " << aInfo[3] << endl;
                            cout << "Saving: " << aInfo[5] << endl;
                            cout << "Username: " << uInfo[0] << endl;
                            cout << "Password: " << uInfo[1] << endl;
                            cout << "********************" << endl;
                            keep_going = false;
                            break;
                        }
                    }
                }

            }
            Filein.close();

        }
    }
    if(option==2){
        ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
        if (Filein.is_open()) {
            string line;
            while (Filein) {

                getline(Filein, line);
                if (line == "") {
                    Filein.close();
                    break;
                }

                stringstream ssin(line);
                while (ssin.good() && i < 4) {
                    ssin >> uInfo[i];
                    ++i;
                }
                i = 0;

                string this_line;
                ifstream AccFile(
                        "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
                bool acc = true;
                while (acc) {

                    getline(AccFile, this_line);
                    stringstream ssin2(this_line);
                    while (ssin2.good() && j < 7) {
                        ssin2 >> aInfo[j];
                        ++j;
                    }
                    j = 0;
                    if(uInfo[2] == aInfo[0]) {
                        cout << "************************" << endl;
                        cout << "First Name: " << aInfo[0] << endl;
                        cout << "Last Name: " << aInfo[1] << endl;
                        cout << "Checking: " << aInfo[3] << endl;
                        cout << "Saving: " << aInfo[5] << endl;
                        cout << "Username: " << uInfo[0] << endl;
                        cout << "Password: " << uInfo[1] << endl;
                        cout << "********************" << endl;
                        cout << endl;
                        AccFile.close();
                        acc =false;
                    }
                }
            }
            Filein.close();

        }
    }
    if (option == 3){
        return;
    }

    return;
}

//**********************************************************************************************

void UserFunctions::customerMenu(User *user){

    do {
        int optionmenu;
        Activity *customer, cust;
        customer = &cust;
        cout << "\n******************************************\n";
        cout << "* 1 - Withdraw     2 - Deposit             *\n";
        cout << "* 3 - Transfer     4 - Print Account       *\n";
        cout << "* 5 - Logout                               *\n";
        cout << "********************************************\n\n";
        cout << "\nOption number: ";
        optionmenu = getUserFChoice();

        switch (optionmenu) {
            case 1:
                withdraw(user, customer);
                cin.clear();
                break;
            case 2:
                deposit(user, customer);
                break;
            case 3:
                transfer(user, customer);
                break;
            case 4:
                //** ID - view Customer **//
                cout << "**************************" << endl;
                cout << "*Name: "<<line[0]+" "+line[1]+"*"<< endl;
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

        string amt = trunc_double(customer->getAmount());
        string trace;
        if(customer->isTransact()) {
            trace = customer->getActivity() + " " + amt + " ";
        }
        if(!logged_on){
            trace = "\n";
        }
        ofstream log(
                "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\CustomersLog"
                , ios_base::app | ios_base::out);
        log <<  " " + trace;
        log.close();
        customer = new Activity;

    }while (logged_on);
    return;
}


void UserFunctions::withdraw(User *user, Activity *active){

    int option;
    bool withdrawing = true;
    while (withdrawing) {
        cout << "\n";
        cout << "*******************************\n";
        cout << "* 1 - Checkings    2 - Savings*\n";
        cout << "* 3 - Exit                    *\n";
        cout << "*******************************\n";
        cout << "\nOption number: ";
        option = getUserFChoice();

        switch (option) {
            case 1: {
                double amount;
                cout << "Enter Amount, must be whole number: ";
                cin >> amount;
                trunc_double(amount);
                user->withdrawCheck(amount, user, active);
                cin.clear();
                withdrawing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount, must be whole number: ";
                cin >> amount;
                user->withdrawSave(amount, user, active);
                cin.clear();
                withdrawing=false;
                break;
            }
            case 3: {
                cin.clear();
                withdrawing = false;
                break;
            }
            default: {cout << "\nInvalid input\n";break;}
        }

    }
    return;
}


void UserFunctions::deposit(User *user, Activity *active){
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
                user->depositCheck(amount, user, active);
                cin.clear();
                depositing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount to deposit:  ";
                cin >> amount;
                user->depositSave(amount, user, active);
                cin.clear();
                depositing=false;
                break;
            }
            case 3: {
                cin.clear();
                depositing = false;
                break;
            }
            default: {cout << "\nInvalid input\n";break;}
        }

    }
    return;
}


void UserFunctions::transfer(User *user, Activity *active){
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
                user->transferCtoS(amount, user, active);
                cin.clear();
                depositing = false;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount to transfer:  ";
                cin >> amount;
                user->transferStoC(amount, user, active);
                cin.clear();
                depositing=false;
                break;
            }
            case 3: {
                cin.clear();
                depositing = false;
                break;
            }
            default: {cout << "\nInvalid input\n";break;}
        }

    }
    return;
}


void UserFunctions:: logout(User *user){

    double check = user->isChecking();
    double save = user->isSaving();
    stringstream Scheck, Ssave;
    Scheck << fixed << setprecision(2) << check;
    string c = Scheck.str();
    Ssave << fixed << setprecision(2) << save;
    string s = Ssave.str();

    string new_line = user->getFirstname() + " " + user->getLastname()
    + " checking " + c + " saving " + s + "\r";

    string replace_line = line[0] + " " + line[1] + " " + line[2] + " " + line[3] + " " + line[4] + " " + line[5] + "\r";


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

    rewrite(1);
    return;
}


void UserFunctions::rewrite(int i) {
    ofstream Filechange;
    if(i ==1) {
        Filechange.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
    }
    else{
        Filechange.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
    }
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
        if (check == "no" && save == "no"){
            user->setFirstname(f_name);
            user->setLastname(line[1]);
            user->setCheck(false);
            user->setSave(false);
            customerFileR.close();
            return;
        }
        if (check == "no"){
            user->setFirstname(f_name);
            user->setLastname(line[1]);
            double saver = stod(save);
            user->setSaving(saver);
            user->setCheck(false);
            customerFileR.close();
            return;
        }
        if (save == "no"){
            user->setFirstname(f_name);
            user->setLastname(line[1]);
            double checekr = stod(check);
            user->setSaving(checekr);
            user->setSave(false);
            customerFileR.close();
            return;
        }

        double checekr = stod(check);
        double saver = stod(save);
        user->setFirstname(f_name);
        user->setLastname(line[1]);
        user->setChecking(checekr);
        user->setSaving(saver);

        customerFileR.close();

    }
    return;

}


int UserFunctions::getUserFChoice(){
    int choice =0;
    cin >> choice;
    return choice;
}

string UserFunctions::trunc_double(double val) {
    stringstream s;
    s << fixed << setprecision(2) << val;
    string res = s.str();

    size_t dotIndex = res.find(".");

    string final_res = res.substr(0, dotIndex + 9);


    return final_res;
}
