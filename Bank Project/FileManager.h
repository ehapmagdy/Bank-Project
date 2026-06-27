#pragma once
#include <vector>
#include "DataSourceInterface.h"
#include "FilesHelper.h"


using namespace std;

class FileManager : public DataSourceInterface
{
public:
    static void addClient(Client obj)
    {
        FilesHelper::saveClient(obj);
    }

    static void addEmployee(Employee obj)
    {
        FilesHelper::saveEmployee(obj);
    }

    static void addAdmin(Admin obj)
    {
        FilesHelper::saveAdmin(obj);
    }

    static vector<Client> getAllClients()
    {
        return FilesHelper::getClients();
    }

    static vector<Employee> getAllEmployees()
    {
        return FilesHelper::getEmployees();
    }

    static vector<Admin> getAllAdmins()
    {
        return FilesHelper::getAdmins();
    }

    static void removeAllClients()
    {
        FilesHelper::clearFile("Clients.txt");
    }

    static void removeAllEmployees()
    {
        FilesHelper::clearFile("Employees.txt");
    }

    void removeAllAdmins()
    {
        FilesHelper::clearFile("Admins.txt");
    }
};

