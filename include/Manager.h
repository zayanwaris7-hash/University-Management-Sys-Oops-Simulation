#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<vector>
#include"Admin.h"
#include"Student.h"
#include"Route.h"
#include"Bus.h"
#include"Van.h"
#include"TransportationPass.h"
using namespace std;
class Manager{
    protected:
    Admin* admin;
    vector<Student*> users;
    vector<Van*> Vans;
    vector<Bus*> Buses;
    vector<Route*> routes;
    vector<TransportationPass*> passes;
    public:
     Manager():admin(NULL),users(),Vans(),Buses(),routes(),passes(){}
     Manager( Admin* a):admin(a),users(),Vans(),Buses(),routes(),passes(){}
     ~Manager(){
       delete admin;
       for (size_t i = 0; i < users.size(); i++) {
           delete users[i];
       }    
       for (size_t i = 0; i < Vans.size(); i++) {
           delete Vans[i];
       }    
       for (size_t i = 0; i < Buses.size(); i++) {
           delete Buses[i];
       }    
       for (size_t i = 0; i < routes.size(); i++) {
           delete routes[i];
       }    
       for (size_t i = 0; i < passes.size(); i++) {
           delete passes[i];
       }
     }
};
#endif