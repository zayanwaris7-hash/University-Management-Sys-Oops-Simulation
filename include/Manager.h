#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <fstream>
#include <array>
#include <cctype>
#include <windows.h>
#include "Admin.h"
#include "Student.h"
#include "Route.h"
#include "Bus.h"
#include "Van.h"
#include "TransportationPass.h"
using namespace std;
class Manager{
    protected:
    Admin *admin;
    vector<Student *> users;
    vector<Van *> Vans;
    vector<Bus *> Buses;
    vector<Route *> routes;
    vector<TransportationPass *> passes;

public:
    
    Manager() : admin(NULL), users(), Vans(), Buses(), routes(), passes() {
    }
    Manager(Admin *a) : admin(a), users(), Vans(), Buses(), routes(), passes() {
    }

   
    //------------------------------------
    
    void saveUser()
    {
        ofstream file("users.txt");
        if (!file.is_open())
            return;
        if (!users.empty())
        {
            for (size_t i = 0; i < users.size(); i++)
            {
                file << users[i]->getId() << " " << users[i]->getPassword() << " " << users[i]->getFullName() << " " << "false" <<" "<< users[i]->getregistrationNumber() <<" "<<users[i]->getPassId()<< "\n";
            }
            file.close();
        }
        else
        {
            cout << "[Error] Nothing To Save..." << endl;
        }
    }

    void saveRoutes()
    {
        ofstream file("route.txt");
        if (!file.is_open())
            return;
        if(!routes.empty()){
        for (size_t i = 0; i < routes.size(); i++)
        {
            file << routes[i]->getRouteId() << " " << routes[i]->getstartPoint() << " " << routes[i]->getendPoint() << " " << routes[i]->calculateDistance() << " " << routes[i]->getbusId() << " " << routes[i]->getvanId() << "\n";
        }
        file.close();
       }else{
         cout << "[Error] Nothing To Save..." << endl;
       }
    }
  
    void saveBus(){
         ofstream file("bus.txt");
        if (!file.is_open())
            return;
        if(!Buses.empty()){
        for (size_t i = 0; i < Buses.size(); i++)
        {
            file <<Buses[i]->getId() << " " << Buses[i]->getVehicleNumber() << " " << Buses[i]->getTotalSeat() << " " << Buses[i]->getOccupiedSeat() << " " << Buses[i]->getassigneRoute() << " " << Buses[i]->checkAvailability() <<" "<<Buses[i]->getfee()<<" "<< Buses[i]->wificheck()<< "\n";
        }
        file.close();
       }else{
         cout << "[Error] Nothing To Save..." << endl;
       }
    }
    void saveVans(){
         ofstream file("vans.txt");
        if (!file.is_open())
            return;
        if(!Vans.empty()){
        for (size_t i = 0; i < Vans.size(); i++)
        {
            file <<Vans[i]->getId() << " " << Vans[i]->getVehicleNumber() << " " << Vans[i]->getTotalSeat() << " " << Vans[i]->getOccupiedSeat() << " " << Vans[i]->getassigneRoute() << " " << Vans[i]->checkAvailability() <<" "<<Vans[i]->getfee()<<" "<< Vans[i]->checkisAirCondAvailable()<< "\n";
        }
        file.close();
       }else{
         cout << "[Error] Nothing To Save..." << endl;
       }
    }
    
    void savePasses(){
        ofstream file("pases.txt");
        if (!file.is_open())
            return;
        if(!passes.empty()){
        for (size_t i = 0; i < passes.size(); i++)
        {
           file<<passes[i]->getPassId()<<" "<<passes[i]->getStudId()<<" "<<passes[i]->getRouteId()<<" "<<passes[i]->getstatus()<<" "<<passes[i]->getBillId()<<" "<<passes[i]->getMontlyFees()<<" "<<passes[i]->getFine()<<" "<<passes[i]->getPStatus()<<"\n";
        }
        file.close();
       }else{
         cout << "[Error] Nothing To Save..." << endl;
       }
    }
    void saveAll(){
       saveUser();
       saveRoutes();
       saveBus();
       saveVans();
       savePasses();
    }
    //--------------------------------------------
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
    //----------------------------------------------
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
        string email, password, fullName,fname,lname, regNo, ss,passId;
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
        cout << "Enter Your first name : ";
        cin>>fname;
        cout << endl;
        cout << "Enter Your first name : ";
        cin>>lname;
        cout << endl;
        fullName=fname+lname;
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
        passId=email;
        Student *studPtr = new Student(email, password, fullName, false, regNo,passId);
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
        for (size_t i = 0; i < users.size(); i++){
            if (users[i]->getId() == email && users[i]->getPassword() == password)
            {
                cout << "Login Successful! Welcome, " << users[i]->getFullName() << ".\n"
                     << endl;
                users[i]->login();
                return "Student";
            }
        }
        cout << "Invalid Email or Password! Please try again."<< endl;
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
        if (!users.empty())
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
                    users[i]->logout();
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
    
    void delVehicle(){
         string type, busId, vanId;
        cout << "--------------( Delete Vehicle Details )--------------" << endl;
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
           
            cout << "Enter Bus Id (eg B01) : ";
            cin >> busId;
               
            Bus *ptr = searchBus(busId);
               if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<busId<<" | "<<endl;
                return;
            }
            Buses.erase(remove(Buses.begin(), Buses.end(), ptr), Buses.end());
            cout << "Bus | id : "<<busId<<" | successfully Deleted!" << endl;
        }
        else if (type == "van")
        {
            cout << "Enter Van Id (eg B01) : ";
            cin >> vanId;
            Van *ptr = searchVans(vanId);
            if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<vanId<<" | "<<endl;
                return;
            }
             Vans.erase(remove(Vans.begin(), Vans.end(), ptr), Vans.end());
           cout << "Van | id : "<<vanId<<" | successfully Deleted!" << endl;
        }
    }
    //---------------------------------
    void updateVehicleDetail(){
          string type, busId, vanId;
        cout << "--------------( Update Vehicle Details )--------------" << endl;
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
            
            cout << "Enter Bus Id (eg B01) : ";
            cin >> busId;
            Bus *ptr = searchBus(busId);
            if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<busId<<" | "<<endl;
                return;
            }
            ptr->AddInfo(busId);
            cout << "Bus successfully updated !" << endl;
        }
        else if (type == "van")
        {
           
            cout << "Enter Van Id (eg B01) : ";
            cin >> vanId;
            Van *ptr = searchVans(vanId);
            if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<vanId<<" | "<<endl;
                return;
            }
            ptr->AddInfo(vanId);
            cout << "Van successfully updated!" << endl;
        }
    }

    //-------------------------------
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
        }
        return false;
    }
    //-----------------------------
    void loadUsers() {
        ifstream file("users.txt");
        if (!file.is_open()) {
            cout << "[Error] Could not open users.txt for loading." << endl;
            return;
        }
        for (size_t i=0;i<users.size();i++) {
            delete users[i];
        }
        users.clear();

        string id, password, fullName, statusStr, regNo, passId;
        while (file >> id >> password >> fullName >> statusStr >> regNo >> passId) {
            bool loginStatus = (statusStr == "true");
            Student *studPtr = new Student(id, password, fullName, loginStatus, regNo, passId);
            users.push_back(studPtr);
        }
        file.close();
        cout << "[STATUS] Users Loaded Successfully! Count: " << users.size() << endl;
    }

    void loadBus(){
        ifstream file("bus.txt");
        if (!file.is_open())
        {
            cout << "[Error] Could not open bus.txt for loading." << endl;
            return;
        }
        for (size_t i = 0; i < Buses.size(); i++)
        {
            delete Buses[i];
        }
        Buses.clear();
        string vI,vN,aR,iW,iA;
        int c,oC;
        float f;
        while(file>>vI>>vN>>c>>oC>>aR>>iA>>f>>iW){
            bool wifistatus=(iW =="true");
            bool AvailStatus=(iA =="true");
            Bus* bptr=new Bus(vI,vN,c,oC,aR,AvailStatus,f,wifistatus);
            Buses.push_back(bptr);
        }
    }
    
    void loadVan(){
        ifstream file("vans.txt");
        if (!file.is_open())
        {
            cout << "[Error] Could not open van.txt for loading." << endl;
            return;
        }
        for (size_t i = 0; i < Vans.size(); i++)
        {
            delete Vans[i];
        }
        Vans.clear();
        string vI,vN,aR,iW,iA;
        int c,oC;
        float f;
        while(file>>vI>>vN>>c>>oC>>aR>>iA>>f>>iW){
            bool wifistatus=(iW =="true");
            bool AvailStatus=(iA =="true");
            Van* bptr=new Van(vI,vN,c,oC,aR,AvailStatus,f,wifistatus);
            Vans.push_back(bptr);
        }
    }
   
    void loadRoute(){
      string rI,eP,sP,bId,vId;
      double d;
       ifstream file("route.txt");
        if (!file.is_open())
        {
            cout << "[Error] Could not open route.txt for loading." << endl;
            return;
        }
        for (size_t i = 0; i < routes.size(); i++)
        {
            delete routes[i];
        }
        routes.clear();
        while(file>>rI>>sP>>eP>>d>>bId>>vId){
            Bus* bptr= searchBus(bId);
            Van* vptr= searchVans(vId);
            Route* rptr=new Route(rI,sP,eP,d,bptr,vptr);
            routes.push_back(rptr);
        }

    }

    void loadPasses(){
        ifstream file("pases.txt");
        if (!file.is_open())
        {
            cout << "[Error] Could not open Pasess.txt for loading." << endl;
            return;
        }
        for (size_t i = 0; i < passes.size(); i++)
        {
            delete passes[i];
        }
        passes.clear();
        string passId,sId,rId,status,bId,paidStatus;
        float mF,fine;
        while(file>>passId>>sId>>rId>>status>>bId>>mF>>fine>>paidStatus){
            Student* sptr=searchStudent(sId);
            Route* rptr=searchRoute(rId);
            bool p=(paidStatus =="true");
            Bill* bptr=new Bill(bId,mF,fine,p);
            TransportationPass* ptr= new TransportationPass(passId,sptr,rptr,status,bptr);
            passes.push_back(ptr);
        }

    }
    TransportationPass* searchPass(string b){
         if (passes.empty())
        {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for (size_t i = 0; i < passes.size(); i++)
        {
            if (passes[i]->getPassId() == b)
            {
                return passes[i];
            }
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }

    //--------------------------------
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
    int ViewAllRoute()
    {
        cout << "---------------( Routes )---------------" << endl;
        if (routes.size() == 0)
        {
            cout << " No Route Availible Yet . " << endl;
            return -1;
        }
        for (size_t i = 0; i < routes.size(); i++)
        {
            cout << "========( Route No " << i + 1 << " )===============" << endl;
            routes[i]->diplayRoute();
            cout << endl;
        }
        return 2;
    }
    
    void assignVehicleToRoute(){
        string rId,vId,type;
        int cond=ViewAllRoute();
        if(cond == 2 ){
            cout << "--------------( Route ID )--------------" << endl;
            cout<<"Enter Route Id : ";
            cin>>rId;
            Route* ptr1=searchRoute(rId);
            if(ptr1==NULL){
                cout<<"[STATUS] No Such Route Found with | id : "<<rId<<" | "<<endl;
                return;
            }
            cout << "--------------( Vehicle ID )--------------" << endl;
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
            
            cout << "Enter Bus Id (eg B01) : ";
            cin >> vId;
            Bus *ptr = searchBus(vId);
            if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<vId<<" | "<<endl;
                return;
            }
            ptr1->assignBus(ptr);
            ptr->setAssignroute(ptr1->getRouteId());
            cout << "Bus | id : "<<ptr->getId()<<"successfully Assigned to Route | id : "<<ptr1->getRouteId()<<" !" << endl;
        }
        else if (type == "van")
        {
            
            cout << "Enter Van Id (eg B01) : ";
            cin >> vId;
            Van *ptr = searchVans(vId);
            if(ptr==NULL){
                cout<<"[STATUS] No Such Vehicle Found with | id : "<<vId<<" | "<<endl;
                return;
            }
            ptr1->assignVan(ptr);
            ptr->setAssignroute(ptr1->getRouteId());
            cout << "Van | id : "<<ptr->getId()<<"successfully Assigned to Route | id : "<<ptr1->getRouteId()<<" !" << endl;
        }

        }
    }
    //-------------------------------------------
    void applyTransport(Student *stud)
    {
        int routeNo;
        cout << "============== ( Apply Transportaion ) ==============" << endl;
        ViewAllRoute();
        cout << "Enter Route Number To Apply : ";
        cin >> routeNo;
        while (cin.fail() || routeNo < 1 || static_cast<size_t>(routeNo) > routes.size())
        {
            cout << "Invalid choice! Please enter a number between 1 to " << routes.size() << ":\nEnter Route Number To Apply : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> routeNo;
        }
        if (routes[routeNo - 1]->getAssignedBus() == NULL && routes[routeNo - 1]->getAssignedVan() == NULL)
        {
            cout << "[Error] No Vehicle Assigned To Route | Id :" << routes[routeNo - 1]->getRouteId() << " |  Yet  ." << endl;
        }
        /*string billId;
      float monthlyFee;
      float fine;
      bool paidStatus;
      */
        Bill *bptr;
        if (routes[routeNo - 1]->getAssignedBus() != NULL)
        {
            if (routes[routeNo - 1]->getAssignedBus()->checkAvailability())
            {
                routes[routeNo - 1]->getAssignedBus()->occuppiedSeat();
                bptr = new Bill(stud->getId(), routes[routeNo - 1]->getAssignedBus()->Fee(), 0.0, false);
            }
        }
        else if (routes[routeNo - 1]->getAssignedVan() != NULL)
        {
            if (routes[routeNo - 1]->getAssignedVan()->checkAvailability())
            {
                routes[routeNo - 1]->getAssignedVan()->occuppiedSeat();
                bptr = new Bill(stud->getId(), routes[routeNo - 1]->getAssignedVan()->Fee(), 0.0, false);
            }
        }
        TransportationPass *ptr = new TransportationPass((stud->getId()), stud, (routes[routeNo - 1]), "pending", bptr);
        addPass(ptr);
    }
    //---------------
    Student *searchStudent(string b)
    {
        if (users.empty())
        {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for (size_t i = 0; i < users.size(); i++)
        {
            if (users[i]->getId() == b)
            {
                return users[i];
            }
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }
    //--------------------------
    Bus *searchBus(string b)
    {
        if (Buses.empty())
        {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for (size_t i = 0; i < Buses.size(); i++)
        {
            if (Buses[i]->getId() == b)
            {
                return Buses[i];
            }
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }
    //------------------------------------------
    Van *searchVans(string b)
    {
        if (Vans.empty())
        {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for (size_t i = 0; i < Vans.size(); i++)
        {
            if (Vans[i]->getId() == b)
            {
                return Vans[i];
            }
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }
    //----------------------------------------------------
    Route *searchRoute(string b)
    {
        if (routes.empty())
        {
            cout << "[NOTICE] No students registered in the database yet." << endl;
            return NULL;
        }
        for (size_t i = 0; i < routes.size(); i++)
        {
            if (routes[i]->getRouteId() == b)
            {
                return routes[i];
            }
        }
        cout << "[NOTICE] No students exist with this id." << endl;
        return NULL;
    }
    //----------------------------------------
      void loadAll(){
        loadUsers();
        loadBus();
        loadVan();
        loadRoute();
        loadPasses();
      }
    //----------------------------
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
    void veiwAll(){
         cout << "---------------( Students )---------------" << endl;
        if (users.size() == 0)
        {
            cout << " No Student  Yet . " << endl;
        }
        for (size_t i = 0; i < users.size(); i++)
        {
            cout << "========( Student No " << i + 1 << " )===============" << endl;
            users[i]->display();
            cout << endl;
        }
        //----
            cout << "---------------( Routes )---------------" << endl;
        if (routes.size() == 0)
        {
            cout << " No Route Availible Yet . " << endl;
        }
        for (size_t i = 0; i < routes.size(); i++)
        {
            cout << "========( Route No " << i + 1 << " )===============" << endl;
            routes[i]->diplayRoute();
            cout << endl;
        }
        //----
            cout << "---------------( Buses )---------------" << endl;
        if (Buses.size() == 0)
        {
            cout << " No Buses  Yet . " << endl;
        }
        for (size_t i = 0; i < Buses.size(); i++)
        {
            cout << "========( Bus No " << i + 1 << " )===============" << endl;
            Buses[i]->displayVehicle();
            cout << endl;
        }
        //----
            cout << "---------------( Vans )---------------" << endl;
        if   (Vans.size() == 0)
        {
            cout << " No  Vans  Yet . " << endl;
        }
        for (size_t i = 0; i <  Vans.size(); i++)
        {
            cout << "========( Van No " << i + 1 << " )===============" << endl;
          Vans[i]->displayVehicle();
            cout << endl;
        }
        //----
            cout << "---------------( Passes )---------------" << endl;
        if   (passes.size() == 0)
        {
            cout << " No  Passes  Yet . " << endl;
        }
        for (size_t i = 0; i <  passes.size(); i++)
        {
            cout << "========( pass No " << i + 1 << " )===============" << endl;
          passes[i]->displayPass();
            cout << endl;
        }
    }
    void ViewPendingStud(){
        
            cout << "---------------( Pending Passes )---------------" << endl;
        if   (passes.empty())
        {
            cout << " No Pending  Passes  Yet . " << endl;
        }
        for (size_t i = 0; i <  passes.size(); i++)
        {   
            if(passes[i]->getstatus()=="pending"){
                cout << "========( pass No " << i + 1 << " )===============" << endl;
              passes[i]->displayPass();
                cout << endl;
            }
        }
        
    }
    void passAcceptionOrRej() {
    if (passes.empty()) {
        cout << "[NOTICE] No transportation passes available to review." << endl;
        return;
    }
    int choice;
    ViewPendingStud();
    while (true) {
        cout << "Enter Pass No to Move Forward (0 to go back): ";
        cin >> choice;
        if (cin.fail()) {
            cout << "[Error] Invalid input type. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice < 0 || choice > (int)passes.size()) {
            cout << "[Error] Number out of range! Try a number between 0 and " << passes.size() << "." << endl;
            continue;
        }
        break;
    }
    if (choice == 0) {
        cout << "[STATUS] Returning to previous menu..." << endl;
        return;
    }
    TransportationPass* selectedPass = passes[choice - 1];
    int action;
    cout << "\nSelected Pass Details:" << endl;
    selectedPass->displayPass();
    while (true) {
        cout << "\n---[ Action Menu ]---" << endl;
        cout << "1. Accept / Approve Pass" << endl;
        cout << "2. Reject Pass" << endl;
        cout << "3. Cancel (Keep Pending)" << endl;
        cout << "Select an option (1-3): ";
        cin >> action;
        if (cin.fail() || action < 1 || action > 3) {
            cout << "[Error] Invalid selection. Choose 1, 2, or 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    if (action == 1) {
        selectedPass->approvePass();
        cout << "[STATUS] Pass ID: " << selectedPass->getPassId() << " has been APPROVED." << endl;
    } else if (action == 2) {
        selectedPass->rejectPass();
        cout << "[STATUS] Pass ID: " << selectedPass->getPassId() << " has been REJECTED." << endl;
    } else {
        cout << "[STATUS] Operation canceled. Pass remains pending." << endl;
    }
}
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