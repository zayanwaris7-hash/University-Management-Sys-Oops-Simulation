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
using namespace std;
class Student:public User{
    protected:
     string registrationNumber;
     string passId;
    public:
      Student():registrationNumber(""),passId(""){}
      //------------------------------------------
      Student(string a,string b,string c,bool d,string e,string f):User(a,b,c,d),registrationNumber(e),passId(f){}
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
      string getPassId(){return passId;}
      void login(){isLoggedIn=true;}
      void logout(){isLoggedIn=false;}
      string getregistrationNumber(){return registrationNumber;}
      //-------------------------------------
      string getRole()override{ return "student";}
      void setPass(string b){passId=b;}
      //----------------------------------------------------

    
      //---------------------------------------------------------------
      void menu()override{
           
      }
      
      ~Student()override{}
};
#endif