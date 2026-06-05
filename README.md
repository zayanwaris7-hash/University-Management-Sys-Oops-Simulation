# University Management System (OOP Simulation)

A comprehensive, console-based University Management System simulation written in C++. This project demonstrates advanced Object-Oriented Programming (OOP) architectures by simulating university workflows, user roles, and transport logistics.

---

## 🏗️ Project Structure

The project follows a clean header-and-source separation layout:

```text
University-Management-Sys-Oops-Simulation/
├── CMakeLists.txt          # Build configuration script
├── README.md               # Documentation
├── include/                # Header files (.h)
│   ├── Admin.h
│   ├── Bill.h
│   ├── Bus.h
│   ├── Manager.h
│   ├── Route.h
│   ├── Student.h
│   ├── TransportationPass.h
│   ├── User.h
│   └── Van.h
└── src/                    # Implementation files (.cpp)
    └── main.cpp            # Main simulation driver
```
---
## Core Architecture Components :

### User Hierarchy:
Base class User inherited by Admin, Manager, and Student to showcase polymorphism and encapsulation.

### Logistics & Fleet: 
Bus and Van inherit from a vehicle base structure to manage capacity, routing, and configurations.

### Operational Rules:
Classes like Route, Bill, and TransportationPass interact dynamically to process real-time passenger registrations.

---

## 🛠️ Requirements & Compilation :
Built and tested using CMake and MinGW / GCC (MSYS64).

Build Instructions
Bash
# 1. Create and enter a build directory
```text
mkdir build && cd build
```
# 2. Configure the project with CMake
```text
cmake ..
```
# 3. Compile the executable
```text
cmake --build .
```
# 4. Run the simulation
```text
./University-Management-Sys-Oops-Simulation.exe
```
---
## ⚠️ Key Engineering Challenges & Solutions : 
---
### 🔄 1. Resolving the Circular Dependency Loop (Solved)
#### The Problem: 
During development, a compilation deadlock occurred because files cross-included one another. For example, TransportationPass.h required the Student class definition, while Student.h was bound to properties inside TransportationPass.h. This caused the compiler to throw errors such as:
---
```Plaintext
error: 'Student' does not name a type
error: class 'TransportationPass' does not have any field named 'student'
The Solution Applied:
```

#### Forward Declarations: 
Removed tight #include "Student.h" lines from the top of dependent headers and replaced them with forward declarations (class Student;).

#### Implementation Postponement: 
Moved functions that access member variables/methods (like student->getId()) to the bottom of the header file as inline blocks, ensuring they are only parsed after all primary class layouts are registered.

### 🧹 2. Stream & Pointer Management Patches
#### Input Validation Hangups:
Fixed an infinite loop bug in AddInfo() where character array checking used flawed OR (||) operators instead of logical AND (&&) operators for loop termination.

Vector Type Mismatches: Corrected vector management cleanup queries where object data (*ptr) was mistakenly evaluated against lists of raw object pointers (std::vector<Bus*>).

Abstract Linker Failures: Fixed undefined reference to User::~User() errors by defining explicit, virtual destructors (virtual ~User() = default;) inside base classes.