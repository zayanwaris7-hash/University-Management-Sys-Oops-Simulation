#ifndef VAN_H
#define VAN_H
#include<iostream>
#include"Vehicle.H"
#include<limits>
using namespace std;
class Van:public Vehicle{
    protected:
     bool isAirCondAvailable;
    public:
     Van():isAirCondAvailable(false){}
     Van(string a, string b,int c,int d,string e,float f,bool h):Vehicle(a,b,c,d,e,f),isAirCondAvailable(h){}
     
     string getType()override{return "van";}
     float Fee()override{return fee;}
     bool checkAvailability()override{return isAvailible;}
      
     void displayVehicle()override{
         cout<<"========( Van DISPLAY )========"<<endl;
         cout<<"Van Id         : "<<vehicleId<<endl;
         cout<<"Van Number     : "<<vehicleNumber<<endl;
         cout<<"Cpacity        : "<<capacity<<endl;
         cout<<"Reserved Seats : "<<occupiedSeats<<endl;
         cout<<"Assigned Route : "<<assignedRoute<<endl;
         cout<<"Availible      : "<<(isAvailible?"Yes":"No")<<endl;
         cout<<"Fees Per Seat  : "<<fee<<endl; 
         cout<<"Wifi Availible : "<<(isAirCondAvailable?"Yes":"No")<<endl;
         return;
     }
     

     Van &AddInfo()
    {
        cout << "========( Van Info )========" << endl;
        cout << "Enter Van Id (eg B01) : ";
        cin >> vehicleId;
        cout << endl;
        cout << "Enter Van Number : ";
        cin >> vehicleNumber;
        cout << endl;
        cout << "Enter Capacity in Van : ";
        cin >> capacity;
        while (cin.fail() || cin.peek() == '.' || capacity < 30 ||  capacity > 50)
        {
            cout << "Invalid ! Capacity Must be in between (30-50)\n Enter Capcity : " << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cin >> capacity;
        }
        cout<<endl;
        cout << "Enter Reserved Seat in Van : ";
        cin >> occupiedSeats;
        while (cin.fail() || cin.peek() == '.' || capacity < occupiedSeats ||  occupiedSeats<0)
        {
            cout << "Invalid ! Capacity is "<<capacity<<"\n Enter Reserved Seats : " << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cin >> occupiedSeats;
        }
        cout << endl;
        cout<<"Enter route Id To Assined : ";
        cin>>assignedRoute;
        cout << endl;
        cout<<"Enter Fees Per Seat : ";
        cin>>fee;
        while(cin.fail())
        {
            cout<<"Inavlid ! (Fees Price Must Be In float .)\nEnter Fees Per Seat : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> fee;
        }
        cout << endl;
        char ans;
        cout<<"Is Air condition Availible (Y/N) : "<<endl;
        cin>>ans;
        while(cin.fail() || ans!='y' || ans!='n' || ans!='Y' || ans!='N'){
            cout<<"Inavlid ! Enter in (Y or y/N or n) : ";
             cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> ans;
        }
        if(ans=='Y' ||ans=='y') isAirCondAvailable=true;
        else  isAirCondAvailable=false;
       
        return *this;
    }

   

     ~Van()override{}
};
#endif