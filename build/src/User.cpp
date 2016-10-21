//
// Created by Owner on 2016-10-14.
//

#include "User.h"
#include <sstream>
#include <fstream>


    User::User(){
    }


    User::User(string u_name, string p_name){
    username = u_name;
    password = p_name;
    }


    User::User(string u_name, string p_name, Type_user user){
    username = u_name;
    password = p_name;
    type_of_user = user;
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
bool User::isChecking() const {
    return checking;
}
bool User::isSaving() const {
    return saving;
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

//*************************************************************************************//


//*************************************************************************************//

Customer::Customer(){
}

Customer::Customer(string first, string last, double check, double save){
        firstname = first;
        lastname = last;
        checking = check;
        saving = save;

}

/*void Customer::setUserInfo(string f_name, int lineNumber, Customer user){


    string line[100], the_line;
    ifstream customerFileR;
    customerFileR.open("Customers");
    if(customerFileR.is_open()) {
        cout << "it opened"
        for(int i;i<=lineNumber; i++){
            getline(customerFileR, the_line);
        }
        stringstream ssin(the_line);
        for (int i; ssin.good() && i < 7; i++) {
            ssin >> line[i];
        }
        user.setFirstname(f_name);
        user.setLastname(line[1]);
        user.setChecking(stod(line[3]));
        user.setSaving(stod(line[5]));


    }
        customerFileR.close();

}*/

