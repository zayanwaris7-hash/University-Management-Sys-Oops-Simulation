/*viewRoutes()
applyTransport()
viewRegistration()
cancelRegistration()
menu()
display()
getRole()*/
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<windows.h>
#include <limits>
#include"User.h"
#include"TransportationPass.h"
using namespace std;
class Student:public User{
    protected:
     string registrationNumber;
     TransportationPass* pass;
    public:
      Student():registrationNumber(""){}
      Student(string a,string b,string c,bool d,string e):User(a,b,c,d),registrationNumber(e){}
    
      void display()override{
        cout<<"====( Profile )===="<<endl;
        cout<<" Name     : "<<name<<endl;
        cout<<" Id       : "<<id<<endl;
        cout<<" Password : "<<password<<endl;
        cout<<" Registratition Number : "<<registrationNumber<<endl;
        return;
      }
      string getRole()override{ return "student";}

      void menu(){
             int choice;
             do{
                cout<<"=======( STUDENT MENU )======="<<endl;
                cout<<"1. View Routes\n2. Apply Transport\n3. View Registration\n4. Cancel Registration\n5. Display Profile\n6. Logout "<<endl;
                cin>>choice;
                 while (cin.fail() || cin.peek() == '.')
                {
                cout << "Invalid Choice ! ( 1 to 6)  "<<endl;;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
                }
               // if(choice==1) ViewRoute();
               // else if(choice==2) ApplyTransport();
               // else if(choice==1) ViewRegistration();
               // else if(choice==1) CancelRegistration();
              //  else if(choice==1) display();
               // else if(choice==1) Logout();
             }while(choice!=6);
      }
      ~Student()override{}
};
#endif