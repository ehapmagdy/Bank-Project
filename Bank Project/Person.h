#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Validation.h"

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person(int id, const string& name, const string& password)
        : id(id) {
        setName(name);
        setPassword(password);
    }

    virtual ~Person() = default;

    // ================= SETTERS =================

    void setName(const string& name) {
        if (Validation::validateName(name))
            this->name = name;
        else
            cout << "Invalid Name!\n";
    }

    void setPassword(const string& password) {
        if (Validation::validatePassword(password))
            this->password = password;
        else
           cout << "Invalid Password!\n";
    }

    // ================= GETTERS =================

    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }

    // ================= DISPLAY =================

    virtual void display() {
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Password: " << password << "\n";
    }
};