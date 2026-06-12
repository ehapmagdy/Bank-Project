#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
    Admin(int id, const string& name,
        const string& password, double salary)
        : Employee(id, name, password, salary) {
    }

    void display() {
       cout << "\n===== ADMIN INFO =====\n";
        Person::display();
        cout << "Salary: " << salary << "\n";
    }
};