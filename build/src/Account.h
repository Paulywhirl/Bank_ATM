//
// Created by Owner on 2016-10-24.
//

#ifndef BANK_ATM_ACCOUNTS_H
#define BANK_ATM_ACCOUNTS_H

#include <string>
using namespace std;

class Account {

public:
    string user;
    int acc; //1 - Checking, 2 - Saving

public:
    Account(string, int);

    void addAcc();

    void deleteAcc();
};


#endif //BANK_ATM_ACCOUNTS_H
