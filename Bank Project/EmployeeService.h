#pragma once
#include "Employee.h"
#include "Client.h"
#include "FileManager.h"
#include <vector>
using namespace std;

class EmployeeService {
private:
    Employee employee;

public:
    EmployeeService(Employee emp) : employee(emp) {}

    void addClient(Client c) {
        FileManager::addClient(c);
    }

    Client searchClient(int clientId) {
        for (Client c : FileManager::getAllClients()) {
            if (c.getId() == clientId)
                return c;
        }
        cout << "Client not found\n";
        // لازم ترجع حاجة - لو مش لاقي return default
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
};