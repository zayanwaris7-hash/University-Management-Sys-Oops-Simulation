/*calculateFee()
checkAvailability()
displayVehicle()
getType()*/
#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
using namespace std;

class Vehicle{
    protected: 
    string vehicleId;
    string vehicleNumber;
    int capacity;
    int occupiedSeats;
    string assignedRoute;
    bool isAvailible;
    float fee;
    public:
     Vehicle():vehicleId(""),vehicleNumber(""),capacity(0),occupiedSeats(0),assignedRoute(""),isAvailible(false),fee(0.0){}
     Vehicle(string a, string b,int c,int d,string e,float f):vehicleId(a),vehicleNumber(b),capacity(c),occupiedSeats(d),assignedRoute(e),isAvailible(true),fee(f){}
     virtual bool checkAvailability()=0;
     virtual void displayVehicle()=0;
     virtual string getType()=0;
     virtual float Fee()=0;
     virtual ~Vehicle(){}
};
#endif