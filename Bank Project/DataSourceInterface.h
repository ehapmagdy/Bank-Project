#pragma once
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

    class DataSourceInterface
{
public:

    virtual void addClient(Client obj) = 0;
    virtual void addEmployee(Employee obj) = 0;
    virtual void addAdmin(Admin obj) = 0;

    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};

    
