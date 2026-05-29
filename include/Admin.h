/*
addVehicle()
editVehicle()
removeVehicle()
addRoute()
assignVehicleToRoute()
approveRequest()
rejectRequest()
viewApplications()
generateReports()
saveData()
menu()
display()
getRole()
*/
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <limits>
#include "User.h"
#include "Manager.h"
Manager m;
using namespace std;
class Admin : public User
{
protected:
    string role;

public:
    Admin() : role("Support") {}
    Admin(string a, string b, string c, bool d, string e) : User(a, b, c, d), role(e) {}
    void display() override
    {
        cout << "====( Profile )====" << endl;
        cout << " Name     : " << name << endl;
        cout << " Id       : " << id << endl;
        cout << " Password : " << password << endl;
        cout << " Role     : " << role << endl;
        return;
    }
    string getRole() override { return role; }
    //--------------------------------
    void addVehicle(Manager m){}
    //--------------------------------------------------
    void editVehicle(Manager m){}
    //---------------------------------
    void removeVehicle(Manager m){}
    //--------------
    void addRoute(Manager m){}
    //----------------------
    void assignVehicleToRoute(Manager m){}
    //--------------------------------------------
    void approveRequest(Manager m){}
    //---------------------------------
    void rejectRequest(Manager m){}
    //----------------------------------------
    void viewApplications(Manager m){}
    //-----------------------------
    void generateReports(Manager m){}
    //---------------------------------------------------------------
    void saveToFile(){}
    //-------------
    void changePassword()
    {
        string userid, pass, npass, cpass;
        bool cond = true;

        do
        {
            cout << "\n--- Change Password Protocol ---" << endl;
            cout << "Enter Your Login id (or enter '0' to cancel): ";
            cin >> userid;
            if (userid == "0")
            {
                cout << "[cANCELLED] Returning to menu..." << endl;
                return;
            }
            cout << "Enter Your Current Password: ";
            cin >> pass;
            if (userid == id)
            {
                if (pass == password)
                {
                    do
                    {
                        cout << "Enter Your New Password: ";
                        cin >> npass;
                        cout << "Enter Again to Confirm: ";
                        cin >> cpass;

                        if (npass != cpass)
                        {
                            cout << "[ERROR] Passwords Mismatch. Try Again!\n"
                                 << endl;
                        }
                    } while (npass != cpass);
                    password = npass;
                    cout << "[STATUS] Password Updated Successfully!" << endl;
                    cond = false;
                }
                else
                {
                    cout << "[ERROR] Invalid Password. Try Again!\n"
                         << endl;
                }
            }
            else
            {
                cout << "[ERROR] Invalid Credentials. Try Again!\n"
                     << endl;
            }
        } while (cond);
    }
    //---------------------------------------
    void menu() override
    {
        int choice;
        do
        {
            cout << "\n=========================================" << endl;
            cout << "            ADMIN MENU DASHBOARD         " << endl;
            cout << "=========================================" << endl;
            cout << "1.  Add New Fleet Vehicle" << endl;
            cout << "2.  Edit Existing Vehicle Details" << endl;
            cout << "3.  Remove Vehicle Unit from Fleet" << endl;
            cout << "4.  Create New Transit Route" << endl;
            cout << "5.  Assign Available Vehicle to Route" << endl;
            cout << "6.  View Pending Transport Applications" << endl;
            cout << "7.  Approve Transport Request Application" << endl;
            cout << "8.  Reject Transport Request Application" << endl;
            cout << "9.  Generate Financial & Usage Reports" << endl;
            cout << "10. View My Admin Account Profile" << endl;
            cout << "11. Change Profile Account Password" << endl;
            cout << "12. Save Current System State Records" << endl;
            cout << "13. Terminate Session & Logout" << endl;
            cout << "=========================================" << endl;
            cout << "Enter your command index selection (1-13): ";
            cin >> choice;
            while (cin.fail() || cin.peek() == '.' || choice < 1 || choice > 13)
            {
                cout << "Invalid Choice ! ( 1 to 13)  " << endl;
                ;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
            if (choice == 1)
                addVehicle(m);
            else if (choice == 2)
                editVehicle(m);
            else if (choice == 3)
                removeVehicle(m);
            else if (choice == 4)
                addRoute(m);
            else if (choice == 5)
                assignVehicleToRoute(m);
            else if (choice == 6)
                approveRequest(m);
            else if (choice == 7)
                rejectRequest(m);
            else if (choice == 8)
                viewApplications(m);
            else if (choice == 9)
                generateReports(m);
            else if (choice == 10)
                display();
            else if (choice == 11)
                changePassword();
            else if (choice == 12)
                saveToFile();
        } while (choice != 13);
    }
    ~Admin() override {}
};
#endif