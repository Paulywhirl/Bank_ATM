//
// Created by Owner on 2016-10-23.
//

#ifndef BANK_ATM_ACTIVITY_H
#define BANK_ATM_ACTIVITY_H
#include<string>
using namespace std;

class Activity {

public:
    string activity;
    double amount;
    bool transact;

    bool isTransact() const;

    void setTransact(bool transact);

public:
    Activity();

    void setActivity(const string &a);
    void setAmount(double);

    string getActivity();
    double getAmount();

};


#endif //BANK_ATM_ACTIVITY_H
