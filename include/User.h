#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;
class User{
    protected:
      string id;
      string password;
      string name;
      bool isLoggedIn;

    public:
     User():id(""),password(""),name(""),isLoggedIn(false){}
     User(string id,string password,string name,bool isLoggedIn){
        this->id=id;
        this->password=password;
        this->name=name;
        this->isLoggedIn=isLoggedIn;
     }
      virtual void menu()=0;
      virtual void display()=0;
      virtual string getRole()=0;
      virtual ~User(){};
};
#endif