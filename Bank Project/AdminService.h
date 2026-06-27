#pragma once
#include "Admin.h"
#include "FileManager.h"
#include <vector>
using namespace std;

class AdminService {
private:
    Admin admin;

public:
    AdminService(Admin a) : admin(a) {}

    // ================= Clients =================

    void addClient(Client c) {
        FileManager::addClient(c);
    }

    Client searchClient(int clientId) {
        for (Client c : FileManager::getAllClients()) {
            if (c.getId() == clientId)
                return c;
        }
        cout << "Client not found\n";
        return Client(-1, "Unknown", "00000000", 1500);
    }

    void listClients() {
        for (Client c : FileManager::getAllClients())
            c.display();
    }

    void editClient(int clientId, Client newClient) {
        vector<Client> clients = FileManager::getAllClients();
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == clientId) {
                clients[i] = newClient;
                break;
            }
        }
        FileManager::removeAllClients();
        for (Client c : clients)
            FileManager::addClient(c);
    }

    void deleteClient(int clientId) {
        vector<Client> clients = FileManager::getAllClients();
        FileManager::removeAllClients();
        for (Client c : clients) {
            if (c.getId() != clientId)
                FileManager::addClient(c);
        }
    }

    // ================= Employees =================

    void addEmployee(Employee e) {
        FileManager::addEmployee(e);
    }

    Employee searchEmployee(int id) {
        for (Employee e : FileManager::getAllEmployees()) {
            if (e.getId() == id)
                return e;
        }
        cout << "Employee not found\n";
        return Employee(-1, "Unknown", "00000000", 5000);
    }

    void listEmployees() {
        for (Employee e : FileManager::getAllEmployees())
            e.display();
    }

    void editEmployee(int id, Employee newEmp) {
        vector<Employee> emps = FileManager::getAllEmployees();
        for (int i = 0; i < emps.size(); i++) {
            if (emps[i].getId() == id) {
                emps[i] = newEmp;
                break;
            }
        }
        FileManager::removeAllEmployees();
        for (Employee e : emps)
            FileManager::addEmployee(e);
    }

    void deleteEmployee(int id) {
        vector<Employee> emps = FileManager::getAllEmployees();
        FileManager::removeAllEmployees();
        for (Employee e : emps) {
            if (e.getId() != id)
                FileManager::addEmployee(e);
        }
    }
};