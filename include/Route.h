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

    void diplayRoute()
    {
        cout << "========( ROUTE DISPLAY )========" << endl;
        cout << "Route ID     : " << routeId << endl;
        cout << "Start Point  : " << startPoint << endl;
        cout << "End Point    : " << endPoint << endl;
        cout << "Distance     : " << distance << " km" << endl;
        cout << "Bus Link : ";
        if (assignedBus != NULL){
            cout << "Bus Assigned" << endl;
            assignedBus->displayVehicle();
        }else{ cout<<"No Bus Assined Yet ."<<endl;}
        cout << "Van Link : ";
         if (assignedVan != NULL){
            assignedVan->displayVehicle();
            cout << "Van Assigned" << endl;
        }
        else{cout << "No Van Assigned To This Route yet ." << endl;}
    }

    ~Route() {}
};
#endif