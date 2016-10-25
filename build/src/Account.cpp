//
// Created by Owner on 2016-10-24.
//

#include "Account.h"
#include <fstream>
#include <sstream>
#include <iostream>

Account::Account(string u_name, int a){
    user = u_name;
    acc = a;
}


void Account::addAcc(){

    string aInfo[6], uInfo[4];
    string line, c, s;
    bool ct = false; bool st = false;
    int i=0;
    ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
    if (Filein.is_open()) {
        while (Filein) {

            getline(Filein, line);
            if (line == "") {
                cout << "\n*This username is not in our records" << endl;
                Filein.close();
                break;
            }


            stringstream ssin(line);
            while (ssin.good() && i < 4) {
                ssin >> uInfo[i];
                ++i;
            }
            i = 0;

            if (uInfo[0] == user) {
                Filein.close();
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
                        if (acc == 1) {
                            if (aInfo[3] != "no") {
                                cout << "\n**User already has a Checkings Account!!" << endl;
                            } else {
                                aInfo[3] = "0.00";
                                c = "no";
                                ct = true;
                            }
                        }
                        if (acc == 2) {
                            if (aInfo[5] != "no") {
                                cout << "\n**User already has a Savings Account!!" << endl;
                            } else {
                                aInfo[5] = "0.00";
                                s = "no";
                                st = true;
                            }
                        }
                        if (ct || st) {
                            string replace_line =
                                    aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + aInfo[3] + " " + aInfo[4] + " " +
                                    aInfo[5] + "\r";
                            string curr_line;
                            if(ct){
                                curr_line = aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + "no" + " " + aInfo[4] + " " +
                                            aInfo[5] + "\r";
                            }
                            if(st){
                                curr_line = aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + aInfo[3] + " " + aInfo[4] + " " +
                                            "no" + "\r";
                            }
                            ifstream Filein1(
                                    "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
                            ofstream Fileout("temporary");

                            if (!Filein1 || !Fileout) {
                                cout << "Error updating profile due to files missing or files not opening";
                                return;
                            }

                            string line1;
                            while (!Filein1.eof()) {
                                getline(Filein1, line1);
                                if (curr_line == line1) {
                                    Fileout << replace_line << endl;
                                }
                                else{
                                    Fileout << line1 <<endl;
                                }
                                if (line1 == "") {
                                    break;
                                }
                            }

                            Filein.close();
                            Fileout.close();
                        }
                    }
                }
                return;
            }
            }
        }
    }

void Account::deleteAcc(){
    string aInfo[6], uInfo[4];
    string line, c, s;
    bool ct = false; bool st = false;
    int i=0;
    ifstream Filein("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
    if (Filein.is_open()) {
        while (Filein) {

            getline(Filein, line);
            if (line == "") {
                cout << "\n*This username is not in our records" << endl;
                Filein.close();
                break;
            }


            stringstream ssin(line);
            while (ssin.good() && i < 4) {
                ssin >> uInfo[i];
                ++i;
            }
            i = 0;

            if (uInfo[0] == user) {
                Filein.close();
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
                        if (acc == 1) {
                            if (aInfo[3] != "0.00") {
                                cout << "\n**User may have money in account or already doesn't have one!!" << endl;
                            } else {
                                aInfo[3] = "no";
                                c = "0.00";
                                ct = true;
                            }
                        }
                        if (acc == 2) {
                            if (aInfo[5] != "0.00") {
                                cout << "\n**User may have money in account or already doesn't have one!!" << endl;
                            } else {
                                aInfo[5] = "no";
                                s = "0.00";
                                st = true;
                            }
                        }
                        if (ct || st) {
                            string replace_line =
                                    aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + aInfo[3] + " " + aInfo[4] + " " +
                                    aInfo[5] + "\r";
                            string curr_line;
                            if(ct){
                                curr_line = aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + "0.00" + " " + aInfo[4] + " " +
                                            aInfo[5] + "\r";
                            }
                            if(st){
                                curr_line = aInfo[0] + " " + aInfo[1] + " " + aInfo[2] + " " + aInfo[3] + " " + aInfo[4] + " " +
                                            "0.00" + "\r";
                            }
                            ifstream Filein1(
                                    "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Acc_Info");
                            ofstream Fileout("temporary");

                            if (!Filein1 || !Fileout) {
                                cout << "Error updating profile due to files missing or files not opening";
                                return;
                            }

                            string line1;
                            while (!Filein1.eof()) {
                                getline(Filein1, line1);
                                if (curr_line == line1) {
                                    Fileout << replace_line << endl;
                                }
                                else{
                                    Fileout << line1 <<endl;
                                }
                                if (line1 == "") {
                                    break;
                                }
                            }

                            Filein.close();
                            Fileout.close();
                            break;
                        }
                    }
                }
                return;
            }
        }
    }
}