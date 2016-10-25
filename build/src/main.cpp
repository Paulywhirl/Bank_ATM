#include <iostream>
#include <string.h>
#include <fstream>
#include "User.h"
#include "UserFunctions.h"
#include <sstream>
#import <ctime>
using namespace std;

string getDateTime();

int main() {


    bool user = false, user_type = false;
    int type, i = 0, back;
    string u_name, p_word, firstname;
    string uInfo[5], the_line;
    User new_user;
    UserFunctions Menu;
    ifstream infile;

    cout << "\nWelcome to your ATM machine!" << endl;

    do {

        while (true) {
            cout << endl << "Please indicate your user-type:" << endl;
            cout << "1 - Customer\n2 - Manager\n3 - Administrator\n4 - Shutdown\n*User number: ";
            cin >> type;

            if (!(type == 1 || type == 2 || type == 3 || type == 4)) {
                cout << "\n\n***Error: Not a User Type!****" << endl;
            } else {
                new_user.setType_of_user((User::Type_user) type);
                break;
            }

            cout << "Please enter User credentials" << endl;
        }

        while (!user) {

            if (type == 1) {
                cout << "Username: ";
                cin >> u_name;
                cout << "\nPassword: ";
                cin >> p_word;

                infile.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
                if (infile.is_open()) {
                    while (true) {

                        getline(infile, the_line);

                        stringstream ssin(the_line);
                        while (ssin.good() && i < 4) {
                            ssin >> uInfo[i];
                            ++i;
                        }
                        i=0;
                        if (uInfo[0] == u_name) {

                            if (uInfo[1] == p_word) {
                                cout << "\nyou're in! Welcome!\n";
                                user = true;
                                firstname = uInfo[2];
                                infile.close();

                                ofstream log(
                                        "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\CustomersLog"
                                        , ios_base::app | ios_base::out);

                                string d_t = getDateTime();
                                string this_person = uInfo[2] + " " + uInfo[3] + " " +d_t;
                                log << "*" + this_person +" ";
                                log.close();

                                Menu = *new UserFunctions();
                                Menu.startUp(firstname, type);

                                break;
                            }
                            break;
                        }

                        i = 0;
                        if (infile.eof()) {
                            infile.close();
                            break;
                        }
                    }
                    if (!user) {
                        infile.close();
                        cout << "***Incorrect Username or Password***\n\nGo Home?\n1-back\n0-stay\n";
                        cin >> back;

                        if (back == 1) {
                            type = 0;
                            break;
                        }
                    } else {
                        infile.close();
                    }

                } else {
                    cout << "file could not open\n";
                }
            }
            if (type == 2) {
                cout << "Username: ";
                cin >> u_name;
                cout << "\nPassword: ";
                cin >> p_word;

                infile.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Managers");
                if (infile.is_open()) {
                    while (true) {

                        getline(infile, the_line);

                        stringstream ssin(the_line);
                        while (ssin.good() && i < 4) {
                            ssin >> uInfo[i];
                            ++i;
                        }

                        if (uInfo[0] == u_name) {

                            if (uInfo[1] == p_word) {
                                cout << "\nyou're in\n";
                                user = true;
                                firstname = uInfo[2];

                                ofstream log(
                                        "C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\ManagersLog"
                                                , ios_base::app | ios_base::out);

                                string d_t = getDateTime();
                                string this_person = uInfo[2] + " " + uInfo[3] + " " +d_t;
                                log << this_person << endl;
                                log.close();

                                Menu = *new UserFunctions();
                                Menu.startUp(firstname, type);


                                break;
                            }
                            break;
                        }

                        i = 0;
                        if (infile.eof()) {
                            break;
                        }
                    }
                    if (!user) {
                        infile.close();
                        cout << "\n***Incorrect Username or Password***\n\nGo Home?\n1-back\n0-stay\n";
                        cin >> back;

                        if (back == 1) {
                            type = 0;
                            break;
                        }
                    } else {
                        infile.close();
                    }

                } else {
                    cout << "file could not open\n";
                }
            }
            if(type == 3){
                cout << "Username: ";
                cin >> u_name;
                cout << "\nPassword: ";
                cin >> p_word;

                infile.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Administrators");
                if (infile.is_open()) {
                    while (infile) {

                        getline(infile, the_line);

                        stringstream ssin(the_line);
                        while (ssin.good() && i < 4) {
                            ssin >> uInfo[i];
                            ++i;
                        }

                        if (uInfo[0] == u_name) {

                            if (uInfo[1] == p_word) {
                                cout << "\nyou're in\n";
                                user = true;
                                firstname = uInfo[2];
                                infile.close();

                                Menu = *new UserFunctions();
                                Menu.startUp(firstname, type);

                                break;
                            }
                            break;
                        }

                        i = 0;
                        if (infile.eof()) {
                            break;
                        }
                    }
                    if (!user) {
                        infile.close();
                        cout << "***Incorrect Username or Password***\n\nGo Home?\n1-back\n0-stay\n";
                        cin >> back;

                        if (back == 1) {
                            type = 0;
                            break;
                        }
                    } else {
                        infile.close();
                    }

                } else {
                    cout << "file could not open\n";
                }
            }
            if (type == 4){
                return 0;
            }
        }
        user = false;
    } while (!user_type);
}

string getDateTime(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
    string str(buffer);

    return str;

};