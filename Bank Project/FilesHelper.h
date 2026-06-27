#pragma once
#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class FilesHelper {
public:
    static void saveLast(string fileName, int id) {
        ofstream file(fileName, ios::trunc);
        if (file.is_open()) {
            file << id;
            file.close();
        }
    }
    static int getLast(string fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c) {
        ofstream file("Clients.txt",ios::app);
        if (file.is_open()) {
            file.close();
        }
    }
    static void saveEmployee(Employee e) {
        ofstream file("Employees.txt",ios::app);
        if (file.is_open()) {
            file.close();
        }
    }
    static void saveAdmin(Admin a) {
        ofstream file("Admins.txt",ios::app);
        if (file.is_open()) {
            file.close();
        }
    }

    static vector<Client> getClients() {
        vector<Client> clients;
        ifstream file("Clients.txt");
        if (file.is_open()) {
            file.close();
        }
        return clients;
    }
    static vector<Employee> getEmployees() {
        vector<Employee> employees;
        ifstream file("Employees.txt");
        if (file.is_open()) {
            file.close();
        }
        return employees;
    }
    static vector<Admin> getAdmins() {
        vector<Admin> admins;
        ifstream file("Admins.txt");
        if (file.is_open()) {
            file.close();
        }
        return admins;
    }

    static void clearFile(string fileName) {
        ofstream file(fileName,ios::trunc);
        if (file.is_open()) {
            file.close();
        }
    }
};

#endif



