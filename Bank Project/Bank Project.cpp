#include <iostream>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "DataSourceInterface.h"
#include "FileManager.h"
#include "AdminService.h"
#include "EmployeeService.h"

using namespace std;

int main() {
    cout << "==================================================\n";
    cout << "          STARTING BANK SYSTEM TESTING            \n";
    cout << "==================================================\n";

    
    cout << "\n>>> Loading existing data from files...\n";
    vector<Client> allClients = FileManager::getAllClients();
    vector<Employee> allEmployees = FileManager::getAllEmployees();
    vector<Admin> allAdmins = FileManager::getAllAdmins();

    cout << "Total Clients in file: " << allClients.size() << "\n";
    cout << "Total Employees in file: " << allEmployees.size() << "\n";
    cout << "Total Admins in file: " << allAdmins.size() << "\n";


    
    cout << "\n>>> Testing Admin Service...\n";
    if (!allAdmins.empty()) {
        Admin currentAdmin = allAdmins[0];
        currentAdmin.display(); 

        AdminService adminService(currentAdmin);

        cout << "\n[Admin action] Adding a new client...\n";
        Client newClient(9, "Captin Egypt", "Cap123456", 5000);
        adminService.addClient(newClient);
        cout << "Client added successfully!\n";

        cout << "\n[Admin action] Listing all clients:\n";
        adminService.listClients();

        
        cout << "\n[Admin action] Searching for Employee with ID 3...\n";
        Employee emp = adminService.searchEmployee(3);
        emp.display();
    }
    else {
        cout << "No admins found in Admins.txt to test AdminService.\n";
    }


   
    cout << "\n>>> Testing Employee Service...\n";
    if (!allEmployees.empty()) {
        Employee currentEmp = allEmployees[0];
        EmployeeService empService(currentEmp);

        cout << "\n[Employee action] Searching for Client with ID 9...\n";
        Client cl = empService.searchClient(99);
        cl.display();
    }
    else {
        cout << "No employees found in Employees.txt to test EmployeeService.\n";
    }


   
    cout << "\n>>> Testing Financial Operations...\n";
    allClients = FileManager::getAllClients();

    if (allClients.size() >= 2) {
        Client& client1 = allClients[0]; 
        Client& client2 = allClients[1]; 

        cout << "\nBefore Operations:\n";
        client1.display();
        client2.display();

        cout << "\nDoing Deposit for " << client1.getName() << "...\n";
        client1.deposit(1500);

        cout << "\nDoing Withdrawal for " << client1.getName() << "...\n";
        client1.withdraw(500);

        cout << "\nTransferring 1000 from " << client1.getName() << " to " << client2.getName() << "...\n";
        client1.transferTo(1000, client2);

        cout << "\nAfter Operations:\n";
        client1.display();
        client2.display();
    }
    else {
        cout << "Need at least 2 clients in the file to test financial operations.\n";
    }

    cout << "\n==================================================\n";
    cout << "          TESTING COMPLETED SUCCESSFULLY          \n";
    cout << "==================================================\n";

    return 0;
}