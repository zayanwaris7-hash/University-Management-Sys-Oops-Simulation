/*

*/
#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <limits>
#include "User.h"
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

    string getEmail(){return id;}
    string getPassword(){return password;}
    string getRole() override { return role; }
    void login(){isLoggedIn=true;}
    void logout(){isLoggedIn=false;}
    //--------------------------------
    
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
      
    }
    ~Admin() override {}
};
#endif