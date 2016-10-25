//
// Created by Owner on 2016-10-14.
//

#ifndef BANK_ATM_USER_H
#define BANK_ATM_USER_H
#include<string>
#import "Activity.h"

using namespace std;


class User {

public:
    string username, password;
    string firstname, lastname;
    enum Type_user {Customer, Manager, Administrator}type_of_user;
    double checking, saving;
    bool check, save;

public:
    User();
    User(string u_name, string p_name);
    User(string u_name, string p_name, Type_user user);


    const string &getUsername() const;
    const string &getPassword() const;
    const string &getFirstname() const;
    const string &getLastname() const;
    Type_user getType_of_user() const;
    double isChecking();
    double isSaving();
    void SetUserType(int type);

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setFirstname(const string &firstname);
    void setLastname(const string &lastname);
    void setType_of_user(Type_user type_of_user);
    void setChecking(double checking);
    void setSaving(double saving);

    void setCheck(bool val);
    void setSave(bool val);
    bool getCheck();
    bool getSave();

    void withdrawCheck(double amount, User *user, Activity *a);
    void withdrawSave(double amount, User *user,Activity *a);

    void depositCheck(double amount, User *user, Activity *a);
    void depositSave(double amount, User *user, Activity *a);

    void transferCtoS(double amount, User *user, Activity *a);
    void transferStoC(double amount, User *user, Activity *a);

    int getUserChoice();

    double trunc_double(double val);
};




#endif //BANK_ATM_USER_H
