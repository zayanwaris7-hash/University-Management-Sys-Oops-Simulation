/*approvePass()
rejectPass()
displayPass()*/
#ifndef TRAPORTATION_H
#define TRAPORTATION_H
#include<iostream>
#include<windows.h>
#include"Student.h"
#include"Route.h"

#include"Bill.h"
using namespace std;
class TransportationPass{
    protected:
     string passId;
     Student* student;
     Route* route;
     string status;
     Bill* bill;
    public:
     TransportationPass():passId(""),student(NULL),route(NULL),status("rejected"),bill(NULL){}
     TransportationPass(string a,Student* b,Route* c,string f,Bill* g):passId(a),student(b),route(c),status(f),bill(g){}
     string getStudId(){return student->getId();}
     string getRouteId(){return route->getRouteId();}
     string getBillId(){return bill->getBill();}
     string getPassId(){return passId;}
     string getstatus(){return status;}
     bool getPStatus(){return bill->getpaidStatus();}
     float getMontlyFees(){return bill->getMf();}
     float getFine(){return bill->getf();}
     void approvePass(){
        char choice;
        cout<<"Are U Sure U Want To Approve The Pass | Id : "<<passId<<" | (Y for Yes /N for No) : ";
        cin.get(choice);
        choice=toupper(choice);
        while(cin.fail()|| choice == '\n' || (choice!='Y' && choice !='N')){
            if (cin.fail()) {
                cin.clear();
            }
            if (choice != '\n') {
                cin.ignore(10000, '\n');
            }
            cout << "Invalid input! Please enter ONLY 'Y' or 'N': ";
            cin.get(choice);
            choice = toupper(choice);
        }
        cin.ignore(10000, '\n');
        if(choice=='Y'){
            bool cond =route->BookSeat();
            if(cond){
            status="approved";
            if(route->getAssignedBus()!=NULL){
                route->getAssignedBus()->occuppiedSeat();
            }
            if(route->getAssignedVan()!=NULL){
                route->getAssignedVan()->occuppiedSeat();
            }
            cout<<"[STATUS] Processing . ";
            Sleep(1500);
            cout<<". ";
            Sleep(1500);
            cout<<". ";
            cout<<endl;
            cout<<"[STATUS] Succesfully Approved !"<<endl;
            }else{
                cout<<"[STATUS] Failed Approved ! (Seats are full)"<<endl;
            }
        }else{
            cout<<"[STATUS] Not Approved Yet."<<endl;
        }
     }
     void rejectPass() {
        char choice;
        cout << "Are U Sure U Want To Reject The Pass | Id : " << passId << " | (Y for Yes /N for No) : ";
        
        cin.get(choice);
        choice = toupper(choice);
        
        while (cin.fail() || choice == '\n' || (choice != 'Y' && choice != 'N')) {
            if (cin.fail()) {
                cin.clear();
            }
            if (choice != '\n') {
                cin.ignore(10000, '\n');
            }
            cout << "Invalid input! Please enter ONLY 'Y' or 'N': ";
            cin.get(choice);
            choice = toupper(choice);
        }
        cin.ignore(10000, '\n');

        if (choice == 'Y') {
            status = "rejected";
            cout << "[STATUS] Processing . ";
            Sleep(1000);
            cout << ". \n";
            cout << "[STATUS] Pass has been Rejected." << endl;
        } else {
            cout << "[STATUS] Rejection Cancelled." << endl;
        }
     }
     void displayPass() {
        cout << " Pass ID     : " << passId << "\n";
        cout << " Pass Status : " << status << "\n";
        if (student != NULL) {
            cout << " --- Student Information --- \n";
            cout<<"Student Id : "<<student->getId()<<endl;
        } else {
            cout << " Student Info: No student assigned.\n";
        }
        if (route != NULL) {
            cout << " --- Route Information --- \n";
            cout<<"Route Id : "<<route->getRouteId()<<endl;
        } else {
            cout << " Route Info  : No route assigned.\n";
        }
        if (bill != NULL) {
            cout << " --- Billing Information --- \n";
            bill->displayBill(); 
        } else {
            cout << " Billing Info: No bill generated yet.\n";
        }
        cout << "============================================\n\n";
     }
     ~TransportationPass(){}
};
#endif