#pragma once
#include "Person.h"

class Client : public Person {
private:
    double balance;

public:
    Client(int id, const string& name,
        const string& password, double balance)
        : Person(id, name, password) {
        setBalance(balance);
    }

    // ================= SETTERS =================

    void setBalance(double balance) {
        if (balance >= 1500)
            this->balance = balance;
        else
            cout << "Minimum balance is 1500!\n";
    }

    // ================= GETTERS =================

    double getBalance() const { return balance; }

    // ================= FUNCTIONS =================

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << "\n";
        }
        else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << "\n";
        }
        else {
            std::cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            std::cout << "Transfer of " << amount
                << " to " << recipient.getName() << " successful.\n";
        }
        else {
            std::cout << "Transfer failed: insufficient balance or invalid amount.\n";
        }
    }

    void checkBalance() const {
        std::cout << "Current balance: " << balance << "\n";
    }

    // ================= DISPLAY =================

    void display() {
        std::cout << "\n===== CLIENT INFO =====\n";
        Person::display();
        std::cout << "Balance: " << balance << "\n";
    }
};
