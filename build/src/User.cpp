//
// Created by Owner on 2016-10-14.
//

#include "User.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>


User::User(){
        checking = 0.00;
        saving = 0.00;
        check = true;
        save = true;
    }


    User::User(string u_name, string p_name){
        username = u_name;
        password = p_name;
        checking = 0.00;
    }


    User::User(string u_name, string p_name, Type_user user){
        username = u_name;
        password = p_name;
        type_of_user = user;
        checking = 0.00;
        saving = 0.00;
    }



const string &User::getUsername() const {
    return username;
}
const string &User::getPassword() const {
    return password;
}
const string &User::getFirstname() const {
    return firstname;
}
const string &User::getLastname() const {
    return lastname;
}
User::Type_user User::getType_of_user() const {
    return type_of_user;
}

double User::isChecking() {
    double new_check = trunc_double(checking);
    return new_check;
}

double User::isSaving() {
    double new_save = trunc_double(saving);
    return new_save;
}



void User::SetUserType(int type){
    type_of_user = Type_user(type);
}
void User::setUsername(const string &username) {
    User::username = username;
}
void User::setPassword(const string &password) {
    User::password = password;
}
void User::setFirstname(const string &firstname) {
    User::firstname = firstname;
}
void User::setLastname(const string &lastname) {
    User::lastname = lastname;
}
void User::setType_of_user(User::Type_user type_of_user) {
    User::type_of_user = type_of_user;
}
void User::setChecking(double checking) {
    User::checking = checking;
}
void User::setSaving(double saving) {
    User::saving = saving;
}


void User::withdrawCheck(double amount, User *user, Activity *a) {
    double curr = user->isChecking();
    double new_amount = 0.00;
    int option =0;

    new_amount = trunc_double(curr - amount);

    if(user->check == false){
        cout <<"\n****You do not have a Checkings Account****\n";
        a->setTransact(false);
        return;
    }
    if(new_amount < 0){
        cout << "\n****Insufficient funds****\n";
        user->setChecking(curr);
        a->setTransact(false);
        return;
    }

    if(curr > 1000.00 && new_amount < 1000.00){

            cout << "**If you proceed you will be under the threshold of\n$1000.00, a $2.00 tax will be taken, ";
            cout << "procced?\n* 1 - I understand\n* Any Other button - Nevermind\n";
            option = getUserChoice();

            if (option == 1) {
                new_amount -= 2.00;
                if (new_amount < 0) {
                    cout << "Insufficient funds\n\n";
                    user->setChecking(curr);
                    a->setTransact(false);
                    cin.clear();
                    return;
                }
                user->setChecking(new_amount);
                a->setActivity("Withdraw from Checking: ");
                a->setAmount(amount);
                cout << "\nAfter transaction: " << user->isChecking();
                cin.clear();
                return;
            }
            else {

                user->setChecking(curr);
                a->setTransact(false);
                cin.clear();
                return;
            }

    }

    user->setChecking(new_amount);
    a->setActivity("Withdraw from Checking: ");
    a->setAmount(amount);
    a->setTransact(true);
    cout << "\nAfter transaction: " << user->isChecking();
    return;
}

void User::withdrawSave(double amount, User *user, Activity *a) {
    double curr = user->isSaving();
    double new_amount = 0.00;
    int option =0;

    new_amount = curr - amount;


    if(user->save == false){
        cout <<"\n****You do not have a Savings Account****\n";
        return;
    }

    if(new_amount < 0){
        cout << "\n****Insufficient funds****\n";
        user->setSaving(curr);
        return;
    }

    if(curr > 1000.00 && new_amount < 1000.00){

        cout << "**If you proceed you will be under the threshold of\n$1000.00, a $2.00 tax will be taken, ";
        cout << "procced?\n* 1 - I understand\n* Any Other button - Nevermind\n";
        option = getUserChoice();

        if (option == 1) {
            new_amount -= 2.00;
            if (new_amount < 0) {
                cout << "Insufficient funds\n\n";
                user->setSaving(curr);
                a->setTransact(false);
                cin.clear();
                return;
            }
            user->setSaving(new_amount);
            a->setActivity("Withdraw from Saving: ");
            a->setAmount(amount);
            cin.clear();
            return;
        }
        else {

            user->setSaving(curr);
            a->setTransact(false);
            cin.clear();
            return;
        }

    }

    user->setSaving(new_amount);
    a->setActivity("Withdraw from Saving: ");
    a->setAmount(amount);
    a->setTransact(true);
    cout << "\nAfter transaction: " << user->isSaving();
    return;
}

void User::depositCheck(double amount, User *user, Activity *a) {
    double curr = user->isChecking();
    double new_amount= 0.00;

    new_amount = curr + amount;
    user->setChecking(new_amount);
    a->setActivity("Deposited to Checking: ");
    a->setAmount(amount);
    a->setTransact(true);

    if(user->check == false){
        cout <<"\n****You do not have a Checkings Account****\n";
        a->setTransact(false);
        return;
    }

    cout << "\nNew Balance: " << user->isChecking();
    return;
}

void User::depositSave(double amount, User *user, Activity *a) {
    double curr = user->isSaving();
    double new_amount = 0.00;

    new_amount = curr + amount;
    user->setSaving(new_amount);
    a->setActivity("Deposited to Saving:");
    a->setAmount(amount);
    a->setTransact(true);

    if(user->save == false){
        cout <<"\n****You do not have a Savings Account****\n";
        a->setTransact(false);
        return;
    }

    if(user->check == false){
        cout <<"\n****You do not have a Checkings Account****\n";
        return;
    }

    cout << "\nNew Balance: " << user->isSaving();
    return;
}

void User::transferCtoS(double amount, User *user, Activity *a) {
    double currC = user->isChecking();
    double currS = user->isSaving();
    double new_amount = currC - amount;

    if(user->check == false){
        cout <<"\n****You do not have a Checkings Account****\n";
        a->setTransact(false);
        return;
    }

    if(new_amount<0){
        cout << "Insufficient funds\n";
        user->setChecking(currC);
        a->setTransact(false);
        return;
    }
    else {
        user->setChecking(new_amount);
        double new_save = currS + amount;
        double new_check = currC - amount;
        user->setSaving(new_save);
        user->setChecking(new_check);
        a->setActivity("Transfered to Savings");
        a->setAmount(amount);
        a->setTransact(true);
    }
    return;
}

void User::transferStoC(double amount, User *user, Activity *a) {
    double currC = user->isChecking();
    double currS = user->isSaving();
    double new_amount = currS - amount;

    if(user->save == false){
        cout <<"\n****You do not have a Savings Account****\n";
        a->setTransact(false);
        return;
    }

    if(new_amount<0){
        cout << "Insufficient funds\n";
        user->setSaving(currS);
        a->setTransact(false);
        return;
    }
    else {
        user->setSaving(new_amount);
        double new_check = currC + amount;
        double new_save = currS - amount;
        user->setSaving(new_save);
        user->setChecking(new_check);
        a->setActivity("Transfered to Checking");
        a->setAmount(amount);
        a->setTransact(true);
    }
    return;
}

void User::setCheck(bool val) {
    check = val;
}
void User::setSave(bool val) {
    save = val;
}
bool User::getCheck() {
    return check;
}
bool User::getSave() {
    return save;
}
int User::getUserChoice(){
    int choice =0;
    cin >> choice;
    return choice;
}

double User::trunc_double(double val){
    double temp =0.0;

    temp = (int) (val * pow(10,2));

    temp /= pow(10,2);

    return temp;
}
