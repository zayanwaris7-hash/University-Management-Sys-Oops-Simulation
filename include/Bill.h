/*generateBill()
applyFine()
payBill()
displayBill()*/
#ifndef BILL_H
#define BILL_H
#include<iostream>
#include<windows.h>

using namespace std;
class Bill{
    protected:
      string billId;
      float monthlyFee;
      float fine;
      bool paidStatus;
    public:
      Bill():billId(""),monthlyFee(0.0),fine(0.0),paidStatus(false){}
      Bill(string a,float b,float c,bool d):billId(a),monthlyFee(b),fine(c),paidStatus(d){}
      string getBill(){return billId;}
      float getMf(){return monthlyFee;}
      float getf(){return fine;}
      bool getpaidStatus(){return paidStatus;}
      void generateBill(string id,float fee){
          billId = id;
          monthlyFee = fee;
          fine = 0.0;
          paidStatus = false;
          cout<<"[STATUS] Bill is Genrating . ";
          Sleep(1500);
          cout<<". ";
          Sleep(1500);
          cout<<". ";
          Sleep(1500);
          cout<<". ";
          cout<<endl;
          cout << "Bill " << billId << " generated successfully.\n";
      };
      void applyFine(float fineAmount){
        if (!paidStatus) {
              fine += fineAmount;
              cout << "Fine of $" << fineAmount << " applied to Bill " << billId << ".\n";
          } else {
              cout << "Cannot apply fine. Bill " << billId << " is already paid.\n";
          }
      };
      void payBill(){
          if (!paidStatus) {
              paidStatus = true;
              cout << "Bill " << billId << " has been paid successfully.\n";
          } else {
              cout << "Bill " << billId << " was already paid.\n";
          }
      };
      void displayBill(){
        cout << "------- BILL DETAILS -------\n";
          cout << "Bill ID:     " << billId << "\n";
          cout << "Monthly Fee: ( " << monthlyFee << " _PKR )\n";
          cout << "Fine:        ( " << fine << " _PKR )\n";
          cout << "Total Due:   ( " << (monthlyFee + fine) << " _PKR )\n";
          cout << "Status:      " << (paidStatus ? "Paid" : "Unpaid") << "\n";
          cout << "----------------------------\n";
      };
      ~Bill(){}
     
};
#endif