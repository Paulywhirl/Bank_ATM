//
// Created by Owner on 2016-10-14.
//

#ifndef BANK_ATM_USER_H
#define BANK_ATM_USER_H
#include<string>

using namespace std;


class User {

public:
    string username, password;
    string firstname, lastname;
    enum Type_user {Customer, Manager, Administrator}type_of_user;
    double checking, saving;

public:
    User();
    User(string u_name, string p_name);
    User(string u_name, string p_name, Type_user user);


    const string &getUsername() const;
    const string &getPassword() const;
    const string &getFirstname() const;
    const string &getLastname() const;
    Type_user getType_of_user() const;
    bool isChecking() const;
    bool isSaving() const;
    void SetUserType(int type);

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setFirstname(const string &firstname);
    void setLastname(const string &lastname);
    void setType_of_user(Type_user type_of_user);
    void setChecking(double checking);
    void setSaving(double saving);
};



class Manager: public User{

public:
    Manager(string x, string p_word) : User(username, password){

    }



};

class Customer: public User{

public:
    Customer();

    Customer(string first, string last, double check, double save);

    void setUserInfo(string username, int lineNumber, Customer user);
};




#endif //BANK_ATM_USER_H
