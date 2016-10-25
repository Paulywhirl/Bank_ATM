//
// Created by Owner on 2016-10-21.
//

#ifndef BANK_ATM_USERFUNCTIONS_H
#define BANK_ATM_USERFUNCTIONS_H
#include <sstream>
#include <fstream>
#include <string>
#include "User.h"

class UserFunctions {

private:
    bool logged_on = true;
    void findAccount(string, User *user);
    string line[10];



public:

    UserFunctions();

    void startUp(string f_name, int type);

    void managerMenu(User *user);
    void addCustomer();
    void deleteCustomer();
    void addAccount();
    void deleteAccount();
    void confirmDelete(string[], string[]);
    void viewCustomer();

    void customerMenu(User *user);
    void withdraw(User *user, Activity *active);
    void deposit(User *user, Activity *active);
    void transfer(User *user, Activity *active);
    void logout(User *user);

    void adminMenu();
    void viewCLog();
    void viewMLog();

    int getUserFChoice();
    void rewrite(int i);

    string trunc_double(double);

};


#endif //BANK_ATM_USERFUNCTIONS_H
