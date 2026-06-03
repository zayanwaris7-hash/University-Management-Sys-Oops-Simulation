#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <windows.h>
#include "Admin.h"
#include "Student.h"
#include "Route.h"
#include "Bus.h"
#include "Van.h"
#include "TransportationPass.h"
using namespace std;
class Manager
{
protected:
    Admin *admin;
    vector<Student *> users;
    vector<Van *> Vans;
    vector<Bus *> Buses;
    vector<Route *> routes;
    vector<TransportationPass *> passes;

public:
    Manager() : admin(NULL), users(), Vans(), Buses(), routes(), passes() {}
    Manager(Admin *a) : admin(a), users(), Vans(), Buses(), routes(), passes() {}
    bool isEmailIsCorrect(string email)
    {
        if ((email.find('@') == string::npos))
        {
            return false;
        }

        if ((email.find("@gmail.com") != string::npos) || (email.find("@yahoo.com") != string::npos))
        {
            return true;
        }

        return false;
    }
    //--------------------------
    bool isEmailIsDuplicated(string email)
    {
        if (users.size() != 0)
        {
            for (size_t i = 0; i < users.size(); i++)
            {
                if (users[i]->getId() == email)
                {
                    return true;
                }
            }
        }
        return false;
    }
    //-----------------------------------------------------------------------------
    bool isBusIdDup(string a)
    {
       
            for (size_t i = 0; i < Buses.size(); i++)
            {
                if (Buses[i]->getId() == a)
                {
                    return true;
                }
            }
            return false;
        
    }
    //-----------------------
    string toLowerString(string data)
    {
        transform(data.begin(), data.end(), data.begin(), [](unsigned char c)
                  { return tolower(c); });
        return data;
    }
    //--------------
    bool isVanIdDup(string a)
    {
            for (size_t i = 0; i < Vans.size(); i++)
            {
                if (Vans[i]->getId() == a)
                {
                    return true;
                }
            }
            return false;
        
    }
    void registerStudent()
    {
        string email, password, fullName, regNo, ss;
        int s, r;
        cout << "----------( Sign Up Details )----------" << endl;
        do
        {
            cout << "Enter your email : ";
            cin >> email;
            if (!isEmailIsCorrect(email))
                cout << "Invalid Email Must Include ( @gamil.com , @yahoo.com) : " << endl;
            if (isEmailIsDuplicated(email))
                cout << "Email Alerady Exist ! Try with Other Email : ";
        } while (!isEmailIsCorrect(email) || isEmailIsDuplicated(email));
        cout << endl;
        cout << "Enter Password (max 8 characters): ";
        cin >> password;
        while (cin.fail() || password.length() > 8)
        {
            cout << "Invalid password! Must be 8 characters or less: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> password;
            cout << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Enter Your full name : ";
        getline(cin, fullName);
        cout << endl;
        cout << "Enter Session Number (2024 to 2026) : ";
        cin >> s;
        while (cin.fail() || s < 2024 || s > 2026)
        {
            cout << "Invalid session! Must be between 2024 to 2026 :\nEnter Session Number (2024 to 2026) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> s;
            cout << endl;
        }
        cout << endl;
        cout << "Enter your Domain (SE-CS-AI-CE-CYS-DS) : ";
        cin >> ss;
        while (cin.fail() || (ss != "se" && ss != "SE" && ss != "se" && ss != "SE" && ss != "cs" && ss != "CS" && ss != "CE" && ss != "ce" && ss != "AI" && ss != "ai" && ss != "CYS" && ss != "cys" && ss != "DS" && ss != "ds"))
        {
            cout << "Invalid domain! \nEnter your Domain (SE-CS-AI-CE-CYS-DS) : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> ss;
            cout << endl;
        }
        cout << endl;
        cout << "Enter your roll Number : ";
        cin >> r;
        while (cin.fail())
        {
            cout << "Invalid Roll Number ! \nEnter your roll Number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> r;
            cout << endl;
        }
        regNo = to_string(s) + "-" + ss + to_string(r);
        Student *studPtr = new Student(email, password, fullName, false, regNo);
        users.push_back(studPtr);
    }
    //-------------------------------
    string login(string email, string password)
    {
        if (admin != NULL)
        {
            if (admin->getEmail() == email && admin->getPassword() == password)
            {
                cout << "Welcome Back, Admin!\n"
                     << endl;
                admin->login();
                return "Admin";
            }
        }
        for (size_t i = 0; i < users.size(); i++)
        {
            if (users[i]->getId() == email && users[i]->getPassword() == password)
            {
                cout << "Login Successful! Welcome, " << users[i]->getFullName() << ".\n"
                     << endl;
                users[i]->login();
                return "Student";
            }
        }
        cout << "Invalid Email or Password! Please try again.\n"
             << endl;
        return "Invalid";
    }
    //---------------------------------------------------------------
    void logout(Student *u, Admin *a)
    {
        if (a != NULL)
        {
            cout << "[Status] Logging out . ";
            Sleep(1500);
            cout << ". ";
            Sleep(1500);
            cout << ". ";
            Sleep(1500);
            cout << ". ";
            cout << "[STATUS] Admin Logged Out Succesfully !\n"
                 << endl;
            a->logout();
        }
        if (users.size() != 0)
        {
            for (size_t i = 0; i < users.size(); i++)
            {
                if (users[i]->getId() == u->getId() && users[i]->getPassword() == u->getPassword())
                {
                    cout << "[Status] Logging out . ";
                    Sleep(1500);
                    cout << ". ";
                    Sleep(1500);
                    cout << ". ";
                    Sleep(1500);
                    cout << ". ";
                    cout << "Logout Successful!."
                         << endl;
                    users[i]->login();
                }
            }
        }
    }
    //-----------------------------------------------
    void addVehicle()
    {
        string type, busId, vanId;
        cout << "--------------( Vehicle Details )--------------" << endl;
        cout << "Enter Type of Vehicle (bus | van) : ";
        cin >> type;
        type = toLowerString(type);
        while (cin.fail() || (type != "bus" && type != "van"))
        {
            cout << "Invalid input! Please enter 'bus' or 'van': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> type;
            type = toLowerString(type);
        }
        if (type == "bus")
        {
            do
            {
                cout << "Enter Bus Id (eg B01) : ";
                cin >> busId;
                if (isBusIdDup(busId))
                {
                    cout << "Id already exisit! (Try another)" << endl;
                }
            } while (isBusIdDup(busId));
            Bus *ptr = new Bus();
            ptr->AddInfo(busId);
            Buses.push_back(ptr);
            cout << "Bus successfully added!" << endl;
        }
        else if (type == "van")
        {
            do
            {
                cout << "Enter Van Id (eg B01) : ";
                cin >> vanId;
                if (isVanIdDup(vanId))
                {
                    cout << "Id already exisit! (Try another)" << endl;
                }
            } while (isVanIdDup(vanId));
            Van *ptr = new Van();
            ptr->AddInfo(vanId);
            Vans.push_back(ptr);
            cout << "Van successfully added!" << endl;
        }
    }
    //---------------------------------
    bool isRouoteIdDup(string rId)
    {
        if (routes.size() != 0)
        {
            for (size_t i = 0; i < routes.size(); i++)
            {
                if (routes[i]->getRouteId() == rId)
                {
                    return true;
                }
            }
            return false;
        }
    }
    //-----------------------------

    void addPass(TransportationPass *p)
    {
        if (p == NULL)
        {
            cout << "Invalid Pass!" << endl;
            return;
        }

        passes.push_back(p);

        cout << "[STATUS] Transport Pass Added Successfully!" << endl;
    }
    void ViewAllRoute(){
        cout<<"---------------( Routes )---------------"<<endl;
        if(routes.size() == 0){cout<<" No Route Availible Yet . "<<endl;return;}
        for(size_t i=0;i<routes.size();i++){
            cout<<"========( Route No "<<i+1 <<" )==============="<<endl;
            routes[i]->diplayRoute();
            cout<<endl;
        }

    }
    //-------------------------------------------
    void applyTransport(Student *stud)
    {
        int routeNo;
        cout << "============== ( Apply Transportaion ) ==============" << endl;
        ViewAllRoute();
        cout<<"Enter Route Number To Apply : " ;
        cin>>routeNo;
        while (cin.fail() || routeNo < 1 || routeNo > routes.size()) {
        cout << "Invalid choice! Please enter a number between 1 to "<<routes.size()<<":\nEnter Route Number To Apply : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> routeNo;
        }
        if(routes[routeNo-1]->getAssignedBus() == NULL && routes[routeNo-1]->getAssignedVan() == NULL){
            cout<<"[Error] No Vehicle Assigned To Route | Id :"<<routes[routeNo-1]->getRouteId()<<" |  Yet  ."<<endl;
        }
        /*string billId;
      float monthlyFee;
      float fine;
      bool paidStatus;
      */
        Bill* bptr;
        if(routes[routeNo-1]->getAssignedBus() != NULL){
            if(routes[routeNo-1]->getAssignedBus()->checkAvailability()){
                routes[routeNo-1]->getAssignedBus()->occuppiedSeat();
                bptr=new Bill(stud->getId(),routes[routeNo-1]->getAssignedBus()->Fee(),0.0,false);
            }
        }else   if(routes[routeNo-1]->getAssignedVan() != NULL){
            if(routes[routeNo-1]->getAssignedVan()->checkAvailability()){
                routes[routeNo-1]->getAssignedVan()->occuppiedSeat();
                bptr=new Bill(stud->getId(),routes[routeNo-1]->getAssignedVan()->Fee(),0.0,false);
            }
        }
        TransportationPass* ptr=new TransportationPass((stud->getId()),stud,(routes[routeNo-1]),"pending",bptr);
        addPass(ptr);
    }
    //---------------
    Student* searchStudent(string b){
        if (users.empty()) {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for(size_t i=0;i<users.size();i++){
            if(users[i]->getId()==b){return users[i];}
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
     }
    //--------------------------
    Bus* searchBus(string b){
          if (Buses.empty()) {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for(size_t i=0;i<Buses.size();i++){
            if(Buses[i]->getId()==b){return Buses[i];}
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }
    //------------------------------------------
        Van* searchVans(string b){
          if (Vans.empty()) {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for(size_t i=0;i<Vans.size();i++){
            if(Vans[i]->getId()==b){return Vans[i];}
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
        }
    //----------------------------------------------------
     Route* searchRoute(string b){
          if (routes.empty()) {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for(size_t i=0;i<routes.size();i++){
            if(routes[i]->getRouteId()==b){return routes[i];}
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
        }
    //----------------------------------------
    void addRoute()
    {
        string rId;
        do
        {
            cout << "Enter Route Id (eg R01) : ";
            cin >> rId;
            if (isBusIdDup(rId))
            {
                cout << "Id already exisit! (Try another)" << endl;
            }
        } while (isRouoteIdDup(rId));
        Route *ptr = new Route();
        ptr->addinfo(rId);
        routes.push_back(ptr);
        cout << "Route successfully added!" << endl;
    }
    //--------------------------------------

    ~Manager()
    {
        delete admin;
        for (size_t i = 0; i < users.size(); i++)
        {
            delete users[i];
        }
        for (size_t i = 0; i < Vans.size(); i++)
        {
            delete Vans[i];
        }
        for (size_t i = 0; i < Buses.size(); i++)
        {
            delete Buses[i];
        }
        for (size_t i = 0; i < routes.size(); i++)
        {
            delete routes[i];
        }
        for (size_t i = 0; i < passes.size(); i++)
        {
            delete passes[i];
        }
    }
};
#endif