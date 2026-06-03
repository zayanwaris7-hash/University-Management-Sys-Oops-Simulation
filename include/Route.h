/*
routeId
startPoint
endPoint
distance
assignedVehicle
assignVehicle()
displayRoute()
calculateDistance()
*/
#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include<windows.h>
#include "Bus.h"
#include "Van.h"
using namespace std;
class Route
{
protected:
    string routeId;
    string startPoint;
    string endPoint;
    double distance;
    Bus *assignedBus;
    Van *assignedVan;

public:
    Route() : routeId(""), startPoint(""), endPoint(""), distance(0.0), assignedBus(NULL), assignedVan(NULL) {}
    Route(string a, string b, string c, double d, Bus *e, Van *f) : routeId(a), startPoint(b), endPoint(c), distance(d), assignedBus(e), assignedVan(f) {}
    double calculateDistance() { return distance; }
    string getRouteId() { return routeId; }
    bool BookSeat(){
        if(assignedBus->getOccupiedSeat() == 0 ){
            cout<<"No Seat Is Availible !"<<endl;
            return false;
        }
        assignedBus->occuppiedSeat();
        return true;
    };

    Bus* getAssignedBus(){return assignedBus;}
    Van* getAssignedVan(){return assignedVan;}
    
    void diplayRoute()
    {
        cout << "========( ROUTE DISPLAY )========" << endl;
        cout << "Route ID     : " << routeId << endl;
        cout << "Start Point  : " << startPoint << endl;
        cout << "End Point    : " << endPoint << endl;
        cout << "Distance     : " << distance << " km" << endl;
        cout << "Bus Link : ";
        if (assignedBus != NULL){
            cout << "Bus Assigned : " << endl;
            assignedBus->displayVehicle();
        }else{ cout<<"No Bus Assined Yet ."<<endl;}
        cout << "Van Link : ";
         if (assignedVan != NULL){
            assignedVan->displayVehicle();
            cout << "Van Assigned : " << endl;
        }
        else{cout << "No Van Assigned To This Route yet ." << endl;}
    }
    void assignBus(Bus* bus){ 
        assignedBus=bus;
        cout<<"[SATAUS]  Bus Is Assigning To Route ( Id : "<<routeId<<" ) . ";
        Sleep(1500);
        cout<<". ";
        Sleep(1500);
        cout<<". ";
        Sleep(1500);
        cout<<". ";
        cout<<endl;
        cout<<"[STATUS] Succesfully Assigned "<<endl;
    }
    void assignVan(Van* Van){ 
        assignedVan=Van;
        cout<<"[SATAUS]  Van Is Assigning To Route ( Id : "<<routeId<<" ) . ";
        Sleep(1500);
        cout<<". ";
        Sleep(1500);
        cout<<". ";
        Sleep(1500);
        cout<<". ";
        cout<<endl;
        cout<<"[STATUS] Succesfully Assigned "<<endl;
    }
    void addinfo(string rId){
        routeId = rId;
        cout << "----------( Route Info )----------" << endl;
        cout << "Route ID assigned: " << routeId << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Start Point (City/Station): ";
        getline(cin, startPoint);
        cout << "Enter End Point (City/Station): ";
        getline(cin, endPoint);
        cout << "Enter Distance (in km): ";
        cin >> distance;
        while (cin.fail() || distance <= 0.0) {
            cout << "Invalid input! Distance must be a positive number.\nEnter Distance (in km): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> distance;
        }
        cout << "\n[SUCCESS] Route details saved successfully!" << endl;
    }
    ~Route() {}

};
#endif