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
    User findAccount(string);


public:

    UserFunctions();

    void startUp(string f_name, int type);
    void customerMenu();
    void managerMenu();
    void withdraw();
    void deposit();
    void transfer();
    void logout();


};


#endif //BANK_ATM_USERFUNCTIONS_H
