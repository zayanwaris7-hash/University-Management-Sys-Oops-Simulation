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
#include"Manager.h"
#include"TransportationPass.h"
Manager m;
using namespace std;
class Student:public User{
    protected:
     string registrationNumber;
     TransportationPass* pass;
    public:
      Student():registrationNumber(""){}
      //------------------------------------------
      Student(string a,string b,string c,bool d,string e):User(a,b,c,d),registrationNumber(e),pass(){}
        //----------------------------------------------------------------------------------------------
      void display()override{
        cout<<"====( Profile )===="<<endl;
        cout<<" Name     : "<<name<<endl;
        cout<<" Id       : "<<id<<endl;
        cout<<" Password : "<<password<<endl;
        cout<<" Registratition Number : "<<registrationNumber<<endl;
        return;
      }
      string getId(){return id;}
      string getPassword(){return password;}
      string getFullName(){return name;}
      void login(){isLoggedIn=true;}
      void logout(){isLoggedIn=false;}
      //-------------------------------------
      string getRole()override{ return "student";}
      //----------------------------------------------------
      void  ViewRoute(Manager m){
         
      }
      //------------------------------------------------
       void ApplyTransport(Manager m){

      }
      //-----------------------------------
      
      void ViewRegistration(Manager m){

      }
      //---------------------------------------
      void CancelRegistration(Manager m){

      }
      //--------------------------------------
      void Logout(Manager m){

      }
    
      //---------------------------------------------------------------
      void menu()override{
             int choice;
             do{
                cout<<"=======( STUDENT MENU )======="<<endl;
                cout<<"1. View Routes\n2. Apply Transport\n3. View Registration\n4. Cancel Registration\n5. Display Profile\n6. Logout\n "<<endl;
                cin>>choice;
                 while (cin.fail() || cin.peek() == '.'|| choice<1 || choice>6)
                {
                cout << "Invalid Choice ! ( 1 to 7)  "<<endl;;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
                }
                if(choice==1) ViewRoute(m);
                else if(choice==2) ApplyTransport(m);
                else if(choice==3) ViewRegistration(m);
                else if(choice==4) CancelRegistration(m);
                else if(choice==5) display();
               // else if(choice==6) Logout(m);
             }while(choice!=6);
      }
      
      ~Student()override{}
};
#endif