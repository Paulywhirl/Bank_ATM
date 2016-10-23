#include <iostream>
#include <string.h>
#include <fstream>
#include "User.h"
#include "UserFunctions.h"
#include <sstream>
using namespace std;
#define SIZE 100

int main() {


    bool user = false, user_type = false;
    int type, i = 0, back;
    string u_name, p_word, firstname;
    string uInfo[SIZE], the_line;
    User new_user;
    UserFunctions Menu;
    ifstream infile;

    cout << "\nWelcome to your ATM machine!" << endl;

    do {

        cout << endl << "Please indicate your user-type:" << endl;
        cout << "1 - Customer\n2 - Manager\n" << endl;
        cin >> type;

        if (!(type == 1 || type == 2)) {
             cout << "Error: Not a User Type!" << endl;
        }else{
            new_user.setType_of_user((User::Type_user) type);
        }


        cout << "Please enter User credentials" << endl;

        while (!user) {

            if (type == 1) {
                cout << "Username: ";
                cin >> u_name;
                cout << "\nPassword: ";
                cin >> p_word;

                infile.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Customers");
                if (infile.is_open()) {
                    while (infile) {

                        getline(infile, the_line);

                        stringstream ssin(the_line);
                        while (ssin.good() && i < 3) {
                            ssin >> uInfo[i];
                            ++i;
                        }

                        if (uInfo[0] == u_name) {

                            if (uInfo[1] == p_word) {
                                cout << "\nyou're in\n";
                                user = true;
                                firstname = uInfo[2];
                                infile.close();

                                ofstream log("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\log");
                                string this_person = uInfo[2]+" "+uInfo[3];
                                log << this_person << endl;

                                
                                Menu = *new UserFunctions();
                                Menu.startUp(firstname, type);

                                break;
                            }
                            break;
                        }

                        i = 0;
                        if(infile.eof()){
                            break;
                        }
                    }
                    if (!user) {
                        infile.close();
                        cout << "***Incorrect Username or Password***\n\nGo Home?\n1-back\n0-stay\n";
                        cin >> back;

                        if (back == 1) {
                            type =0;
                            break;
                        }
                    }else{
                        infile.close();
                    }

                } else {
                    cout << "file could not open\n";
                }
            }
            if(type ==2){
                cout << "Username: ";
                cin >> u_name;
                cout << "\nPassword: ";
                cin >> p_word;

                infile.open("C:\\Users\\Owner\\Documents\\Third Year\\Comp Sci 3307\\Bank_ATM\\build\\res\\Managers");
                if (infile.is_open()) {
                    while (infile) {

                        getline(infile, the_line);

                        stringstream ssin(the_line);
                        while (ssin.good() && i < 3) {
                            ssin >> uInfo[i];
                            ++i;
                        }

                        if (uInfo[0] == u_name) {

                            if (uInfo[1] == p_word) {
                                cout << "\nyou're in\n";
                                user = true;
                                firstname = uInfo[2];
                                //infile.close();
                                Menu = *new UserFunctions();
                                Menu.startUp(firstname, type);

                                break;
                            }
                            break;
                        }

                        i = 0;
                        if(infile.eof()){
                            break;
                        }
                    }
                    if (!user) {
                        infile.close();
                        cout << "\n***Incorrect Username or Password***\n\nGo Home?\n1-back\n0-stay\n";
                        cin >> back;

                        if (back == 1) {
                            type =0;
                            break;
                        }
                    }else{
                        infile.close();
                    }

                } else {
                    cout << "file could not open\n";
                }
            }
        }
        user=false;
    }while (!user_type);


        /*cout << "Username: ";
        cin >> new_user.username;
        cout << "\nPassword: ";
        cin >> new_user.password;

         cout << "\n*************************************\n";
                        cout << "* 1 - Withdraw     2 - Deposit      *\n";
                        cout << "* 3 - Transfer     4 - Logout       *\n";
                        cout << "*************************************\n\n";
                        cin >> option;

                        new_user.setUserInfo(firstname, lineNumber, new_user);
                        cout << "firstname: " << new_user.getFirstname();
                        cout << "\nlastname: " << new_user.getLastname();
                        cout << "\ncheckings: " << new_user.isChecking();
                        cout << "\nsavings: " << new_user.isSaving();

         UserFunctions();

    void startup(string f_name, int type);
    void customerMenu();
    void managerMenu();
    void withdraw();
    void deposit();
    void transfer();
    void logout();


*/

        return 0;

}
