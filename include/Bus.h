/*
virtual bool checkAvailability()=0;
 virtual void displayVehicle()=0;
     virtual string getType()=0;
     virtual float Fee()=0;
      string vehicleId;
    string vehicleNumber;
    int capacity;
    int occupiedSeats;
    string assignedRoute;
    bool isAvailible;
    float fee;*/
#ifndef BUS_H
#define BUS_H
#include <iostream>
#include "Vehicle.H"
#include<limits>
using namespace std;
class Bus : public Vehicle
{
protected:
    bool wifiAvailable;

public:
    Bus() : wifiAvailable(false) {}
    Bus(string a, string b, int c, int d, string e, float f, bool h) : Vehicle(a, b, c, d, e, f), wifiAvailable(h) {}

    string getType() override { return "bus"; }
    float Fee() override { return fee; }
    bool checkAvailability() override { return isAvailible; }

    void displayVehicle() override
    {
        cout << "========( BUS DISPLAY )========" << endl;
        cout << "Bus Id         : " << vehicleId << endl;
        cout << "Bus Number     : " << vehicleNumber << endl;
        cout << "Cpacity        : " << capacity << endl;
        cout << "Reserved Seats : " << occupiedSeats << endl;
        cout << "Assigned Route : " << assignedRoute << endl;
        cout << "Availible      : " << (isAvailible ? "Yes" : "No") << endl;
        cout << "Fees Per Seat  : " << fee << endl;
        cout << "Wifi Availible : " << (wifiAvailable ? "Yes" : "No") << endl;
        return;
    }

    Bus &AddInfo()
    {
        cout << "========( Bus Info )========" << endl;
        cout << "Enter Bus Id (eg B01) : ";
        cin >> vehicleId;
        cout << endl;
        cout << "Enter Bus Number : ";
        cin >> vehicleNumber;
        cout << endl;
        cout << "Enter Capacity in Bus : ";
        cin >> capacity;
        while (cin.fail() || cin.peek() == '.' || capacity < 30 ||  capacity > 50)
        {
            cout << "Invalid ! Capacity Must be in between (30-50)\n Enter Capcity : " << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cin >> capacity;
        }
        cout<<endl;
        cout << "Enter Reserved Seat in Bus : ";
        cin >> occupiedSeats;
        while (cin.fail() || cin.peek() == '.' || capacity < occupiedSeats ||  occupiedSeats<0)
        {
            cout << "Invalid ! Capacity is "<<capacity<<"\n Enter Reserved Seat : " << endl;
            
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
        cout<<"Is Wifi Availible (Y/N) : "<<endl;
        cin>>ans;
        while(cin.fail() || ans!='y' || ans!='n' || ans!='Y' || ans!='N'){
            cout<<"Inavlid ! Enter in (Y or y/N or n) : ";
             cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> ans;
        }
        if(ans=='Y' ||ans=='y') wifiAvailable=true;
        else  wifiAvailable=false;
       
        return *this;
    }

    ~Bus() override {}
};
#endif