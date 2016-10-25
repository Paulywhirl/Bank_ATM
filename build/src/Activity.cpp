//
// Created by Owner on 2016-10-23.
//

#include "Activity.h"
#include<string>
using namespace std;

Activity::Activity(){
    amount = 0.00;
    transact = false;
}


void Activity::setActivity(const string &activity) {
    Activity::activity = activity;
}

void Activity::setAmount(double amount){
    Activity::amount = amount;
}


string Activity::getActivity(){
    return activity;
}

double Activity::getAmount(){
    return amount;
}

bool Activity::isTransact() const {
    return transact;
}

void Activity::setTransact(bool transact) {
    Activity::transact = transact;
}
