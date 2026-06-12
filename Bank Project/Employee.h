#pragma once
#include "Person.h"

class Employee : public Person {
protected:
    double salary;

public:
    Employee(int id, const string& name,
        const string& password, double salary)
        : Person(id, name, password) {
        setSalary(salary);
    }

    // ================= SETTERS =================

    void setSalary(double salary) {
        if (salary >= 5000)
            this->salary = salary;
        else
            cout << "Minimum salary is 5000!\n";
    }

    // ================= GETTERS =================

    double getSalary() const { return salary; }

    // ================= DISPLAY =================

    void display() {
        cout << "\n===== EMPLOYEE INFO =====\n";
        Person::display();
        cout << "Salary: " << salary << "\n";
    }
};