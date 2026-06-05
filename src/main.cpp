#include <iostream>
#include <string>
#include <limits>
#include<fstream>
#include "Manager.h"
#include"Admin.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Admin* a=new Admin("Admin@123","password123","Zuzzy",false,"Admin");
    Manager manager(a);
    manager.loadAll();

    int mainChoice = 0;
    
    while (mainChoice != 3) {
        cout << "\n==================================================\n";
        cout << "  UNIVERSITY TRANSPORT MANAGEMENT & BILLING SYSTEM\n";
        cout << "==================================================\n";
        cout << "1. Register Student\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "--------------------------------------------------\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> mainChoice)) {
            cout << "[Error] Invalid input type. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (mainChoice) {
            case 1: {
                manager.registerStudent();
                break;
            }
            case 2: {
                string email, password;
                cout << "\n---[ Login Screen ]---\n";
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Password: ";
                cin >> password;

                string userRole = manager.login(email, password);

                if (userRole == "Admin") {
                    int adminChoice = 0;
                    while (adminChoice != 9) {
                        cout << "\n==========( Admin Menu )==========\n";
                        cout << "1. Add Vehicle\n";
                        cout << "2. Edit Vehicle Details\n";
                        cout << "3. Remove Vehicle\n";
                        cout << "4. Add Route\n";
                        cout << "5. Assign Vehicle to Route\n";
                        cout << "6. View Pending Applications\n";
                        cout << "7. Approve / Reject Requests\n";
                        cout << "8. View Students,Routes,Buses,Vans,Passes List\n";
                        cout << "9. Logout\n";
                        cout << "----------------------------------\n";
                        cout << "Enter your choice: ";
                        
                        if (!(cin >> adminChoice)) {
                            cout << "[Error] Invalid input type.\n";
                            clearInputBuffer();
                            continue;
                        }

                        switch (adminChoice) {
                            case 1: manager.addVehicle(); break;
                            case 2: manager.updateVehicleDetail(); break;
                            case 3: manager.delVehicle(); break;
                            case 4: manager.addRoute(); break;
                            case 5: manager.assignVehicleToRoute(); break;
                            case 6: manager.ViewPendingStud() ; break;
                            case 7: manager.passAcceptionOrRej(); break;
                            case 8: manager.veiwAll(); break;
                            case 9:
                                manager.logout(NULL, new Admin());
                                break;
                            default:
                                cout << "Invalid choice! Range is 1-9.\n";
                        }
                    }
                } 
                else if (userRole == "Student") {
                    // Resolve pointer to the logged-in student entity
                    Student* activeStudent = manager.searchStudent(email);
                    if (!activeStudent) {
                        cout << "[Critical Error] Session resolving failed.\n";
                        break;
                    }

                    int studentChoice = 0;
                    while (studentChoice != 5) {
                        cout << "\n==========( Student Menu )==========\n";
                        cout << "1. View System Routes\n";
                        cout << "2. Apply for Transport Pass\n";
                        cout << "3. View My Registration & Invoices\n";
                        cout << "4. Cancel Active Registration\n";
                        cout << "5. Logout\n";
                        cout << "------------------------------------\n";
                        cout << "Enter your choice: ";

                        if (!(cin >> studentChoice)) {
                            cout << "[Error] Invalid input type.\n";
                            clearInputBuffer();
                            continue;
                        }

                        switch (studentChoice) {
                            case 1: manager.ViewAllRoute(); break;
                            case 2: manager.applyTransport(activeStudent); break;
                            case 3: 
                                cout << "\n---[ My Registration Details ]---\n";
                                cout << "ID: " << activeStudent->getId() << "\n";
                                cout << "Name: " << activeStudent->getFullName() << "\n";
                                cout << "Reg No: " << activeStudent->getregistrationNumber() << "\n";
                                if (activeStudent->getPassId() != "0" && activeStudent->getPassId() != "") {
                                    cout << "Active Transport Pass Associated! ID: " << activeStudent->getPassId() << "\n";
                                } else {
                                    cout << "Status: No active transportation passes approved.\n";
                                }
                                break;
                            case 4: 
                                cout << "[Notice] Resetting transport application constraints for this student pointer.\n";
                                break;
                            case 5:
                                manager.logout(activeStudent, NULL); // Safely isolate student states
                                break;
                            default:
                                cout << "Invalid choice! Range is 1-5.\n";
                        }
                    }
                }
                break;
            }
            case 3: {
                cout << "\n[STATUS] Terminating system execution. Saving dynamic records back to standard disk file architecture...\n";
                manager.saveAll();
                break;
            }
            default:
                cout << "Invalid main choice! Enter 1, 2, or 3.\n";
        }
    }

    return 0;
} 